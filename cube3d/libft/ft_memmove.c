/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:10:35 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:41:36 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || !len)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			*((unsigned char *)dst + len - 1)
				= *((unsigned char *)src + len - 1);
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*((unsigned char *) dst + i) = *((unsigned char *) src + i);
			i++;
		}
	}
	return (dst);
}

/*int main(void)
{
	char a[] = "hola qque tal";
	char b[] = "muy bien";
	ft_memmove(b, a, 2);
	printf("%s", b);
	return(0);
}*/
