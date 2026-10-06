/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 22:03:35 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 23:50:27 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_texture(char *str)
{
	char	map_texture[9];
	int		i;
	bool	flag;

	init_map_texture(map_texture);	
	while (*str != '\n' && *str != '\0')
	{
		i = 0;
		flag = false;
		while (map_texture[i])
		{
			if (*str == map_texture[i])
			{
				flag = true;
				break ;
			}
			else if (i == 6 && flag == false)
				return (1);
			i++;
		}
		str++;
	}
	return (0);
}


/**
 * @brief Fills up the map line by line
 * 
 * @param map Pointer to the original map
 * @param str Line to fill up the map with
 * @param texture 
 * @return int (0 for success, 1 for failure)
 */
int	feed_map(char (*map)[MAP_SIZE][MAP_SIZE], char *str, t_texture *texture)
{
	static int	row;
	int			col;
	int			map_len;
	
	col = 0;
	if (ft_strchr(str, '\n')) //if it has a newline then minus the new line
		map_len = ft_strlen(str) - 1;
	else
		map_len = ft_strlen(str); //this is if it has a null temrinato
	if (map_len >= MAP_SIZE - 2  || row >= MAP_SIZE - 2)
		return (ft_printf("Error : Map too large, Enter a 100x100 size."), 1);
	while (*str != '\n' && *str != '\0')
	{
		(*map)[row + 1][col + 1] = *str;
		if (match_direction(*str))
		{
			if (texture->player_x == 0 || texture->player_y == 0)
			{	
				texture->player_x = col + 1 ;
				texture->player_y = row + 1;
				texture->player_dir = *str;
			}
			else
				return (ft_printf("Error : Multiple player positions found"), 1);
		}
		str++;
		col++;
	}
	row++;
	return (0);
}

/**
 * @brief Creates a copy of the map and does floodfill on the copy,
 * upon success, floodfil the original map to ensure the enclosed values are 
 * all filled up.
 * 
 * @param ori_map pass in the original map 
 * @param texture pass in the texture
 * @return int 
 */
int validate_map(char (*ori_map)[MAP_SIZE][MAP_SIZE], t_texture *texture)
{
	char map_copy[MAP_SIZE][MAP_SIZE];

	if (texture->player_x == 0 || texture->player_y == 0)
		return (ft_printf("Error : Player position not included"), 1);
	dup_map(*ori_map, &map_copy);
	flood_outside_map(0, 0, &map_copy);
	if (flood_inside_map(texture->player_y, texture->player_x, &map_copy) == 1)
		return(ft_printf("Error : walls of map are not closed."), 1);
	else
		flood_inside_map(texture->player_y, texture->player_x, ori_map);
	return (0);
}
/* Helper functions */

int match_direction(char dir)
{
	char	direction[5];
	int		i;

	i = 0;
	direction[0]='N';
	direction[1]='S';
	direction[2]='W';
	direction[3]='E';
	direction[4]='\0';
	while (i < 4)
	{
		if (dir == direction[i])
			return (1);
		i++;
	}
	return (0);
}

void init_map_texture(char map_texture[8])
{
	map_texture[0] = '0';
	map_texture[1] = '1';
	map_texture[2] = 'N';
	map_texture[3] = 'S';
	map_texture[4] = 'E';
	map_texture[5] = 'W';
	map_texture[6] = ' ';
	map_texture[7] = '\0';
}