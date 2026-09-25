/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/23 22:47:10 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	struct_print_free_debug(t_texture *texture);
void	free_texture(t_texture *texture);
void	print_map_debug(t_texture *texture);

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
		if (validate_map(texture->map) == 0)
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
		print_map_debug (texture);
		free_texture(texture);
	}
	return (0);
}


void free_texture(t_texture *texture)
{
	//struct_print_free_debug(texture);
	printf("freeing\n");
	free(texture->wall_textures[0]);
	free(texture->wall_textures[1]);
	free(texture->wall_textures[2]);
	free(texture->wall_textures[3]);
	free(texture->floor_ceiling[0]);
	free(texture->floor_ceiling[1]);
}

void	struct_print_free_debug(t_texture *texture)
{
	printf("%s\n", texture->wall_textures[0]);
	printf("%s\n", texture->wall_textures[1]);
	printf("%s\n", texture->wall_textures[2]);
	printf("%s\n", texture->wall_textures[3]);
	printf("%d\n", texture->floor[0]);
	printf("%d\n", texture->floor[1]);
	printf("%d\n", texture->floor[2]);
	printf("%d\n", texture->ceiling[0]);
	printf("%d\n", texture->ceiling[1]);
	printf("%d\n", texture->ceiling[2]);
		
}

void	print_map_debug(t_texture *texture)
{
	int	row;
	int	col;

	row = 0;
	while (row < MAP_SIZE)
	{
		col = 0;
		while (col < MAP_SIZE)
		{
			if (texture->map[row][col] == '\0')
				break ;
			ft_printf("%c", texture->map[row][col]);
			col++;
		}
		ft_printf("\n");
		row++;
	}
}


/*
what id the remaining liens are empty 
*/

/*
goal : feed the stuff into teh map and print it
issues : 
	- the 
*/

			/*
			if (there are new lines)
				skip until it reaches the map section
			else
			{
				flag = CHECKING_MAP_CONTENT;
				//inside this section if it sees a new line, its still considered valid until its being checked
			}
				
				
			*/
			//what if there are new lines 
			//keep reading newlines ()
			//it is a null temrinated strinf right ?