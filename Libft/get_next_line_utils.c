/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:29:44 by syee              #+#    #+#             */
/*   Updated: 2025/06/20 20:23:53 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*returnpoint;

	returnpoint = (char *)s;
	while (*returnpoint)
	{
		if (*returnpoint == (char)c)
			return (returnpoint);
		returnpoint++;
	}
	if (c == '\0')
		return (returnpoint);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

char	*ft_strdup(const char *src)
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

char	*ft_strjoin(char *staticbuffer, char *buffer)
{
	char	*newstr;
	int		len_staticbuf;
	int		len_buffer;

	len_buffer = ft_strlen(buffer);
	if (!staticbuffer && *buffer)
	{
		newstr = ft_strdup(buffer);
		return (newstr);
	}
	len_staticbuf = ft_strlen(staticbuffer);
	newstr = (char *)malloc(len_staticbuf + len_buffer + 1);
	if (!newstr)
	{
		free(buffer);
		return (NULL);
	}
	ft_memcpy (newstr, staticbuffer, len_staticbuf);
	ft_memcpy (newstr + len_staticbuf, buffer, len_buffer);
	free (staticbuffer);
	newstr[len_staticbuf + len_buffer] = '\0';
	return (newstr);
}
