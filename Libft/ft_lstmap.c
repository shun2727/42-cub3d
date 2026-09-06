/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syee <syee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:07:15 by syee              #+#    #+#             */
/*   Updated: 2025/06/04 15:07:15 by syee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newnode = malloc(sizeof(t_list));
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode -> next = NULL;
		newnode -> content = f(lst -> content);
		ft_lstadd_back (&newlst, newnode);
		lst = lst -> next;
	}
	return (newlst);
}
/*i malloc node
if node fails free
make the content of next = nextnode (was initialize as NULL)
 newlst content is after function
 set the upcoming node as?
 point the lst to the next lst
 ()*/
