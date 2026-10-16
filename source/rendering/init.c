/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:15:03 by selow             #+#    #+#             */
/*   Updated: 2026/10/01 18:15:04 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

// initialising everything
void	init_renderer_side(t_render *r, t_texture *t, char *title)
{
	// initialisation of the window and image
	r->win.mlx = mlx_init();
	r->win.mlx_win = mlx_new_window(r->win.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	r->img.ptr = mlx_new_image(r->win.mlx, WIN_WIDTH, WIN_HEIGHT);
	r->img.addrs = mlx_get_data_addr(r->img.ptr,
			&r->img.bits_per_pixel, &r->img.line_len, &r->img.endian);
	// vars->magnify = (WIN_WIDTH / vars->map.width) / MAGNIFY_SCALE; // for minimap if want to implement

	// init of player
	r->player.x = t->player_x;
	r->player.y = t->player_y;
	r->player.dir_x = 0; // PLACEHOLDER, NOT ACTUAL VALUE
	r->player.dir_y = 0; // PLACEHOLDER, NOT ACTUAL VALUE

}

// //+1 because want to loop till null
// typedef struct s_texture
// {
// 	int		floor[3]; // the 3 is referring to their RGB values
// 	int		ceiling[3];
// 	char	*wall_textures[4];
// 	char	*floor_ceiling[2];
// 	char	map[MAP_SIZE][MAP_SIZE + 1];
	
// 	int		player_x;
// 	int		player_y;

// 	char	dir; //NSEW
// }	t_texture;



// typedef struct s_player
// {
//     double x;
//     double y;

//     double dir_x;
//     double dir_y;

//     double plane_x; // has not been initialised yet, will be used later on
//     double plane_y;

// } t_player;

// typedef struct s_img
// {
// 	void	*ptr;
// 	void	*addrs;
// 	int		line_len;
// 	int		bits_per_pixel;
// } 	t_img;

// typedef struct s_window
// {
// 	void	*mlx;
// 	void	*mlx_win;

// }	t_window;


// // MAIN RENDERING STRUCT THAT WILL BE USED
// typedef struct s_render
// {
// 	t_texture	texture; // remaining this to transfer into player
// 	t_player	player;
// 	t_window	win; // finished with init
// 	t_img		img; // finished with init
// }	t_render;
