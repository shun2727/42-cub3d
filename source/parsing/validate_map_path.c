/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:32:03 by syee              #+#    #+#             */
/*   Updated: 2026/09/26 22:51:04 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


/**
* duplicates map
* @param original_map 
* @param map_copy pointer to the copy of the map
* @return void
*/
void duplicate_map (char original_map[MAP_SIZE][MAP_SIZE + 1], char *map_copy[MAP_SIZE][MAP_SIZE + 1])
{
	int row;
	int col;

	row = 0;
	while (row < MAP_SIZE)
	{
		col = 0;
		while (col < MAP_SIZE + 1)
		{
			*map_copy[row][col] = original_map[row][col];
			col++;
		}
		row++;
	}
}


void flood_inside_map (int row, int col, char *map[MAP_SIZE][MAP_SIZE + 1]) //the map here is the copied map, using floodfil 
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
* floods the outside of the map with 'o', will be called recursively.
* starts with (0,0) as the top left corner of the map
* @param row
* @param col 
* @param map 
* @return 1 on error, 0 on success
*/
int flood_outside_map(int row, int col, char *map[MAP_SIZE][MAP_SIZE + 1])
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