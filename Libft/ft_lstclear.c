/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:34:53 by syee              #+#    #+#             */
/*   Updated: 2025/06/03 22:34:55 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*templist;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		templist = *lst;
		del (templist -> content);
		*lst = templist -> next;
		free (templist);
	}
	*lst = NULL;
}
//why **lst is passed instead of *lst , cus always passing a value, 
//with adrr is passing the location olding the value whi
//if head is just copy if &head its the location and stuff itself
