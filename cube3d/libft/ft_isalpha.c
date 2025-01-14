/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:47:18 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:15 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z')
		|| (a >= 'a' && a <= 'z'))
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	printf ("%d\n", ft_isappha('a'));
	printf ("%d\n", ft_isappha(1));
	return (0);
}*/
