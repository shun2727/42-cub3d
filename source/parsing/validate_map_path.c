/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:32:03 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 13:37:50 by syee             ###   ########.fr       */
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


void flood_inside_map (int row, int col, char *map[MAP_SIZE][MAP_SIZE]) //the map here is the copied map, using floodfil 
{
	
	if (*map[row][col + 1] == '0') //front, check for '\0'
	{
		*map[row][col + 1] = 'i';
		if (map[row][col + 2]) //if its not '\0' 
			flood_inside_map(row, col + 2, map);
	}
	if (*map[row][col - 1] == '0') //back check if col == 0
	{
		*map[row][col - 1] = 'i';
		if (col - 2 >= 0 )
			flood_inside_map(row, col - 2, map);
	}
	if (*map[row + 1][col] == '0') //down check if row 
	{
		*map[row + 1][col] = 'i';
		if (row + 2 <= MAP_SIZE)
			flood_inside_map(row + 2, col, map);
	}
	if (*map[row - 1][col] == '0') //up
	{
		*map[row - 1][col] = 'i';
		if (row - 2 >= 0)
			flood_inside_map(row - 2, col, map);
	}
}


/**
* @brief floods the outside of the map with 'o', will be called recursively.
* starts with (0,0) as the top left corner of the map
* @param row
* @param col 
* @param map 
* @return void, does not return anything on success or failure and merely fills the map
*/
int flood_outside_map(int row, int col, char (*map)[MAP_SIZE][MAP_SIZE])
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