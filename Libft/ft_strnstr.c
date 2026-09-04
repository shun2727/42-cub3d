/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:24:26 by syee              #+#    #+#             */
/*   Updated: 2025/05/22 12:24:26 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j] && little[j]
				&& (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
		 const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = ft_strnstr(largestring, smallstring, 4);
	if (ptr == NULL) 
		printf("null bro");
	else
		printf("%s",ptr);
}
removed the -1 in return for big + i*/
