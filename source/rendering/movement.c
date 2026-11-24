/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 12:40:00 by selow             #+#    #+#             */
/*   Updated: 2026/11/23 12:40:00 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	is_walkable(t_render *r, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= MAP_SIZE
		|| map_y < 0 || map_y >= MAP_SIZE)
		return (0);
	return (r->texture.map[map_y][map_x] != '1'
		&& r->texture.map[map_y][map_x] != '\0');
}

static int	can_move_to(t_render *r, double x, double y)
{
	double	radius;

	radius = 0.15;
	if (!is_walkable(r, x - radius, y - radius)
		|| !is_walkable(r, x - radius, y + radius)
		|| !is_walkable(r, x + radius, y - radius)
		|| !is_walkable(r, x + radius, y + radius))
		return (0);
	return (1);
}

int	move_forward(t_render *r)
{
	double	new_x;
	double	new_y;

	new_x = r->player.x + r->player.dir_x * 0.1;
	new_y = r->player.y + r->player.dir_y * 0.1;
	if (can_move_to(r, new_x, r->player.y))
		r->player.x = new_x;
	if (can_move_to(r, r->player.x, new_y))
		r->player.y = new_y;
	return (0);
}

int	move_backward(t_render *r)
{
	double	new_x;
	double	new_y;

	new_x = r->player.x - r->player.dir_x * 0.1;
	new_y = r->player.y - r->player.dir_y * 0.1;
	if (can_move_to(r, new_x, r->player.y))
		r->player.x = new_x;
	if (can_move_to(r, r->player.x, new_y))
		r->player.y = new_y;
	return (0);
}

int	move_left(t_render *r)
{
	double	new_x;
	double	new_y;

	new_x = r->player.x - r->player.plane_x * 0.1;
	new_y = r->player.y - r->player.plane_y * 0.1;
	if (can_move_to(r, new_x, r->player.y))
		r->player.x = new_x;
	if (can_move_to(r, r->player.x, new_y))
		r->player.y = new_y;
	return (0);
}

int	move_right(t_render *r)
{
	double	new_x;
	double	new_y;

	new_x = r->player.x + r->player.plane_x * 0.1;
	new_y = r->player.y + r->player.plane_y * 0.1;
	if (can_move_to(r, new_x, r->player.y))
		r->player.x = new_x;
	if (can_move_to(r, r->player.x, new_y))
		r->player.y = new_y;
	return (0);
}

int	rotate_left(t_render *r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = r->player.dir_x;
	old_plane_x = r->player.plane_x;
	r->player.dir_x = r->player.dir_x * cos(-0.1)
		- r->player.dir_y * sin(-0.1);
	r->player.dir_y = old_dir_x * sin(-0.1)
		+ r->player.dir_y * cos(-0.1);
	r->player.plane_x = r->player.plane_x * cos(-0.1)
		- r->player.plane_y * sin(-0.1);
	r->player.plane_y = old_plane_x * sin(-0.1)
		+ r->player.plane_y * cos(-0.1);
	return (0);
}

int	rotate_right(t_render *r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = r->player.dir_x;
	old_plane_x = r->player.plane_x;
	r->player.dir_x = r->player.dir_x * cos(0.1)
		- r->player.dir_y * sin(0.1);
	r->player.dir_y = old_dir_x * sin(0.1)
		+ r->player.dir_y * cos(0.1);
	r->player.plane_x = r->player.plane_x * cos(0.1)
		- r->player.plane_y * sin(0.1);
	r->player.plane_y = old_plane_x * sin(0.1)
		+ r->player.plane_y * cos(0.1);
	return (0);
}

int	rotate_by(t_render *r, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = r->player.dir_x;
	old_plane_x = r->player.plane_x;
	r->player.dir_x = r->player.dir_x * cos(angle)
		- r->player.dir_y * sin(angle);
	r->player.dir_y = old_dir_x * sin(angle)
		+ r->player.dir_y * cos(angle);
	r->player.plane_x = r->player.plane_x * cos(angle)
		- r->player.plane_y * sin(angle);
	r->player.plane_y = old_plane_x * sin(angle)
		+ r->player.plane_y * cos(angle);
	return (0);
}

void	adjust_pitch(t_render *r, double amount)
{
	r->player.pitch += amount;
	if (r->player.pitch > WIN_HEIGHT / 4)
		r->player.pitch = WIN_HEIGHT / 4;
	if (r->player.pitch < -WIN_HEIGHT / 4)
		r->player.pitch = -WIN_HEIGHT / 4;
}
