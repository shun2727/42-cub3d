/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:42:23 by syee              #+#    #+#             */
/*   Updated: 2025/06/27 22:27:24 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *bytes_written)
{
	int		i;
	char	c;

	i = 0;
	if (!s)
		*bytes_written += write (fd, "(null)", 6);
	else
	{
		while (s[i])
		{
			c = s[i++];
			*bytes_written += write (fd, &c, 1);
		}
	}
}
