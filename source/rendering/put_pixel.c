/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:32:01 by selow             #+#    #+#             */
/*   Updated: 2025/11/11 20:32:06 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_pixel(t_render *r, int x, int y, int color)
{
	int		i;
	int		bytes;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		i = x * r->img.bits_per_pixel / 8 + y * r->img.line_len;
		bytes = r->img.bits_per_pixel / 8;
		if (r->img.endian)
		{
			r->img.addrs[i] = color >> 16;
			r->img.addrs[i + 1] = color >> 8;
			r->img.addrs[i + 2] = color;
		}
		else
		{
			r->img.addrs[i] = color;
			r->img.addrs[i + 1] = color >> 8;
			r->img.addrs[i + 2] = color >> 16;
		}
		if (bytes == 4)
			r->img.addrs[i + 3] = 0;
	}
}
