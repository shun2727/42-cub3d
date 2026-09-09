/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:02:18 by syee              #+#    #+#             */
/*   Updated: 2026/09/09 16:30:14 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	writenbr(long long n, int fd, int *bytes_written)
{
	char	c;

	if (n != 0)
	{
		writenbr(n / 10, fd, bytes_written);
		c = (n % 10) + '0';
		*bytes_written += write (fd, &c, 1);
	}
}

void	pf_putnbr_fd(long long x, int fd, int *bytes_written)
{
	if (x < 0)
	{
		*bytes_written += write (fd, "-", 1);
		x = -1 * x;
	}
	if (x == 0)
	{
		*bytes_written += write (fd, "0", 1);
		return ;
	}
	writenbr (x, fd, bytes_written);
}
