/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:32:03 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 20:34:05 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


/**
 * @brief Duplicates map, accepts the original map and pointer to the map_copy
 * 
 * @param original_map 
 * @param map_copy 
 */
void duplicate_map (char original_map[MAP_SIZE][MAP_SIZE], char (*map_copy)[MAP_SIZE][MAP_SIZE])
{
	int row;
	int col;

	row = 0;
	while (row < MAP_SIZE)
	{
		col = 0;
		while (col < MAP_SIZE) //here ?
		{
			(*map_copy)[row][col] = original_map[row][col];
			col++;
		}
		row++;
	}
}

/**
 * @brief fills from the pleyer's front, cannot fill from its current spot
 * 
 * @param row 
 * @param col 
 * @param map 
 * @return int 
 */

/*
check if the current position is the first player position given denoted by an argument passed ? 
*/
bool is_inside(int row, int col, char map[MAP_SIZE][MAP_SIZE])
{
	if (map[row][col] == '0' || map[row][col] == ' ')
		return (true);
	return (false);
}

int is_outside(int row, int col, char map[MAP_SIZE][MAP_SIZE])
{
	if (map[row][col] == 'o')
		return (true);
	return (false);
}

int flood_inside_map (int row, int col, char (*map)[MAP_SIZE][MAP_SIZE])
{
	static int flag;
	
	if (flag == 1)
		return (printf("flag is %d",flag), flag);
		
	if (col + 1 < MAP_SIZE) //checks front
	{
		
		if (is_inside(row, col + 1, *map))
		{
			(*map)[row][col + 1] =  'i';
			flag = flood_inside_map(row, col + 1, map);
		}
		if (is_outside(row, col + 1, *map))
		{
			printf(" col+ 1 : col = %d row : %d %c \n", col + 1 ,row ,(*map)[row][col + 1]);	
			return (1);
		}
	}
	if (col - 1 >= 0)
	{
	
		if (is_inside(row, col - 1, *map))
		{
			(*map)[row][col - 1] =  'i';
			flag = flood_inside_map(row, col - 1, map);
		}
		if (is_outside(row, col - 1, *map))
		{
			printf(" col -1 : col = %d row : %d %c \n", col - 1 ,row ,(*map)[row][col - 1]);
			return (1);
		}
	}
	if (row + 1 < MAP_SIZE) //down
	{
		
		if (is_inside(row + 1, col, *map))
		{
			(*map)[row + 1][col] =  'i';
			flag = flood_inside_map(row + 1, col, map);
		}
		if (is_outside(row + 1, col, *map))
		{
			printf(" row + 1 : col = %d row : %d %c \n", col ,row +1 ,(*map)[row + 1][col]);
			return (1);
		}
	}
	if (row - 1 >= 0) //up
	{
		
		if (is_inside(row - 1, col, *map))
		{
			(*map)[row - 1][col] =  'i';
			flag = flood_inside_map(row - 1, col, map);
		}
		if (is_outside(row - 1, col, *map))
		{
			printf(" row - 1 : col = %d row : %d %c \n", col ,row -1 ,(*map)[row - 1][col]);
			return (1);
		}
	}
	return (flag);
}

void flood_outside_map(int row, int col, char (*map)[MAP_SIZE][MAP_SIZE])
{
	if ((*map)[row][col] == '\0') //fill current visited
		(*map)[row][col] = 'o';
	if ((col + 1 < MAP_SIZE) &&(*map)[row][col + 1] == '\0') //checks front
		flood_outside_map(row, col + 1, map);
	if ((col - 1 >= 0) &&(*map)[row][col - 1] == '\0') //checks bac
		flood_outside_map(row, col - 1, map);
	if ((row + 1 < MAP_SIZE) && (*map)[row + 1][col] == '\0') //check down
		flood_outside_map(row + 1, col, map);
	if ((row - 1 >= 0) && (*map)[row - 1][col] == '\0') //checks up
		flood_outside_map(row - 1, col, map);
}

/*
it was brace initialized so cant check using null terminators and cn only with map size 
*/