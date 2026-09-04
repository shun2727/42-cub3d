/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:02:33 by syee              #+#    #+#             */
/*   Updated: 2025/05/26 20:02:33 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	trimfront(char const *s1, char const *set)
{
	int	i;
	int	front;

	i = 0;
	front = 0;
	while (set[i] && s1[front])
	{
		if (set[i++] == s1[front])
		{
			front++;
			i = 0;
		}
	}
	return (front);
}
//back -1 cus len is pointing at null

static int	trimback(const char *s1, const char *set)
{
	int	i;
	int	back;

	i = 0;
	back = (ft_strlen(s1) - 1);
	while (set[i] && back >= 0)
	{
		if (set[i++] == s1[back])
		{
			back--;
			i = 0;
		}
	}
	return (back);
}

static char	*mallocreturn(const char *s1, int start, int end)
{
	int		i;
	int		j;
	char	*returnstr;

	i = start;
	j = 0;
	returnstr = (char *)malloc(end - start + 2);
	if (returnstr == NULL)
		return (NULL);
	else
	{
		while (i <= end)
			returnstr[j++] = s1[i++];
	}
	returnstr[j] = '\0';
	return (returnstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*returnstr;
	char	*empty;
	int		front;
	int		back;
	int		s1len;

	s1len = ft_strlen(s1);
	front = trimfront(s1, set);
	if (front == s1len)
	{
		empty = malloc(1);
		if (empty)
			empty[0] = '\0';
		return (empty);
	}
	back = trimback(s1, set);
	returnstr = mallocreturn(s1, front, back);
	return (returnstr);
}
/*
-shouldve done it with strchr (where str is the set and char is str[i],
current code is prone to error 
-it ok to typecast char const to char 
-edge cases, oif its consists of set only , if the first loop reaches null,
 dont loop from back
-i can prolly do i++ since its null terminated and theres no risk of segfault?
*/
