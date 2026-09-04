/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:24:42 by syee              #+#    #+#             */
/*   Updated: 2025/05/21 19:24:42 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*returnpoint;
	int		n;

	n = 0;
	returnpoint = (char *)s;
	while (*returnpoint)
	{
		returnpoint++;
		n++;
	}
	if ((char)c == '\0')
		return (returnpoint);
	else
	{
		while (n-- >= 0)
		{
			if (*returnpoint == (char)c)
				return (returnpoint);
			returnpoint--;
		}
		return (NULL);
	}
}
/*
int main (void)
{
    char * output = (ft_strrchr("abdide",'d'));
    while (*output)
    {
     printf("the char is at :%c\n",*output);
     output++;
    }
}*/
