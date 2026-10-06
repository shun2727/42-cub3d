/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 22:03:35 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 10:17:50 by syee             ###   ########.fr       */
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


/**
 * @brief pass in the original map, the line to be fed into the map, and the textures
 * 
 * @param map
 * @param str 
 * @param texture 
 * @return int 
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
	
	/*
	row is 0 
	will go to 99 when 100x100
	but now 102x102
	102-2 = 100
	still 0 to 99 , if reaches 100 then its extra
	*/
	if (map_len >= MAP_SIZE - 2  || row >= MAP_SIZE - 2)
		return (ft_printf("Error : Map too large, Enter a 100x100 size."), 1);
		
	while (*str != '\n' && *str != '\0')
	{
		(*map)[row + 1][col + 1] = *str;
		//map can be printed here but its not reflecting on the actual map 
		printf("row : %d col : %d char : %c \n", row+1, col+1, *str);
		if (match_direction(*str))
		{
			
			if (texture->player_x == 0 || texture->player_y == 0)
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
	
	row++;

	return (0);
}


//this functions contains references of functions in validate_map_path.c
int validate_map(char original_map[MAP_SIZE][MAP_SIZE],t_texture *texture)
{
	char map_copy[MAP_SIZE][MAP_SIZE];

	printf ("Inside validate map \n");
	if (texture->player_x == 0 || texture->player_y == 0)
	{
		ft_printf("match direction %d %d",texture->player_x, texture->player_y );
		return (ft_printf("Error : Player position not included"), 1);
	}
	//duplicate_map(original_map, &map_copy);
	
	//flood_outside_map(0, 0, &map_copy);
	
	//print_map_debug(map_copy); //works
	
	//flood_inside_map(texture->player_y, texture->player_y, &map_copy); 
	//if (flood_outside_map(0, 0, &map_copy) == 1) //returns error if it encounteres an i value
	// 	return(ft_printf("Error : walls of map are not closed."), 1);
	
	return (0);
}

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