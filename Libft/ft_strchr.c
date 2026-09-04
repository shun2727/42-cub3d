/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:37:41 by syee              #+#    #+#             */
/*   Updated: 2025/05/21 13:37:41 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*returnpoint;

	returnpoint = (char *)s;
	if ((char)c == '\0')
	{
		while (*returnpoint)
			returnpoint++;
		return (returnpoint);
	}
	else
	{
		while (*returnpoint)
		{
			if (*returnpoint == (char)c)
				return (returnpoint);
			returnpoint++;
		}
		return (NULL);
	}
}
/*int main (void)
{
    printf("the char is at :%c",*(ft_strchr("abide",'d')));
}*/
//why int is used, char values are promoted to int ,to distinguish all 
//unsigned char values , lowest 8 bits are used
