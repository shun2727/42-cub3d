/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/09 12:09:48 by syee             ###   ########.fr       */
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
	t_texture_enum	texture_enum;
	int				i;

	while (i < 7)
	{
		if (i < 4 && (ft_strnstr(str, texture_compare[i], 3)))
		{
			if (texture->wall_textures[i])
				return (ft_printf("Dupilcated texture"), 1); //add a clean all funciton
			else
				texture->wall_textures[i]= ft_strdup_nl(str + 3);
		}
		else if (i > 3 && (ft_strnstr(str, texture_compare[i], 2)))
		{
			if (texture->wall_textures[i])
				return (ft_printf("Dupilcated texture"), 1); //add a clean all funciton
			else
				texture->wall_textures[i - 4] = ft_strdup_nl(str + 3);
		}
		i++;
	}
	return (0);
}

char *read_file(char *file, t_texture *texture)
{
	int		file_fd;
	char	*texture_compare[7];
	char	*str;
	char	*pointer;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (print_err("Unable to open file\n"), NULL); //nothing has been initialized so can just quit
	
	init_texture_compare(texture_compare);
	str = get_next_line(file_fd);
	while (str != NULL)
	{
		if (feed_texture(str, texture, texture_compare) != 0)
		{
			printf("Texture compare error\n");
			//free(str);
			//free_all(struct only) & exit
		}
		//validate_texture
		//feed_map		
		free(str);
		str = get_next_line(file_fd);
	}
	//validate_texture(texture);
	struct_print_free_debug(texture);
	return(NULL);
}



/*
declare a str arr and store it inside, do while if true, get the array index and assign it to the array inside the struct
, if the array is already assigned then quit saying its duplicate 
*/



//need to use mlx here 
void *validate_texture(t_texture *texture)
{
	int texture_fd;
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