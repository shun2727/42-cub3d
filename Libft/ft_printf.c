/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:55:39 by syee              #+#    #+#             */
/*   Updated: 2025/06/27 22:09:32 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_written;

	bytes_written = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			pass_format(*format, args, &bytes_written);
		}
		else
			bytes_written += write(1, format, 1);
		format ++;
	}
	va_end(args);
	return (bytes_written);
}

void	pass_format(char format_specifier, va_list args, int *bytes_written)
{
	if (format_specifier == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1, bytes_written);
	else if (format_specifier == 's')
		ft_putstr_fd((char *)va_arg(args, char *), 1, bytes_written);
	else if (format_specifier == 'p')
		ft_putptr(((unsigned long long)va_arg(args, void *)), bytes_written);
	else if (format_specifier == 'd' || format_specifier == 'i')
		ft_putnbr_fd((int)va_arg(args, int), 1, bytes_written);
	else if (format_specifier == 'u')
		ft_putnbr_fd((unsigned int)va_arg(args, unsigned int), 1,
			bytes_written);
	else if (format_specifier == 'x')
		ft_putnbr_hex((unsigned int)va_arg(args, int), 0, bytes_written);
	else if (format_specifier == 'X')
		ft_putnbr_hex((unsigned int)va_arg(args, int), 1, bytes_written);
	else if (format_specifier == '%')
		*bytes_written += write (1, "%", 1);
}
