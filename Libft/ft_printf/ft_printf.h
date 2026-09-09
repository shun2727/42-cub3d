/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:25:57 by syee              #+#    #+#             */
/*   Updated: 2025/06/27 22:17:44 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //for variadic function
# include <unistd.h> //write func

//libft helper function
void	pf_putchar_fd(char c, int fd, int *bytes_written);
void	pf_putnbr_fd(long long n, int fd, int *bytes_written);
void	pf_putstr_fd(char *s, int fd, int *bytes_written);
void	pf_putnbr_hex(long long x, int flag, int *bytes_written);
void	pf_putptr(unsigned long long x, int *bytes_written);

//ft_printf file
int		ft_printf(const char *format, ...);
void	pass_format(char format_specifier, va_list args, int *bytes_written);

#endif