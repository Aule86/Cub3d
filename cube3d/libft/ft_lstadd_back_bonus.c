/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:10:39 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:35 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

/*int	main(void)
{
	t_list	**dalist;
	t_list	*node;
	int		i;

	i = 0;
	node = 0;
	dalist = &node;
	ft_lstadd_back(dalist, ft_lstnew("perro"));
	ft_lstadd_back(dalist, ft_lstnew("gato"));
	ft_lstadd_back(dalist, ft_lstnew("conejo"));
	ft_lstadd_back(dalist, ft_lstnew("pato"));
	node = *dalist;
	while (node)
	{
		printf("%s ", node->content);
		node = (*node).next; //node->next; 
	}
	return (0);
}*/
