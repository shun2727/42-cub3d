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

void	render_frame(t_render *r)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(r, x);
		perform_dda(r);
		calculate_wall_distance(r);
		draw_wall_column(r, x);
		x++;
	}
}

int	game_loop(t_render *r)
{
	render_frame(r);
	mlx_put_image_to_window(r->win.mlx, r->win.mlx_win, r->img.ptr, 0, 0);
	return (0);
}

int	render(t_texture *t)
{
	t_render	r;

	init_renderer_side(&r, t, "Cub3D");
	mlx_do_key_autorepeaton(r.win.mlx);
	mlx_loop_hook(r.win.mlx, game_loop, &r);
	mlx_hook(r.win.mlx_win, KeyPress, KeyPressMask, key_hook, &r);
	mlx_hook(r.win.mlx_win, CLOSE, 1L << 1, close_window, &r);
	mlx_mouse_hide(r.win.mlx, r.win.mlx_win);
	mlx_hook(r.win.mlx_win, MotionNotify, PointerMotionMask, mouse_hook, &r);
	mlx_loop(r.win.mlx);
	return (0);
}
