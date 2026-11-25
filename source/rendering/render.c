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
	update_held_keys(r);
	render_frame(r);
	mlx_put_image_to_window(r->win.mlx, r->win.mlx_win, r->img.ptr, 0, 0);
	return (0);
}

static void	destroy_renderer(t_render *r)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (r->wall[i].ptr)
			mlx_destroy_image(r->win.mlx, r->wall[i].ptr);
		i++;
	}
	if (r->img.ptr)
		mlx_destroy_image(r->win.mlx, r->img.ptr);
	if (r->win.mlx_win)
		mlx_destroy_window(r->win.mlx, r->win.mlx_win);
	if (r->win.mlx)
	{
		mlx_destroy_display(r->win.mlx);
		free(r->win.mlx);
	}
}

int	render(t_texture *t)
{
	t_render	r;

	init_renderer_side(&r, t, "Cub3D");
	mlx_do_key_autorepeaton(r.win.mlx);
	mlx_loop_hook(r.win.mlx, game_loop, &r);
	mlx_hook(r.win.mlx_win, KeyPress, KeyPressMask, key_hook, &r);
	mlx_hook(r.win.mlx_win, KeyRelease, KeyReleaseMask, key_release_hook, &r);
	mlx_hook(r.win.mlx_win, CLOSE, 1L << 1, close_window, &r);
	mlx_mouse_hide(r.win.mlx, r.win.mlx_win);
	mlx_hook(r.win.mlx_win, MotionNotify, PointerMotionMask, mouse_hook, &r);
	mlx_loop(r.win.mlx);
	destroy_renderer(&r);
	return (0);
}
