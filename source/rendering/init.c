/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:15:03 by selow             #+#    #+#             */
/*   Updated: 2026/10/01 18:15:04 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

// initialising everything
void	init_renderer_side(t_render *r, t_texture *t, char *title)
{
	char	direction;
	int		row;
	int		col;
	int		i;
	int		width;
	int		height;

	r->texture = *t;
	r->win.mlx = mlx_init();
	r->win.mlx_win = mlx_new_window(r->win.mlx, WIN_WIDTH, WIN_HEIGHT, title);
	r->img.ptr = mlx_new_image(r->win.mlx, WIN_WIDTH, WIN_HEIGHT);
	r->img.addrs = mlx_get_data_addr(r->img.ptr,
			&r->img.bits_per_pixel, &r->img.line_len, &r->img.endian);
	i = 0;
	while (i < 4)
	{
		r->wall[i].ptr = NULL;
		r->wall[i].addrs = NULL;
		r->wall[i].width = 0;
		r->wall[i].height = 0;
		if (t->wall_textures[i])
		{
			r->wall[i].ptr = mlx_xpm_file_to_image(r->win.mlx,
					t->wall_textures[i], &width, &height);
			if (r->wall[i].ptr)
			{
				r->wall[i].width = width;
				r->wall[i].height = height;
				r->wall[i].addrs = mlx_get_data_addr(r->wall[i].ptr,
						&r->wall[i].bits_per_pixel,
						&r->wall[i].line_len, &r->wall[i].endian);
			}
		}
		i++;
	}
	r->player.x = t->player_x + 0.5;
	r->player.y = t->player_y + 0.5;
	r->player.pitch = 0;
	r->player.mouse_x = -1;
	r->player.mouse_y = -1;
	r->player.mouse_warped = 0;
	r->controls.forward = 0;
	r->controls.backward = 0;
	r->controls.left = 0;
	r->controls.right = 0;
	r->controls.turn_left = 0;
	r->controls.turn_right = 0;
	direction = t->dir;
	if (direction != 'N' && direction != 'S'
		&& direction != 'E' && direction != 'W')
	{
		row = 0;
		while (row < MAP_SIZE)
		{
			col = 0;
			while (col < MAP_SIZE && t->map[row][col] != '\0')
			{
				if (t->map[row][col] == 'N' || t->map[row][col] == 'S'
					|| t->map[row][col] == 'E' || t->map[row][col] == 'W')
				{
					direction = t->map[row][col];
					row = MAP_SIZE;
					break ;
				}
				col++;
			}
			if (row < MAP_SIZE)
				row++;
		}
	}
	if (direction == 'N')
	{
		r->player.dir_x = 0;
		r->player.dir_y = -1;
		r->player.plane_x = 0.66;
		r->player.plane_y = 0;
	}
	else if (direction == 'S')
	{
		r->player.dir_x = 0;
		r->player.dir_y = 1;
		r->player.plane_x = -0.66;
		r->player.plane_y = 0;
	}
	else if (direction == 'W')
	{
		r->player.dir_x = -1;
		r->player.dir_y = 0;
		r->player.plane_x = 0;
		r->player.plane_y = -0.66;
	}
	else
	{
		r->player.dir_x = 1;
		r->player.dir_y = 0;
		r->player.plane_x = 0;
		r->player.plane_y = 0.66;
	}
}
