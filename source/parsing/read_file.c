/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/12 02:00:23 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	struct_print_free_debug(t_texture *texture);
void free_texture(t_texture *texture);

void	print_err(char *str)
{
	ft_printf("Error: %s\n", str);
	return ;
}


void init_map_texture(char map_texture[8])
{
	map_texture[0] = "0";
	map_texture[1] = "1";
	map_texture[2] = "N";
	map_texture[3] = "S";
	map_texture[4] = "E";
	map_texture[5] = "W";
	map_texture[6] = " ";
	map_texture[7] = "\0";
}

int check_map_texture(char *str)
{
	char map_texture[9];
	int i;
	
	init_map_texture(map_texture);
	
	while (*str != '\0' || *str != '\n')
	{
		i = 0;
		while (map_texture[i])
		{
			if (*str != map_texture[i])
				return (1);
			str++;
		}
	}
	return (0);
}


int	feed_map(char map[MAP_SIZE][MAP_SIZE], char *str)
{
	static int	row;
	int			col;
	int			map_len;
	
	col = 0;
	if (check_map_texture(str) != 0)
		return (ft_printf("Error : invalid values found in map : %s", str), 1);
		
	printf ("feeding the map, row %d\n", row);
	if (ft_strchr(str, '\n'))
		map_len = ft_strlen(str) - 1;
	else
		map_len = ft_strlen(str);
		
	if (map_len > MAP_SIZE)
		return (ft_printf("Error : Map too large, Enter a 100x100 size."), 1);
	while (*str != '\n' || *str != '\n')
	{
		map[row][col] = *str;
		str++;
		col++;
	}
	row++;
	return (0);
}

int validate_map(char map[MAP_SIZE][MAP_SIZE])
{
	printf ("Inside validate map, Map is valid \n");
	//flood fill
	return (0);
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
	flag = UNCHECK_UNFULFILLED;
	
	str = get_next_line(file_fd);
	while (str != NULL)
	{
		if (flag == UNCHECK_UNFULFILLED && texture_count != 1000000) //prevents from passing in the last line with null terminator to be fed into ft_strdup_nl
		{
			if (!ft_strchr(str, '\n'))
			{
				ft_printf("Error : incomplete file\n");
				flag = CHECKED_UNFULFILLED;
			}
			else
			{
				x = feed_texture(str, texture, texture_compare);
				if (x == 1 && ft_strlen(str) != 1)
				{
					if (check_map_texture(str) == 0)
						print_err("Map initialialized before texture");
					else
						ft_printf("Error : invalid values found in file : %s", str);
					flag = CHECKED_UNFULFILLED;
				}
				else
				{
					texture_count = texture_count * x;
					if ((texture_count == 1000000 && validate_texture(texture) != 0) || texture_count < 0)
						flag = CHECKED_UNFULFILLED;
				}
			}
		}
		else if (flag == UNCHECK_UNFULFILLED)
		{
			feed_map(texture->map, str); //theres a chance of garbage values wihtin the map
			if (ft_strchr(str, '\0') && validate_map(texture->map))
				flag = FULFILLED;
		}
		free(str);
		str = get_next_line(file_fd);
	}
	
	close(file_fd);
	if (flag == CHECKED_UNFULFILLED)
	{
		printf("CHECKED_UNFULFILLED\n");
		return (free_texture(texture),  -1);
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

