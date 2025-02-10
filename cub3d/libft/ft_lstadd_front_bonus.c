/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:32:26 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:48 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	*lst = new;
}

/*int	main(void)
{
	t_list	**dalist;
	t_list	*node;
	int		i;

	i = 0;
	ft_lstadd_front(dalist, ft_lstnew("perro"));
	ft_lstadd_front(dalist, ft_lstnew("gato"));
	ft_lstadd_front(dalist, ft_lstnew("conejo"));
	ft_lstadd_front(dalist, ft_lstnew("pato"));
	node = *dalist;
	while (node)
	{
		printf("%s ", node->content);
		node = (*node).next; //node->next; 
	}
	return (0);
}*/
