/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:34:18 by syee              #+#    #+#             */
/*   Updated: 2026/09/23 22:51:18 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void read_file_texture(int *flag, char *str, t_texture *texture, int *texture_count)
{
	char	*texture_compare[7];
	int		x;
	
	init_texture_compare(texture_compare);
	x = feed_texture(str, texture, texture_compare);
	if (!ft_strchr(str, '\n'))  //prevents from passing in the last line with null terminator to be fed into ft_strdup_nl
	{
		ft_printf("Error : incomplete file\n");
		*flag = TEXTURE_ERROR;
	}
	else
	{
		if (x == 1 && ft_strlen(str) != 1) //this if checks for non texture values
		{
			if (check_map_texture(str) == 0)
				print_err("Map initialialized before texture");
			else
				ft_printf("Error : invalid values found in file : %s", str);
			*flag = TEXTURE_ERROR;
		}
		else
		{
			*texture_count = *texture_count * x;
			if ((*texture_count == 1000000 && validate_texture(texture) != 0) || *texture_count < 0)
				*flag = TEXTURE_ERROR;
			else if (*texture_count == 1000000 && validate_texture(texture) == 0)
				*flag = CHECKING_MAP_CONTENT;
		}
	}
}

