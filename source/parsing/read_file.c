/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/14 14:40:54 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	struct_print_free_debug(t_texture *texture);
void	free_texture(t_texture *texture);
void	print_map_debug(t_texture *texture);

void	print_err(char *str)
{
	ft_printf("Error: %s\n", str);
	return ;
}

bool	is_blank_line(char *str)
{
    if (!str)
        return (false);
    return (ft_strlen(str) == 1 && str[0] == '\n');
}

int	read_file(char *file, t_texture *texture)
{
	int		file_fd;
	int		x;
	int		texture_count;
	char	*texture_compare[7];
	char	*str;
	int		flag;
	
	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (print_err("Unable to open file\n"), -1); //nothing has been initialized so can just quit
	
	init_texture_compare(texture_compare);
	texture_count = 1;
	x = 0;
	flag = CHECKING_FILE_CONTENT;

	str = get_next_line(file_fd);
	if (!str)
			return (print_err("Empty file\n"), -1);;
			
	while (str != NULL)
	{
		if (flag == CHECKING_FILE_CONTENT && texture_count != 1000000)
		{
			
		}
		else if (flag == CHECKING_MAP_CONTENT)
		{

		}
		
		free(str);
		str = get_next_line(file_fd);
	}
	
	close(file_fd);
	//this is specifically for after the part where theres training lines
	if(flag == CHECKING_MAP_CONTENT)//if there are nl only 
	{
		if (validate_map(texture->map) == 0)
			flag = FULFILLED_FILE;
		else
			flag = MAP_ERROR;
	}

	if (flag == TEXTURE_ERROR || flag == MAP_ERROR)
	{
		printf("ERROR\n");
		return (free_texture(texture),  -1);
	}
	else if (flag == FULFILLED_FILE)
	{
		printf("FULFILLED_FILE\n");
		print_map_debug (texture);
		free_texture(texture);
	}
	return (0);
}
int read_file_texture(int flag, char *str)
{
	if (!ft_strchr(str, '\n'))  //prevents from passing in the last line with null terminator to be fed into ft_strdup_nl
	{
		ft_printf("Error : incomplete file\n");
		flag = TEXTURE_ERROR;
	}
	else
	{
		x = feed_texture(str, texture, texture_compare);
		if (x == 1 && ft_strlen(str) != 1) //this if checks for non texture values
		{
			if (check_map_texture(str) == 0)
				print_err("Map initialialized before texture");
			else
				ft_printf("Error : invalid values found in file : %s", str);
			flag = TEXTURE_ERROR;
		}
		else
		{
			texture_count = texture_count * x;
			if ((texture_count == 1000000 && validate_texture(texture) != 0) || texture_count < 0)
				flag = TEXTURE_ERROR;
			else if (texture_count == 1000000 && validate_texture(texture) == 0)
				flag = CHECKING_MAP_CONTENT;
		}
	}
}

int read_file_map(char *str, t_texture *texture, int flag)
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
			flag = MAP_ERROR;
		}
		else
		{
			map_flag = DURING_MAP_CHECKING;
			if (check_map_texture(str) != 0)
			{	
				ft_printf("Error : invalid values found in map :%s", str);
				flag = MAP_ERROR;
			}

			if (feed_map(texture->map, str) != 0)
				flag = MAP_ERROR;
			else if ((*str == '\0') || !ft_strchr(str, '\n')) //its at the last line
			{
				if (validate_map(texture->map) == 0)
					flag = FULFILLED_FILE;
				else
					flag = MAP_ERROR;
			}
		}
	}
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