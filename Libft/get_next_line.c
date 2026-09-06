/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 01:47:47 by syee              #+#    #+#             */
/*   Updated: 2025/06/20 20:21:07 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str(char *staticbuffer)
{
	char	*newline_ptr;
	int		len;
	char	*returnstr;

	newline_ptr = ft_strchr(staticbuffer, '\n');
	if (newline_ptr == NULL)
	{
		returnstr = ft_strdup(staticbuffer);
		if (!returnstr)
			return (NULL);
		return (returnstr);
	}
	len = newline_ptr - staticbuffer + 1;
	returnstr = (char *)malloc(len + 1);
	if (!returnstr)
		return (NULL);
	ft_memcpy(returnstr, staticbuffer, len);
	returnstr[len] = '\0';
	return (returnstr);
}

// here keep reading till find newline
void	read_into_buffer(int fd, char **staticbuffer)
{
	int		read_size;
	char	*buffer;

	read_size = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	while (read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		*staticbuffer = ft_strjoin(*staticbuffer, buffer);
		if (ft_strchr(*staticbuffer, '\n'))
			break ;
	}
	free(buffer);
}

void	update_staticbuffer(char **staticbuffer)
{
	char	*newline_ptr;
	char	*temp;

	newline_ptr = ft_strchr(*staticbuffer, '\n');
	if (!newline_ptr || !*(newline_ptr + 1))
	{
		free(*staticbuffer);
		*staticbuffer = NULL;
		return ;
	}
	temp = ft_strdup(newline_ptr + 1);
	free(*staticbuffer);
	*staticbuffer = temp;
}

char	*get_next_line(int fd)
{
	static char	*staticbuffer[OPEN_MAX];
	char		*returnstr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	read_into_buffer (fd, &staticbuffer[fd]);
	if (!staticbuffer[fd])
		return (NULL);
	returnstr = get_str(staticbuffer[fd]);
	update_staticbuffer(&staticbuffer[fd]);
	return (returnstr);
}

// int main(void)
// {
// 	char *output;
// 	int fd;
// 	fd = open("test.txt",O_RDONLY);
// 	output = get_next_line(fd);
// 	//printf("read line : %s ",output);
// 	while (output)
// 	{
// 		printf("main read line : %s",output);
// 		free(output);
// 		output = get_next_line(fd);
// 	}
// 	return(0);
// }
