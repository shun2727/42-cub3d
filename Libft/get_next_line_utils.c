/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:29:44 by syee              #+#    #+#             */
/*   Updated: 2026/09/07 21:50:34 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdest;

	tempdest = (unsigned char *) dest;
	tempsrc = (unsigned char *) src;
	if (!tempsrc && !tempdest)
		return (dest);
	while (n-- > 0)
		*(tempdest++) = *(tempsrc++);
	return (dest);
}

char	*gnl_strdup(const char *src)
{
	size_t	i;
	char	*dest;
	char	*desttemp;

	i = 0;
	while (src[i])
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
//rewritten as staticbuffer and buffer for clerer understanding 
//if static buffer is empty, n theres stuff in buffer means that its first loop
//wanted to free the given values, after joining them 

char	*gnl_strjoin(char *staticbuffer, char *buffer)
{
	char	*newstr;
	int		len_staticbuf;
	int		len_buffer;

	len_buffer = ft_strlen(buffer);
	if (!staticbuffer && *buffer)
	{
		newstr = gnl_strdup(buffer);
		return (newstr);
	}
	len_staticbuf = ft_strlen(staticbuffer);
	newstr = (char *)malloc(len_staticbuf + len_buffer + 1);
	if (!newstr)
	{
		free(buffer);
		return (NULL);
	}
	gnl_memcpy (newstr, staticbuffer, len_staticbuf);
	gnl_memcpy (newstr + len_staticbuf, buffer, len_buffer);
	free (staticbuffer);
	newstr[len_staticbuf + len_buffer] = '\0';
	return (newstr);
}
