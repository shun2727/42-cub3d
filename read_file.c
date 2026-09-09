/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/09 18:56:41 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	struct_print_free_debug(t_texture *texture);
void *validate_texture(t_texture *texture);

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
		if (texture_count < 1)
		{
			//free(str);
			//call cleanup
		}
		
		if (texture_count != 1000000)
		{
			ft_printf("Error: incomplete textures\n");
			//call cleanup
		}
		
		//validate_texture
		//feed_map		
		printf("texture count : %d\n", texture_count);
		free(str);
		str = get_next_line(file_fd);
	}
	//validate_texture(texture);
	struct_print_free_debug(texture);
	return(NULL);
}

//need to use mlx here 
void	*validate_texture(t_texture *texture)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		//check .xpm
		if (!ft_rstrstr(".xpm", texture->wall_textures[i], 4))
			return(ft_printf("Error: invalid file type for %s\n", texture->wall_textures[i]), 1);

		//check if can open
		if (open(texture->wall_textures[i], O_RDONLY) == -1)
			return(ft_printf("Error: invalid file type for %s\n", texture->wall_textures[i]), 1);
		i++;
	}
	
	while (i < 3)
	{
		ft_strchr(texture->wall_textures[F], ',');

	}
	//file for wall textures invalid
	//can file be opened
	//can file be converted to xpm 
	//can file be displayed in mlx window
	
	//check if .xpm
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