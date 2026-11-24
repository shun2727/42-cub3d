/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:08:15 by syee              #+#    #+#             */
/*   Updated: 2026/10/06 21:01:18 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief counts the amount of needles (char) within the provided string (haystack)
 * 
 * @param char needle 
 * @param char* haystack 
 * @return int 
 */
int chr_count(char needle, char *haystack)
{
	int	count;

	count = 0;
	while (*haystack != '\0')
	{
		if (*haystack == needle)
			count++;
		haystack++;
	}
	return(count);
}
