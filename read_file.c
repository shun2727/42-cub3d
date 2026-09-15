/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/10 18:45:29 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	struct_print_free_debug(t_texture *texture);
int	validate_texture(t_texture *texture);

void	print_err(char *str)
{
	ft_printf("%s\n", str);
	return ;
}
char	*ft_strdup_nl(const char *src)
{
	size_t	i;
	char	*dest;
	char	*desttemp;

	i = 0;
	while (src[i] != '\n')
		i++;
	dest = (char *) malloc (i + 1);
	if (!dest)
		return (NULL);
	desttemp = dest;
	while (i-- > 0)
		*desttemp++ = *src++;
	*desttemp = '\0';
	return (dest);
}
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

char *read_file(char *file, t_texture *texture)
{
	int		file_fd;
	int		texture_count;
	char	*texture_compare[7];
	char	*str;
	char	*pointer;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (print_err("Unable to open file\n"), NULL); //nothing has been initialized so can just quit
	
	init_texture_compare(texture_compare);
	texture_count = 1;
	
	str = get_next_line(file_fd);
	

	while (str != NULL)
	{
		texture_count = texture_count * feed_texture(str, texture, texture_compare);
		//this test will run every turn
		if (texture_count != 1000000 && !ft_strchr(str, '\n'))
		{
			//ft_printf("Error: incomplete textures\n");
		}
		if (texture_count < 1)
		{
			//free(str);
			//call cleanup
		}
		//if read until the following chars and the texture is not 1000000
		if (texture_count != 1000000)
		{
			//ft_printf("Error: incomplete textures\n");
			//call cleanup
		}
		else if (texture_count == 1000000)
		{
			if (validate_texture(texture) != 0)
			{
				//free
				//exit
			}
		}
		
		
		//feed_map		
		free(str);
		str = get_next_line(file_fd);
	}
	printf("texture count : %d\n", texture_count);
	close(file_fd);
	//validate_texture(texture);
	struct_print_free_debug(texture);
	return(NULL);
}

//will free the string after use
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
		return (free(str), -1);
	while (i < len)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			result = (result * 10) + (str[i] - '0');
		else
			return (free(str), -1);
		i++;
	}
	if (result > 255)
		return (free(str), -1);
	return (free(str), result);
}


//need to use mlx here 
int	assign_value(int arr[3], char *str)
{
	int i;
	
	i = 0;
	if (charcount(',', str) != 2 || ft_strlen(str) > 11 || ft_strlen(str) < 5)
		return (1);

	char *first_comma;
	char *second_comma;
	first_comma = ft_strchr(str, ',');
	second_comma = ft_strchr(first_comma++, ',');
	
	
	arr[0] = extract_int(str, str, first_comma);
	arr[1] = ft_strchr_n(str, ',');
	arr[2] = ft_atoi
	//convert 
	//check
	//assign
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
	if (assign_value(texture->floor, texture->floor_ceiling[1]) != 0 || assign_value(texture->ceiling, texture->floor_ceiling[2]) != 0)
		return (ft_printf("Error: invalid RGB values %s\n"), 1);
	return (0);
}

void	struct_print_free_debug(t_texture *texture)
{
	printf("%s\n", texture->wall_textures[0]);
	printf("%s\n", texture->wall_textures[1]);
	printf("%s\n", texture->wall_textures[2]);
	printf("%s\n", texture->wall_textures[3]);
	printf("%s\n", texture->floor_ceiling[0]);
	printf("%s\n", texture->floor_ceiling[1]);
	

	free(texture->wall_textures[0]);
	free(texture->wall_textures[1]);
	free(texture->wall_textures[2]);
	free(texture->wall_textures[3]);
	free(texture->floor_ceiling[0]);
	free(texture->floor_ceiling[1]);
}