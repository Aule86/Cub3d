/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:44:02 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:43:12 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*m;

	i = 0;
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(start + s) < len)
		len = ft_strlen(start + s);
	m = malloc(sizeof(char) * (len + 1));
	if (!m || !s)
		return (NULL);
	while (i < len)
	{
		m[i] = s[start];
		start++;
		i++;
	}
	m[i] = '\0';
	return (m);
}
