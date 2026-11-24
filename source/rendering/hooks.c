/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 12:40:00 by selow             #+#    #+#             */
/*   Updated: 2026/11/23 12:40:00 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	close_window(t_render *r)
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
		mlx_loop_end(r->win.mlx);
		mlx_destroy_display(r->win.mlx);
	}
	return (0);
}

int	key_hook(int keycode, t_render *r)
{
	if (keycode == ESC_KEY)
		close_window(r);
	if (keycode == XK_w)
		move_forward(r);
	if (keycode == XK_s)
		move_backward(r);
	if (keycode == XK_a)
		move_left(r);
	if (keycode == XK_d)
		move_right(r);
	if (keycode == 0xff51) // mouse
		rotate_by(r, -10.9);
	if (keycode == 0xff53) // mouse 
		rotate_by(r, 10.9);
	if (keycode == XK_Up)
		adjust_pitch(r, 20);
	if (keycode == XK_Down)
		adjust_pitch(r, -20);
	return (0);
}

int	mouse_hook(int x, int y, t_render *r)
{
	int	delta_x;

	(void)y;
	if (r->player.mouse_x < 0)
	{
		r->player.mouse_x = x;
		r->player.mouse_y = y;
		return (0);
	}
	delta_x = x - r->player.mouse_x;
	if (delta_x)
		rotate_by(r, delta_x * 0.001);
	r->player.mouse_x = x;
	r->player.mouse_y = y;
	return (0);
}
