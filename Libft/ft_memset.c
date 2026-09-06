/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:42:03 by syee              #+#    #+#             */
/*   Updated: 2025/05/20 15:42:06 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n-- > 0)
		*(temp++) = (unsigned char) c;
	return (s);
}
/*
int main ()
{
	int arr[5];

	ft_memset(arr,9,sizeof(arr));

	for (int i = 0; i < 5; i++) 
	{
		printf("%d ", arr[i]);
   	}

	return 0;
}*/
//memset to assign raw memory 
