/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:00:13 by syee              #+#    #+#             */
/*   Updated: 2026/10/16 20:14:05 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "render.h"

int main(int argc, char **argv)
{
	t_texture	texture;
	
	texture = (t_texture){0};
	
	if (argc != 2 || chr_count('.', "argv[1]") > 0 || !(ft_rstrstr(".cub", argv[1], 4)))
		return (ft_printf("Invalid file type"), 1);
		
	if (read_file(argv[1], &texture) == -1)
		return (1);
	
	render(&texture);
	
	return (0);
}