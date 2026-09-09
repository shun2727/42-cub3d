/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:54 by syee              #+#    #+#             */
/*   Updated: 2026/09/09 16:29:40 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_recursive(unsigned long long x, char *base_arr,
	int *bytes_written)
{
	if (x == 0)
		return ;
	print_recursive(x / 16, base_arr, bytes_written);
	*bytes_written += write (1, &base_arr[x % 16], 1);
}

void	pf_putptr(unsigned long long x, int *bytes_written)
{
	char	*base_arr;

	base_arr = "0123456789abcdef";
	if (x == 0)
		*bytes_written += write (1, "(nil)", 5);
	else
	{
		*bytes_written += write (1, "0x", 2);
		print_recursive(x, base_arr, bytes_written);
	}
}
