/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:32:03 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 23:39:40 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dup_map(char ori_map[MAP_SIZE][MAP_SIZE], char (*map_copy)[MAP_SIZE][MAP_SIZE])
{
	int row;
	int col;

	row = 0;
	while (row < MAP_SIZE)
	{
		col = 0;
		while (col < MAP_SIZE)
		{
			(*map_copy)[row][col] = ori_map[row][col];
			col++;
		}
		row++;
	}
}

bool is_inside(int row, int col, char map[MAP_SIZE][MAP_SIZE])
{
	if (map[row][col] == '0' || map[row][col] == ' ')
		return (true);
	return (false);
}

bool is_outside(int row, int col, char map[MAP_SIZE][MAP_SIZE])
{
	if (map[row][col] == 'o' || map[row][col] == '\0')
		return (true);
	return (false);
}
/**
 * @brief Recursively floods the inside of the map
 * 
 * @param row 
 * @param col 
 * @param map
 * @param fill The character to fill the map with, used so that it can pad whitespaces in 
 * the original map with '0', this reduces the need to create a new map
 * @return 0 on success, 1 on failure
 */
int flood_inside_map (int row, int col, char (*map)[MAP_SIZE][MAP_SIZE])
{
	static int flag;
	
	if (flag == 1)
		return (flag);
	if (col + 1 < MAP_SIZE) //checks front
	{
		if (is_inside(row, col + 1, *map))
		{
			(*map)[row][col + 1] =  'i';
			flag = flood_inside_map(row, col + 1, map);
		}
		if (is_outside(row, col + 1, *map))
			return (1);
	}
	if (col - 1 >= 0)
	{
		if (is_inside(row, col - 1, *map))
		{
			(*map)[row][col - 1] = 'i';
			flag = flood_inside_map(row, col - 1, map);
		}
		if (is_outside(row, col - 1, *map))
			return (1);
	}
	if (row + 1 < MAP_SIZE) //down
	{
		if (is_inside(row + 1, col, *map))
		{
			(*map)[row + 1][col] = 'i';
			flag = flood_inside_map(row + 1, col, map);
		}
		if (is_outside(row + 1, col, *map))
			return (1);
	}
	if (row - 1 >= 0)
	{		
		if (is_inside(row - 1, col, *map))
		{
			(*map)[row - 1][col] = 'i';
			flag = flood_inside_map(row - 1, col, map);
		}
		if (is_outside(row - 1, col, *map))
			return (1);
	}
	return (flag);
}

/**
 * @brief explanaiton on the map, fills current visited, 
 * then checks and passes coordinates front, back, down, up
 * 
 * @param row 
 * @param col 
 */
void flood_outside_map(int row, int col, char (*map)[MAP_SIZE][MAP_SIZE])
{
	if ((*map)[row][col] == '\0')
		(*map)[row][col] = 'o';
	if ((col + 1 < MAP_SIZE) &&(*map)[row][col + 1] == '\0')
		flood_outside_map(row, col + 1, map);
	if ((col - 1 >= 0) &&(*map)[row][col - 1] == '\0')
		flood_outside_map(row, col - 1, map);
	if ((row + 1 < MAP_SIZE) && (*map)[row + 1][col] == '\0')
		flood_outside_map(row + 1, col, map);
	if ((row - 1 >= 0) && (*map)[row - 1][col] == '\0')
		flood_outside_map(row - 1, col, map);
}
