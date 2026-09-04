/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:23:50 by syee              #+#    #+#             */
/*   Updated: 2025/06/03 18:14:13 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		counter;

	node = lst;
	counter = 0;
	while (node != NULL)
	{
		node = node -> next;
		counter++;
	}
	return (counter);
}
