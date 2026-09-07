/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:37:41 by syee              #+#    #+#             */
/*   Updated: 2026/09/07 21:47:06 by syee             ###   ########.fr       */
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
