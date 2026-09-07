/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:00:13 by syee              #+#    #+#             */
/*   Updated: 2026/09/07 21:52:19 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int main(int argc, char **argv)
// {
// 	int filenum;
// 	char **path;
	
// 	printf("%s\n", argv[1]);
// 	//filenum = open(path, O_RDONLY);
// 	/*
// 	1. open the file 
// 		- handle open file error 
// 	2. read the file 
// 		- file rules :
// 			- must be .cub extension (using strchr to get if values after . is cub)
// 			- map must be composed of 
// 				- 0 for empty
// 				- 1 for wall
// 				- NSWE for player's star position and spawninf orentation
// 				- > use get_next_line to check lines one by one?
// 			- must be closed by walls (1) 
// 				- > flood fill? figure out the algorithm to check if walls are close
// 		- from the subject pdf, there can be other elements within the file
// 			- NO , SO , WE , EA , F, C followed by location to texture
// 		- if the paths to the texture and the colors to the F and C are invalid, print an error message
// 	3. Pass the map to execution
// 		- how does execution read or use the map ?
// 	*/
// }