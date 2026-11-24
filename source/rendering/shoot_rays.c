/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 12:35:00 by selow             #+#    #+#             */
/*   Updated: 2026/11/23 12:35:00 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_ray(t_render *r, int x)
{
	r->ray.camera_x = 2.0 * x / WIN_WIDTH - 1.0;
	r->ray.dir_x = r->player.dir_x
		+ r->player.plane_x * r->ray.camera_x;
	r->ray.dir_y = r->player.dir_y
		+ r->player.plane_y * r->ray.camera_x;
	r->ray.map_x = (int)r->player.x;
	r->ray.map_y = (int)r->player.y;
	if (r->ray.dir_x == 0)
		r->ray.delta_dist_x = 1e30;
	else
		r->ray.delta_dist_x = fabs(1.0 / r->ray.dir_x);
	if (r->ray.dir_y == 0)
		r->ray.delta_dist_y = 1e30;
	else
		r->ray.delta_dist_y = fabs(1.0 / r->ray.dir_y);
	if (r->ray.dir_x < 0)
	{
		r->ray.step_x = -1;
		r->ray.side_dist_x = (r->player.x - r->ray.map_x)
			* r->ray.delta_dist_x;
	}
	else
	{
		r->ray.step_x = 1;
		r->ray.side_dist_x = (r->ray.map_x + 1.0 - r->player.x)
			* r->ray.delta_dist_x;
	}
	if (r->ray.dir_y < 0)
	{
		r->ray.step_y = -1;
		r->ray.side_dist_y = (r->player.y - r->ray.map_y)
			* r->ray.delta_dist_y;
	}
	else
	{
		r->ray.step_y = 1;
		r->ray.side_dist_y = (r->ray.map_y + 1.0 - r->player.y)
			* r->ray.delta_dist_y;
	}
}

void	perform_dda(t_render *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->ray.side_dist_x < r->ray.side_dist_y)
		{
			r->ray.side_dist_x += r->ray.delta_dist_x;
			r->ray.map_x += r->ray.step_x;
			r->ray.wall_hit = 'x';
		}
		else
		{
			r->ray.side_dist_y += r->ray.delta_dist_y;
			r->ray.map_y += r->ray.step_y;
			r->ray.wall_hit = 'y';
		}
		if (r->ray.map_x < 0 || r->ray.map_x >= MAP_SIZE
			|| r->ray.map_y < 0 || r->ray.map_y >= MAP_SIZE)
			hit = 1;
		else if (r->texture.map[r->ray.map_y][r->ray.map_x] == '1')
			hit = 1;
		else if (r->texture.map[r->ray.map_y][r->ray.map_x] == '\0')
			hit = 1;
	}
}

void	calculate_wall_distance(t_render *r)
{
	int	line_height;

	if (r->ray.wall_hit == 'x')
		r->ray.perp_wall_dist = (r->ray.map_x - r->player.x
				+ (1 - r->ray.step_x) / 2.0) / r->ray.dir_x;
	else
		r->ray.perp_wall_dist = (r->ray.map_y - r->player.y
				+ (1 - r->ray.step_y) / 2.0) / r->ray.dir_y;
	if (r->ray.perp_wall_dist <= 0)
		r->ray.perp_wall_dist = 0.0001;
	line_height = (int)(WIN_HEIGHT / r->ray.perp_wall_dist);
	r->ray.draw_start = -line_height / 2 + WIN_HEIGHT / 2
		+ (int)r->player.pitch;
	if (r->ray.draw_start < 0)
		r->ray.draw_start = 0;
	r->ray.draw_end = line_height / 2 + WIN_HEIGHT / 2
		+ (int)r->player.pitch;
	if (r->ray.draw_end >= WIN_HEIGHT)
		r->ray.draw_end = WIN_HEIGHT - 1;
	if (r->ray.wall_hit == 'x')
		r->ray.wall_x = r->player.y
			+ r->ray.perp_wall_dist * r->ray.dir_y;
	else
		r->ray.wall_x = r->player.x
			+ r->ray.perp_wall_dist * r->ray.dir_x;
	r->ray.wall_x -= floor(r->ray.wall_x);
	if (r->ray.wall_hit == 'x' && r->ray.dir_x > 0)
		r->ray.wall_texture = WE;
	else if (r->ray.wall_hit == 'x')
		r->ray.wall_texture = EA;
	else if (r->ray.dir_y > 0)
		r->ray.wall_texture = NO;
	else
		r->ray.wall_texture = SO;
}
