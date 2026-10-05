/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:09:27 by selow             #+#    #+#             */
/*   Updated: 2026/10/01 18:09:28 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
// Init func on my side, storing everything into my own struct
// start drawing a square and the player 
// 

//temp
int	close_window(t_render *r)
{
	//free_vars(vars);
	(void)r; // temp due to free vars being commented out and -Wextra hates me
	exit(0); 
}
int	key_hook(int keycode, t_render *r)
{
	if (keycode == ESC_KEY)
		close_window(r);
	return (0);
}


int	render(t_texture *t)
{
	t_render	r;
	init_renderer_side(&r, t, "Cub3D");

	// test drawing
	for (int i = 20; i < 100; i++)
		put_pixel(&r, i, 20, 255); // testing window


	// test case:
	// just grab the map and draw the obstacles
	// alongside the player as just a dot (They must all be big enough to be visible)
	
	// calculate mapheight and mapwidth functions
	// size_t i = 0;

	// while (r.texture.map[i] != NULL) // row
	// {
	// 	for (size_t j = 0; j < ft_strlen(r.texture.map[i]); j++) // col
	// 	{
	// 		put_pixel(&r, i, j, 255); // testing window
	// 	}
	// 	i++;
	// }



	// actually putting everythign together
	mlx_put_image_to_window(r.win.mlx, r.win.mlx_win, r.img.ptr, 0, 0);
	mlx_key_hook(r.win.mlx_win, key_hook, &r);
	mlx_hook(r.win.mlx_win, CLOSE, 1L << 1, close_window, &r);
	mlx_loop(r.win.mlx);

	// raycasting side: Shooting rays

	// raycasting side: Drawing
	
	return 0;
}
