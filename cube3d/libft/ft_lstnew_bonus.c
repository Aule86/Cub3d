/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:31:28 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:41:08 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*m;

	m = (t_list *)malloc(sizeof(t_list));
	if (!m)
		return (NULL);
	m->content = content;
	m->next = NULL;
	return (m);
}

/*int	main(void)
{
	t_list	*node;

	node = ft_lstnew("perro");
	printf("Content: %s", node->content);
	return (0);
}*/
