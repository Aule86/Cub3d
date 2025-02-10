/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:06:14 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:58 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	else
		del(lst->content);
	free (lst);
}

/*void	del(void *content)
{
	*(char *)content = 0;
	free (content);
}*/

/*int	main(void)
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
	printf("%d\n ", ft_lstsize(node));
	ft_lstdelone((node->next), del);
	node->next = 0;
	printf("%d\n ", ft_lstsize(node));
	return (0);
}*/
