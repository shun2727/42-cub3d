/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:17:08 by syee              #+#    #+#             */
/*   Updated: 2025/05/20 19:17:10 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdest;

	tempdest = (unsigned char *) dest;
	tempsrc = (unsigned char *) src;
	if (dest == src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		while (n-- > 0)
			*(tempdest++) = *(tempsrc++);
	}
	else
	{
		while (n-- > 0)
			tempdest[n] = tempsrc[n];
	}
	return (dest);
}
//wanted to make a temp var that can store the src but there is still possibily
// of the dest overlapping, can only be done if its using malloc
//other solution is to copy byte by byte in the right direction, if its in the 
