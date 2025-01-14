/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:12:06 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:42:53 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*m;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	m = malloc(sizeof(*m) * (ft_strlen(s) + 1));
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = (*f)(i, s[i]);
		++i;
	}
	m[i] = '\0';
	return (m);
}
