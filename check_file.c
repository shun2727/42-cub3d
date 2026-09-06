/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:01:04 by syee              #+#    #+#             */
/*   Updated: 2026/09/06 20:52:23 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <string.h>
#include <stdio.h>
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

int main(int argc, char **argv)
{
	if (charcount('.', "argv[1]") > 0 || !(ft_rstrstr(".cub", argv[1], 4)))
	{
		//return error	
	}
	
}