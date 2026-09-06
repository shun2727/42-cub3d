/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:25:15 by syee              #+#    #+#             */
/*   Updated: 2025/05/22 12:25:15 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*memory;
	size_t			i;

	i = 0;
	if (size != 0 && count > (INT_MAX / size))
		return (NULL);
	memory = (unsigned char *) malloc (count * size);
	if (!memory)
		return (NULL);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return ((void *)memory);
}
