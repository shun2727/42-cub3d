
// TEMPORARY TESTER FILE TAKEN FROM MY FDF, USED ONLY TO OPEN DA WINDOW
#include "test.h"
#include "libft.h"


static int	get_comma_pos(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != ',')
		i++;
	if (s[i] == ',')
		return (i);
	return (-1);
}

static int	*fill_int_arr2(const char *s, int *arr)
{
	int			i;
	const char	*p;
	int			comma;

	i = 0;
	p = s;
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (!*p)
			break ;
		comma = get_comma_pos(p);
		if (comma >= 0)
			arr[i++] = ft_atoi_base(p + comma + 1, 16);
		else
			arr[i++] = -1;
		while (*p && *p != ' ')
			p++;
	}
	return (arr);
}

int	*split_atoi_colour(const char *s)
{
	int			count;
	const char	*p;
	int			*arr;

	count = 0;
	p = s;
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (*p)
		{
			count++;
			while (*p && *p != ' ')
				p++;
		}
	}
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	return (fill_int_arr2(s, arr));
}

static int	*fill_int_arr(const char *s, char sep, int *arr)
{
	const char	*p;
	int			i;

	p = s;
	i = 0;
	while (*p)
	{
		while (*p && *p == sep)
			p++;
		if (!(*p))
			break ;
		arr[i++] = ft_atoi(p);
		while (*p && *p != sep)
			p++;
	}
	return (arr);
}

int	*split_atoi(const char *s, char sep, int *out_len)
{
	int			count;
	const char	*p;
	int			*arr;

	if (!s || !*s)
		return (NULL);
	count = 0;
	p = s;
	*out_len = 0;
	while (*p)
	{
		while (*p && *p == sep)
			p++;
		if (*p)
		{
			count++;
			while (*p && *p != sep)
				p++;
		}
	}
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	*out_len = count;
	return (fill_int_arr(s, sep, arr));
}


void	put_pixel(t_vars *vars, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		i = (x * vars->img.bits_per_pixel / 8) + (y * vars->img.line_len);
		vars->img.addrs[i] = color;
		vars->img.addrs[++i] = color >> 8;
		vars->img.addrs[++i] = color >> 16;
	}
}


void	error_message(char *s, int exit_code)
{
	ft_printf_fd(2, s);
	exit(exit_code);
}

void	error_message_free(char *s, int exit_code, t_vars *vars)
{
	ft_printf_fd(2, s);
	free_vars(vars);
	exit(exit_code);
}

void	fill_background(t_vars *vars, int color)
{
	int	x;
	int	y;

	y = 0;
	while (++y < WIN_HEIGHT)
	{
		x = 0;
		while (++x < WIN_WIDTH)
			put_pixel(vars, x, y, color);
	}
}

int	open_file(char *file, int flags, t_vars *vars)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
		error_message_free("fdf: Invalid file, could not open.\n", 1, vars);
	return (fd);
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
	// draw(vars);


	// building the window
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, CLOSE, 1L << 1, close_window, vars);
	mlx_loop(vars->mlx);
}

// TEMPORARY TESTER FILE TAKEN FROM MY FDF, USED ONLY TO OPEN DA WINDOW ^^^^^^

