/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:43:33 by syee              #+#    #+#             */
/*   Updated: 2025/05/27 22:43:33 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	else if ((size_t)start >= ft_strlen(s) || len == 0)
	{
		word = (char *)malloc(1);
		if (!word)
			return (NULL);
		word[i] = '\0';
		return (word);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (s[start] && i < len)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}
/*
int main (void)
{
	char *outcome = ft_substr("tripouille", 100, 1);
	if (outcome == NULL)
		printf("NULL");
	else
		printf("outcome mew: %s",outcome);
}*/
