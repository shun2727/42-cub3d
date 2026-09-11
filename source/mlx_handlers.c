/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:56:02 by syee              #+#    #+#             */
/*   Updated: 2026/09/08 17:57:20 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int hook_close_window(int keycode, t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	//clean up (to be added)
	return (0);
}

//enums declared in X11/keysym.h
int key_hook(int keycode, t_window *window)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(window->mlx, window->mlx_win);
		//clean up (to be added)
		return (0);
	}
	if (keycode == XK_w)
		;
	if (keycode == XK_s)
		;
	if (keycode == XK_a)
		;
	if (keycode == XK_d)
		;
	if (keycode == XK_w)
		;
	if (keycode == XK_Left)
		;
	if (keycode == XK_Right)
		;
}
