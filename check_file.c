/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:01:04 by syee              #+#    #+#             */
/*   Updated: 2026/09/08 14:05:10 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <string.h>
#include <stdio.h>
#include "cub3D.h"
/*
checks for needle in reverse created for cub3D for ".cub" only
exits as soon as it doesnt match
*/
int charcount(char needle, char *haystack)
{
	int	count;

	count = 0;
	while (*haystack != '\0')
	{
		if (*haystack == needle)
			count++;
		haystack++;
	}
	return(count);
}

char *ft_rstrstr(char *needle, char *haystack, int needlen)
{
	int haystacklen;
	int i;

	haystacklen = (strlen(haystack) - 1);
	if (haystacklen < needlen - 1)
		return (NULL);
	i = needlen - 1;
	while (needle[i--] == haystack[haystacklen--])
	{
		if (i == -1)
			return(haystack + haystacklen + 1);
	}
	return (NULL);
}
int hook_close_window(int keycode, t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	return (0);
}

int main(int argc, char **argv)
{
	t_texture	texture;
	t_window	window;
	
	texture = (t_texture){0};
	
	if (argc != 2 || charcount('.', "argv[1]") > 0 || !(ft_rstrstr(".cub", argv[1], 4)))
		return (perror("Invalid file type"), 1);
	
	//all the textures are loaded inside
	read_file(argv[1], &texture);
	
	//after reading file then only open window
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 1920, 1080, "cub3D");
	mlx_hook(window.mlx_win, 17, 0, hook_close_window, &window);
	mlx_loop(window.mlx);

	return (0);
}