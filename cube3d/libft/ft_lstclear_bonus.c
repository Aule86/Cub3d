/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:29:44 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:51 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pos;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		pos = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pos;
	}
}

/*void	del(void *content)
{
	*(char *)content = 0;
	free (content);
}

int	main(void)
{
	t_list	**dalist = malloc(sizeof(t_list *));
	t_list	*node;
	int		i;

	i = 0;
	node = 0;
	dalist = &node;
	ft_lstadd_back(dalist, ft_lstnew(ft_strdup("perro")));
	ft_lstadd_back(dalist, ft_lstnew(ft_strdup("gato")));
	node = *dalist;
	printf("%s ", node->content);
	ft_lstclear(&(node->next), del);
	node->next = 0;
	printf("%s ", node->content);
	return (0);
}*/