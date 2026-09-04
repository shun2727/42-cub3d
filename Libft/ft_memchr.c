/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:09:07 by syee              #+#    #+#             */
/*   Updated: 2025/05/21 23:09:07 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*temp == (unsigned char) c)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}
/*
int main() {
    char data[] = "Hello, world!";
    int target = ',';  

    char *result = ft_memchr(data, target, 20);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", target, result - data);
    } else {
        printf("Character '%c' not found.\n", target);
    }

    return 0;
}
"Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char"*/
