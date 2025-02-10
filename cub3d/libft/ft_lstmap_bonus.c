/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:35:09 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:41:05 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*aux;

	if (!lst)
		return (0);
	temp = ft_lstnew(f(lst->content));
	lst = lst->next;
	new = temp;
	aux = lst;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&aux, del);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (new);
}

/*void	del(void *content)
{
	*(char *)content = 0;
	free (content);
}*/
