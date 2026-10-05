/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 22:03:35 by syee              #+#    #+#             */
/*   Updated: 2026/09/26 22:58:55 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int match_direction(char dir);
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

int check_map_texture(char *str)
{
	char map_texture[9];
	int i;
	bool flag;
	
	
	ft_printf("Inside check map texture, current map line : %s", str);
	init_map_texture(map_texture);
	
	while (*str != '\n' && *str != '\0')
	{
		i = 0;
		flag = false;
		while (map_texture[i])
		{
			if (*str == map_texture[i])
			{
				//printf("valid char checekd : %c against %c, i : %d\n", *str, map_texture[i], i);
				flag = true;
				break;
			}
			else if (i == 6 && flag == false)
			{
				//printf("invalid char checekd : %c against %c, i : %d", *str, map_texture[i], i);
				return (1);
			}
			i++;
		}
		
		str++;
	}
	return (0);
}



int	feed_map(char map[MAP_SIZE][MAP_SIZE + 1], char *str, t_texture *texture)
{
	static int	row;
	int			col;
	int			map_len;
	
	col = 0;

	printf ("Feeding the map, at row : %d\n", row);

	if (ft_strchr(str, '\n')) //if it has a newline then minus the new line
		map_len = ft_strlen(str) - 1;
	else
		map_len = ft_strlen(str); //this is if it has a null temrinato
		
	if (map_len > MAP_SIZE)
		return (ft_printf("Error : Map too large, Enter a 100x100 size."), 1);
		
	while (*str != '\n' && *str != '\0')
	{
		map[row][col] = *str;
		if (match_direction(str))
		{
			if (!texture->player_x || !texture->player_y)
			{
				texture->player_x = col;
				texture->player_y = row;
			}
			else
				return (ft_printf("Error : Multiple player positions found"), 1);
		}
		str++;
		col++;
	}
	map[row][col] = '\0';
	row++;
	if (!texture->player_x || !texture->player_y)
		return (ft_printf("Error : Player position not included"), 1);
	return (0);
}



int validate_map(char original_map[MAP_SIZE][MAP_SIZE + 1],t_texture *texture)
{
	char map_copy[MAP_SIZE][MAP_SIZE + 1];

	printf ("Inside validate map \n");
	duplicate_map(original_map, map_copy);
	flood_inside_map(texture->player_y, texture->player_y, &map_copy); 
	// if (flood_outside_map(0, 0, &map_copy) == 1) //returns error if it encounteres an i value
	// 	return(ft_printf("Error : walls of map are not closed."), 1);
	int	row;
	int	col;

	row = 0;
	while (row < MAP_SIZE)
	{
		col = 0;
		while (col < MAP_SIZE)
		{
			if (map_copy[row][col] == '\0')
				break ;
			ft_printf("%c", map_copy[row][col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
	return (0);
}

int match_direction(char dir)
{
	char	direction[5];
	int		i;

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