/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:55:01 by syee              #+#    #+#             */
/*   Updated: 2026/09/11 17:05:03 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_texture_compare(char **texture_compare)
{
	texture_compare[NO] = "NO ";
	texture_compare[SO] = "SO ";
	texture_compare[EA] = "EA ";
	texture_compare[WE] = "WE ";
	texture_compare[F] = "F ";
	texture_compare[C] = "C ";
}

int	feed_texture(char *str, t_texture *texture, char **texture_compare)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i < 4 && (ft_strnstr(str, texture_compare[i], 3)))
		{
			if (texture->wall_textures[i])
				return (ft_printf("Error: Dupilcated texture %s\n", texture_compare[i]), -1);
			else
				texture->wall_textures[i] = ft_strdup_nl(str + 3);
			return (10);
		}
		else if (i > 3 && (ft_strnstr(str, texture_compare[i], 2)))
		{
			if (texture->floor_ceiling[i - 4])
				return (ft_printf("Error: Dupilcated texture %s\n", texture_compare[i]), -1);
			else
				texture->floor_ceiling[i - 4] = ft_strdup_nl(str + 2);
			return (10);
		}
		i++;
	}
	return (1);
}

int	validate_texture(t_texture *texture)
{
	int	i;
	int	file_fd;

	i = 0;
	while (i < 4)
	{
		if (!ft_rstrstr(".xpm", texture->wall_textures[i], 4))
			return (ft_printf("Error: invalid file type for %s\n", texture->wall_textures[i]), 1);
		file_fd = open(texture->wall_textures[i], O_RDONLY);
		if (file_fd == -1)
			return (ft_printf("Error: file cannot be opened for %s\n", texture->wall_textures[i]), close(file_fd), 1);
		close(file_fd);
		i++;
	}
	if (assign_value(texture->floor, texture->floor_ceiling[0]) != 0 || assign_value(texture->ceiling, texture->floor_ceiling[1]) != 0)
		return (ft_printf("Error: invalid RGB values\n"), 1);
	return (0);
}

/*
extracts and comverts the strings into int while filtering values over and under 255
*/
int	extract_int(char *str, char *start, char *end)
{
	int	i;
	int	result;
	int len;

	i = 0;
	result = 0;
	len = 0;
	while (start != end)
	{
		start++;
		len++;
	}
	if (len == 0)
		return (-1);
	while (i < len)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			result = (result * 10) + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	if (result > 255)
		return (-1);
	return (result);
}

/*
doing it modularly by recording the start and end of fthe commas introduces more lines
therefore it was made to a more static and hardoded approach 
*/
int	assign_value(int arr[3], char *str)
{
	int i;
	char *first_comma;
	char *second_comma;
	
	if (chr_count(',', str) != 2 || ft_strlen(str) > 11 || ft_strlen(str) < 5)
		return (1);
	first_comma = ft_strchr(str, ',');
	second_comma = ft_strchr(first_comma + 1, ',');
	arr[0] = extract_int(str, str, first_comma);
	arr[1] = extract_int(first_comma + 1, first_comma + 1, second_comma);
	arr[2] = extract_int(second_comma + 1, second_comma + 1, ft_strchr(str, '\0'));
	i = 0;
	while (i < 3)
	{
		if (arr[i] == -1)
			return (1);
		i++;
	}
	return (0);
}

