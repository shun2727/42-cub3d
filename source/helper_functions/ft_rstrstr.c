/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:07:03 by syee              #+#    #+#             */
/*   Updated: 2026/09/11 17:14:44 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
checks for string (needle) in reverse created for cub3D for file extention
chekcing such as ".cub" & ".xpm" only
exits as soon as it doesnt match
*/
char *ft_rstrstr(char *needle, char *haystack, int needlen)
{
	int haystacklen;
	int i;

	haystacklen = (ft_strlen(haystack) - 1);
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
