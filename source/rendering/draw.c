/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 12:40:00 by selow             #+#    #+#             */
/*   Updated: 2026/11/23 12:40:00 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_wall_column(t_render *r, int x)
{
	int	y;
	int	texture_x;
	int	texture_y;
	int	line_height;
	t_img	*texture;

	y = 0;
	while (y < r->ray.draw_start)
	{
		put_pixel(r, x, y, rgb_to_int(r->texture.ceiling));
		y++;
	}
	while (y <= r->ray.draw_end)
	{
		texture = &r->wall[r->ray.wall_texture];
		if (texture->ptr)
		{
			texture_x = (int)(r->ray.wall_x * texture->width);
			line_height = r->ray.draw_end - r->ray.draw_start + 1;
			texture_y = (y - r->ray.draw_start)
				* texture->height / line_height;
			put_pixel(r, x, y, texture_pixel(texture,
					texture_x, texture_y));
		}
		else
			put_pixel(r, x, y, wall_color(r));
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		put_pixel(r, x, y, rgb_to_int(r->texture.floor));
		y++;
	}
}
