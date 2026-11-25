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

#include <sys/time.h>

static void	set_key_state(int keycode, t_render *r, int pressed)
{
	if (keycode == XK_w || keycode == XK_W)
		r->controls.forward = pressed;
	if (keycode == XK_s || keycode == XK_S)
		r->controls.backward = pressed;
	if (keycode == XK_a || keycode == XK_A)
		r->controls.left = pressed;
	if (keycode == XK_d || keycode == XK_D)
		r->controls.right = pressed;
	if (keycode == XK_q || keycode == XK_Q)
		r->controls.turn_left = pressed;
	if (keycode == XK_e || keycode == XK_E)
		r->controls.turn_right = pressed;
}

int	close_window(t_render *r)
{
	if (r->win.mlx)
		mlx_loop_end(r->win.mlx);
	return (0);
}

int	key_release_hook(int keycode, t_render *r)
{
	set_key_state(keycode, r, 0);
	return (0);
}

int	update_held_keys(t_render *r)
{
	static struct timeval	last_update;
	static int				initialized;
	struct timeval			now;
	long					elapsed;

	gettimeofday(&now, NULL);
	if (!initialized)
	{
		last_update = now;
		initialized = 1;
		return (0);
	}
	elapsed = (now.tv_sec - last_update.tv_sec) * 1000000L
		+ now.tv_usec - last_update.tv_usec;
	if (elapsed < 40000)
		return (0);
	last_update = now;
	if (r->controls.forward)
		move_forward(r);
	if (r->controls.backward)
		move_backward(r);
	if (r->controls.left)
		move_left(r);
	if (r->controls.right)
		move_right(r);
	if (r->controls.turn_left)
		rotate_by(r, -0.1);
	if (r->controls.turn_right)
		rotate_by(r, 0.1);
	return (0);
}

int	key_hook(int keycode, t_render *r)
{
	set_key_state(keycode, r, 1);
	if (keycode == ESC_KEY)
		close_window(r);
	if (keycode == 0xff51) // mouse
		rotate_by(r, -0.1);
	if (keycode == 0xff53) // mouse 
		rotate_by(r, 0.1);
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
