/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:27:24 by syee              #+#    #+#             */
/*   Updated: 2026/09/08 23:07:02 by syee             ###   ########.fr       */
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

char *read_file(char *file, t_texture *texture)
{
	int		file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (print_err("Unable to open file\n"), NULL);
		
	char *str;
	char *pointer;

	str = get_next_line(file_fd);
	while (str != NULL)
	{
		//need to add a line here to check fo duplicate reassignment
		if (ft_strnstr(str, "NO ", 3) && !texture->no)
			texture->no = ft_strdup_nl(str + 3);
		else if (ft_strnstr(str, "SO ", 3) && !texture->so)
			texture->so = ft_strdup_nl(str + 3);
		else if (ft_strnstr(str, "WE ", 3) && !texture->we)
			texture->we = ft_strdup_nl(str + 3);
		else if (ft_strnstr(str, "EA ", 3) && !texture->ea)
			texture->ea = ft_strdup_nl(str + 3);
		else if (ft_strnstr(str, "F ", 3) && !texture->f)
			texture->f = ft_strdup_nl(str + 2);
		else if (ft_strnstr(str, "C ", 3) && !texture->c)
			texture->c = ft_strdup_nl(str + 2);
		else if (ft_strnstr(str, "NO ", 3) || ft_strnstr(str, "SO ", 3) || 
			ft_strnstr(str, "WE ", 3) || ft_strnstr(str, "WE ", 3) ||
			ft_strnstr(str, "F ", 3) || ft_strnstr(str, "C ", 3))
		{
			//PRINT "duplicate input"
			//free and quit 
		}
			
		free(str);
		str = get_next_line(file_fd);
	}
	//struct_print_free_debug(texture);
	validate_texture(texture);
	return(NULL);
}

	char			*texture_compare[7];
	texture_compare[NO] = "NO ";
	texture_compare[SO] = "SO ";
	texture_compare[EA] = "EA ";
	texture_compare[WE] = "WE ";
	texture_compare[F] = "F ";
	texture_compare[C] = "C ";

int function(char *str, t_texture *texture, char **texture_compare)
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
				texture->wall_textures[i]= ft_strdup_nl(str + 3);
		}
		i++;
	}

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

	//check if can open
	texture_fd = open(texture->no, O_RDONLY);
	if (texture_fd == -1)
	{
		close(texture_fd);
		return(print_err("Invalid file for wall texture\n"), NULL);
	}
	printf("%s\n", texture->no);
}
void	struct_print_free_debug(t_texture *texture)
{
	printf("%s\n", texture->no);
	printf("%s\n", texture->so);
	printf("%s\n", texture->we);
	printf("%s\n", texture->ea);
	printf("%s\n", texture->f);
	printf("%s\n", texture->c);

	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	free(texture->f);
	free(texture->c);
}