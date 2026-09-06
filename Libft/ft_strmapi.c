/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:52:51 by syee              #+#    #+#             */
/*   Updated: 2025/05/29 19:52:51 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*returnstr;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	returnstr = (char *)malloc(ft_strlen(s) + 1);
	if (!returnstr)
		return (NULL);
	while (s[i])
	{
		returnstr[i] = f(i, s[i]);
		i++;
	}
	returnstr[i] = '\0';
	return (returnstr);
}
