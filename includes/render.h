/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:09:34 by selow             #+#    #+#             */
/*   Updated: 2026/10/01 18:09:36 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RENDER_H
# define RENDER_H

# define MAP_SIZE 100
# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define ESC_KEY		0xff1b
# define CLOSE			17
# define GRID_CELL_SIZE 64


# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define PI 3.1415926535 // first 30
# define FOV (PI/3)
# define cell_size 64 // the map's grid cells sizes (64 * 64 pixels)

/*
To tell shunqi
-> Should have a definition/variable of WIN_WIDTH and WIN_HEIGHT so that we can change it
-> Im probably the one initialising the window, as I will need to handle the img ptrs etc
-> Getting the textures, or just discuss on what textures we will be using

BONUS THAT WILL BE IMPLEMENTED:
Bonus list:
• Wall collisions.
• Animated sprites.
• Rotate the point of view with the mouse.
• Doors which can open and close. // up to you

*/

# include <mlx.h>

typedef enum e_texture_enum
{
	NO = 0,
	SO = 1,
	EA = 2,
	WE = 3,
	F = 4,
	C = 5
}	t_texture_enum;

typedef struct s_texture
{
	int		floor[3]; // the 3 is referring to their RGB values
	int		ceiling[3];
	char	*wall_textures[4];
	char	*floor_ceiling[2];
	char	map[MAP_SIZE][MAP_SIZE + 1];
	int		player_x;
	int		player_y;

	char	dir; //NSEW
}	t_texture;

typedef struct s_player
{
    double x;
    double y;
    double pitch;
    int mouse_x;
    int mouse_y;
    int mouse_warped;

    double dir_x;
    double dir_y;

    double plane_x;
    double plane_y;

} t_player;


typedef struct s_img
{
	void	*ptr;
	char	*addrs;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
	int		width;
	int		height;
} 	t_img;


typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
}	t_window;

typedef struct s_ray
{
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	double camera_x;
	double perp_wall_dist;
	double wall_x;
	int map_x;
	int map_y;
	int step_x;
	int step_y;
	double dir_x;
	double dir_y;
	int draw_start;
	int draw_end;
	int texture_x;
	int texture_y;
	int wall_texture;
	double plane_len;
	double plane_x;
	double plane_y;
	char wall_hit;
}	t_ray;


// MAIN RENDERING STRUCT THAT WILL BE USED
// BASICALLY JUST DATA CARRYIGN EVERYTHING
typedef struct s_render
{
	t_texture	texture; // remaining this to transfer into player
	t_player	player;
	t_ray		ray;
	t_window	win; // finished with init
	t_img		img; // finished with init
	t_img		wall[4];
}	t_render;

/*
void	init_renderer_side(t_vars *vars, char **argv)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addrs = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	// vars->magnify = (WIN_WIDTH / vars->map.width) / MAGNIFY_SCALE; // for minimap if want to implement
}
*/

// put pixel func
// put_pixel();

// MAIN FUNCTION
// draw(t_texture t);

/*
typedef struct s_vars
{
	t_img	img;
	t_coor	coord;
	void	*mlx;
	void	*win;
	float	magnify;
}	t_vars;
*/

int		render(t_texture *t);

void	put_pixel(t_render *r, int x, int y, int color);

void	init_renderer_side(t_render *r, t_texture *t, char *title);
void	init_ray(t_render *r, int x);
void	perform_dda(t_render *r);
void	calculate_wall_distance(t_render *r);
void	draw_wall_column(t_render *r, int x);
int		close_window(t_render *r);
int		key_hook(int keycode, t_render *r);
int		is_walkable(t_render *r, double x, double y);
int		rgb_to_int(int rgb[3]);
int		wall_color(t_render *r);
int		texture_pixel(t_img *texture, int x, int y);
int		move_forward(t_render *r);
int		move_backward(t_render *r);
int		move_left(t_render *r);
int		move_right(t_render *r);
int		rotate_left(t_render *r);
int		rotate_right(t_render *r);
int		rotate_by(t_render *r, double angle);
void	adjust_pitch(t_render *r, double amount);
int		mouse_hook(int x, int y, t_render *r);

#endif



// try to create an mlx loop that creates dots on the screen for each 1 and P there is 
// (Creating a box basically)