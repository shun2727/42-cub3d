/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 12:40:00 by selow             #+#    #+#             */
/*   Updated: 2026/11/23 12:40:00 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	rgb_to_int(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	wall_color(t_render *r)
{
	int	color;

	color = rgb_to_int(r->texture.ceiling);
	if (r->ray.wall_hit == 'y')
		color = (color >> 1) & 8355711;
	return (color);
}

int	texture_pixel(t_img *texture, int x, int y)
{
	int	i;

	if (!texture->addrs || x < 0 || x >= texture->width
		|| y < 0 || y >= texture->height)
		return (0);
	i = x * texture->bits_per_pixel / 8 + y * texture->line_len;
	if (texture->endian)
		return ((unsigned char)texture->addrs[i] << 16
			| (unsigned char)texture->addrs[i + 1] << 8
			| (unsigned char)texture->addrs[i + 2]);
	return ((unsigned char)texture->addrs[i + 2] << 16
		| (unsigned char)texture->addrs[i + 1] << 8
		| (unsigned char)texture->addrs[i]);
}
