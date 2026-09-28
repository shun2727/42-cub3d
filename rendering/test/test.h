
// TEMPORARY STRUCTS TAKEN FROM MY FDF, USED ONLY TO OPEN DA WINDOW ======

#ifndef TEST_H
# define TEST_H

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






void	init_everything(t_vars *vars, char *title);
void	render_map(t_vars *vars);
void	free_vars(t_vars *vars);







#endif
// TEMPORARY STRUCTS TAKEN FROM MY FDF, USED ONLY TO OPEN DA WINDOW ^^^^^^





