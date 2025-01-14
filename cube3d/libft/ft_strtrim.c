/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:28:30 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:43:08 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lens;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	lens = ft_strlen((char *) s1);
	while (ft_strchr(set, s1[lens]) && lens != 0)
		lens--;
	return (ft_substr((char *)s1, 0, lens + 1));
}

/*int main(void)
{
	char s[] = "afhlmnafjjaf";
	char set[] = "af";

	printf("%s", ft_strtrim(s,set));
	return (0);
}*/