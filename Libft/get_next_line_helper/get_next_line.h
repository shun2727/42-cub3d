/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:04:36 by syee              #+#    #+#             */
/*   Updated: 2025/06/20 21:05:53 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> //read witte etc
//# include <fcntl.h> //for open flags

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 65534

int		ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *staticbuffer, char *buffer);
char	*ft_strdup(const char *src);

void	update_staticbuffer(char **staticbuffer);
char	*get_next_line(int fd);
void	read_into_buffer(int fd, char **buffer);
char	*get_str(char *staticbuffer);

#endif
