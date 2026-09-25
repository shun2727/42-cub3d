/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:28:19 by syee              #+#    #+#             */
/*   Updated: 2026/09/23 23:25:00 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void read_file_map(int *flag, char *str, t_texture *texture)
{
	int map_flag;
	
	map_flag = BEFORE_MAP_CHECKING;
	if (is_blank_line(str))
	{
		if (map_flag == DURING_MAP_CHECKING) //this is something new, change the state in an if statement
			map_flag = AFTER_MAP_CHECKING;
	}
	else
	{
		if (map_flag == AFTER_MAP_CHECKING)
		{
			ft_printf("Error : lines after map detected\n");
			*flag = MAP_ERROR;
		}
		else
		{
			map_flag = DURING_MAP_CHECKING;
			if (check_map_texture(str) != 0)
			{	
				ft_printf("Error : invalid values found in map :%s", str);
				*flag = MAP_ERROR;
			}

			if (feed_map(texture->map, str, texture) != 0)
				*flag = MAP_ERROR;
			else if ((*str == '\0') || !ft_strchr(str, '\n')) //its at the last line
			{
				if (validate_map(texture->map) == 0)
					*flag = FULFILLED_FILE;
				else
					*flag = MAP_ERROR;
			}
		}
	}
}
