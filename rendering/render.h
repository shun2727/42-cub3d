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

// TEMP
#define MAP_SIZE 100
# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define ESC_KEY		0xff1b
# define CLOSE			17
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
/*
To tell shunqi
-> Should have a definition/variable of WIN_WIDTH and WIN_HEIGHT so that we can change it
-> Im probably the one initialising the window, as I will need to handle the img ptrs etc

*/

# include <mlx.h>

//+1 because want to loop till null
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
	int		endian; // not used
} 	t_img;


typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	
}	t_window;



// MAIN RENDERING STRUCT THAT WILL BE USED
// BASICALLY JUST DATA CARRYIGN EVERYTHING
typedef struct s_render
{
	t_texture	texture; // remaining this to transfer into player
	t_player	player;
	t_window	win; // finished with init
	t_img		img; // finished with init
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

int	render(t_texture *t);

void	put_pixel(t_render *r, int x, int y, int color);

void	init_renderer_side(t_render *r, t_texture *t, char *title);

#endif



// try to create an mlx loop that creates dots on the screen for each 1 and P there is 
// (Creating a box basically)
