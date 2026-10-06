/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_and_debug.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 20:48:22 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 23:52:18 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(t_texture *texture)
{
	free(texture->wall_textures[0]);
	free(texture->wall_textures[1]);
	free(texture->wall_textures[2]);
	free(texture->wall_textures[3]);
	free(texture->floor_ceiling[0]);
	free(texture->floor_ceiling[1]);
}

void	print_struct_debug(t_texture *texture)
{
	printf("%s\n", texture->wall_textures[0]);
	printf("%s\n", texture->wall_textures[1]);
	printf("%s\n", texture->wall_textures[2]);
	printf("%s\n", texture->wall_textures[3]);
	printf("floor R: %d\n", texture->floor[0]);
	printf("floor G: %d\n", texture->floor[1]);
	printf("floor B: %d\n", texture->floor[2]);
	printf("ceiling R: %d\n", texture->ceiling[0]);
	printf("ceiling G:%d\n", texture->ceiling[1]);
	printf("ceiling B:%d\n", texture->ceiling[2]);
	printf("player_y : %d\n", texture->player_y);
	printf("player_x : %d\n", texture->player_x);
	printf("player direction : %c\n", texture->player_dir);
	print_map_debug(texture->map);
		
}

void	print_map_debug(char map[MAP_SIZE][MAP_SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < MAP_SIZE)
	{
		col = 0;
		while (col < MAP_SIZE)
		{
			ft_printf("%c", map[row][col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
}
