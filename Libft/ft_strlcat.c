/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:33:47 by syee              #+#    #+#             */
/*   Updated: 2025/05/22 17:33:50 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	while (i < (dstsize - 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}

/*int main (void)
{
	char dest[10];
	char *src = "hello";
	printf("3hello ");
	printf("%ld",ft_strlcat(dest,src,10));
}*/
