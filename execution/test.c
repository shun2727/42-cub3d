
// struct probably looking like this

// typedef struct s_game
// {
//     char **map;

//     int map_width;
//     int map_height;

//     t_player player;
//     t_texture textures[4];

//     void *mlx;
//     void *win;
//     void *img;

// } t_game;


// settings
# define WIN_WIDTH 1000 // need to double check
# define WIN_HEIGHT 800 // need to double check
# define H_SCALE 0.2 // IF TOO SPIKY, CAN REDUCE BY (x2)
# define ANGLE 0.6

// (WIN_WIDTH / 2.5)
# define H_MOVE 400

// (WIN_HEIGHT / 4) IF ITS TOO WEIRD, DIVIDE BY 3 INSTEAD
# define V_MOVE 200 // if its too weird, divide by 3 instead

# define MAGNIFY_DEFAULT 2

// BETWEEN 1.5 to 3
# define MAGNIFY_SCALE 1.5

// hooks and colours
# define ESC_KEY		0xff1b
# define CLOSE			17
# define LINE_COLOUR 	0xFFFFFFFF
# define BG_COLOUR 		0x00000000

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*img_ptr;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
	char	*addrs;
}	t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	**map;
	int	**colored;
}	t_map;

typedef struct s_coor
{
	int		ori_x0;
	int		ori_y0;
	double	x1;
	double	y1;
	double	z1;
}	t_coor;

typedef struct s_vars
{
	t_map	map;
	t_img	img;
	t_coor	coord;
	void	*mlx;
	void	*win;
	float	magnify;
}	t_vars;


void	parse_arg(char **argv, int argc, t_vars *vars)
{
	int	fd;

	if (argc != 2)
		error_message_free("Usage:\n./fdf <map_name.fdf>\n", 1, vars);
	fd = open_file(argv[1], O_RDONLY, vars);
	if (!fd)
		error_message_free("Nothing in file to parse\n", 1, vars);
	vars->map.height = find_mapheight(argv, vars);
	parse_map(argv, vars);
	if (!vars)
	{
		free_vars(vars);
		exit(1);
	}
}

void	parse_map(char **argv, t_vars *vars)
{
	char	*line;
	int		i;
	int		fd;

	fd = open_file(argv[1], O_RDONLY, vars);
	vars->map.map = ft_calloc(sizeof(int *), vars->map.height);
	vars->map.colored = ft_calloc(sizeof(int *), vars->map.height);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		vars->map.map[i] = split_atoi(line, ' ', &vars->map.width);
		if (!(vars->map.map[i]))
			free_vars(vars);
		vars->map.colored[i++] = split_atoi_colour(line);
		if (!(vars->map.colored[i - 1]))
			free_vars(vars);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	find_mapheight(char **argv, t_vars *vars)
{
	char	*str;
	int		count;
	int		fd;

	fd = open_file(argv[1], O_RDONLY, vars);
	if (!fd)
		error_message("Nothing in file to parse\n", 1);
	count = 0;
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}

int	open_file(char *file, int flags, t_vars *vars)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
		error_message_free("fdf: Invalid file, could not open.\n", 1, vars);
	return (fd);
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->map.map)
	{
		while (++i < vars->map.height)
			free(vars->map.map[i]);
		free(vars->map.map);
	}
	i = -1;
	if (vars->map.colored)
	{
		while (++i < vars->map.height)
			free(vars->map.colored[i]);
		free(vars->map.colored);
	}
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img_ptr)
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	free(vars);
}

int	close_window(t_vars *vars)
{
	free_vars(vars);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		close_window(vars);
	return (0);
}

void	init_everything(t_vars *vars, char *title)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, title);
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addrs = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	vars->magnify = (WIN_WIDTH / vars->map.width) / MAGNIFY_SCALE;
	vars->coord.x1 = 0;
	vars->coord.y1 = 0;
	vars->coord.z1 = 0;
}

void	render_map(t_vars *vars)
{
	draw(vars);


	// building the window
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, CLOSE, 1L << 1, close_window, vars);
	mlx_loop(vars->mlx);
}









int	main(void)
{
	t_vars	*vars;
	// char **argv = map;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);

	// temporary testing
	vars->map.width = 10; // temporary test value


	// parse_arg(argv, argc, vars); // original code; not needed; thus commented

	init_everything(vars, "Testing title");
	render_map(vars); // main func to for rendering
	free_vars(vars);
	return (0);
}


















