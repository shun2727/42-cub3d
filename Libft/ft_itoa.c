/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:37:42 by syee              #+#    #+#             */
/*   Updated: 2025/05/29 17:37:42 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	numlen(long long m)
{
	int		counter;

	if (m < 0)
	{
		m = -m;
		counter = 1;
	}
	else
		counter = 0;
	if (m == 0)
		return (1);
	while (m != 0)
	{
		m = m / 10;
		counter++;
	}
	return (counter);
}

static char	*returnstr(long long m, char *str, int size)
{
	int		index;

	if (m < 0)
	{
		m = -m;
		str[0] = '-';
	}
	index = size;
	str[index--] = '\0';
	if (m == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (m != 0)
	{
		str[index] = (m % 10) + '0';
		m = m / 10;
		index--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	m;
	char		*str;
	size_t		size;

	m = (long long)n;
	size = numlen(m);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	return (returnstr(m, str, size));
}
/*
int main(void)
{
	printf("%s\n",ft_itoa(-123));
	printf("%s\n",ft_itoa(INT_MIN));
	printf("%s",ft_itoa(0));
}*/