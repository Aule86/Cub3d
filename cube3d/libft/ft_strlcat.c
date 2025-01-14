/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:43:13 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:42:39 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lens;
	size_t	lend;

	i = 0;
	j = 0;
	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (dstsize == 0)
		return (lens);
	else if (lend > dstsize)
		lens = lens + dstsize;
	else
		lens = lens + lend;
	while (dst[i])
	{
		++i;
	}
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (lens);
}

/*#include <stdio.h>
int main()
{
	char a[] = "hola ";
	char b[] = "que tal?";

	printf("%d", ft_strlcat(a,b, 4));
	return (0);
}*/
