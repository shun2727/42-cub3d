/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 23:47:58 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_file(char *file, t_texture *texture)
{
	int		file_fd; //need 
	int		texture_count; //need here, becuase want ot prevent it from resetting
	char	*str;
	int		flag;
	
	texture_count = 1;
	flag = CHECKING_FILE_TEXTURE;
	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (print_err("Unable to open file\n"), -1); //nothing has been initialized so can just quit
	str = get_next_line(file_fd);
	if (!str)
			return (print_err("Empty file\n"), -1);;			
	while (str != NULL)
	{
		if (flag == CHECKING_FILE_TEXTURE)
			read_file_texture(&flag, str, texture, &texture_count);
		else if (flag == CHECKING_MAP_CONTENT)
			read_file_map(&flag, str, texture);
			
		free(str);
		str = get_next_line(file_fd);
	}
	close(file_fd);
	return(flag_check(&flag, texture));
}

int	flag_check(int *flag, t_texture *texture)
{
	//this is specifically for after the part where theres training lines
	if(*flag == CHECKING_MAP_CONTENT)//if there are nl only 
	{
		if (validate_map(&texture->map, texture) == 0)
			*flag = FULFILLED_FILE;
		else
			*flag = MAP_ERROR;
	}

	if (*flag == TEXTURE_ERROR || *flag == MAP_ERROR)
	{
		printf("ERROR\n");
		return (free_texture(texture),  -1);
	}
	else if (*flag == FULFILLED_FILE)
	{
		printf("FULFILLED_FILE\n");

		free_texture(texture);
	}
	return (0);
}



