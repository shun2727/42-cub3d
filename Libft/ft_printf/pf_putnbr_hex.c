/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:58:51 by syee              #+#    #+#             */
/*   Updated: 2026/09/09 16:38:30 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_recursive(long long x, char *base_arr, int *bytes_written)
{
	if (x == 0)
		return ;
	print_recursive(x / 16, base_arr, bytes_written);
	*bytes_written += write(1, &base_arr[x % 16], 1);
}

void	pf_putnbr_hex(long long x, int flag, int *bytes_written)
{
	char	*base_arr;

	if (flag == 1)
		base_arr = "0123456789ABCDEF";
	else if (flag == 0)
		base_arr = "0123456789abcdef";
	if (x == 0)
		*bytes_written += write (1, "0", 1);
	else
		print_recursive (x, base_arr, bytes_written);
}
