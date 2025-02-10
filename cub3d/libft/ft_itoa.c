/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:44:28 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:40:30 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	putnbr(int nb)
{
	size_t	num;

	num = 1;
	if (nb < 0)
		++num;
	while (nb / 10 != 0)
	{
		++num;
		nb /= 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*m;
	int		i;
	long	num;

	num = n;
	m = malloc(sizeof(*m) * (putnbr(num) + 1));
	i = putnbr(num);
	if (!m)
		return (NULL);
	if (!num)
		m[0] = '0';
	else if (num < 0)
	{
		m[0] = '-';
		num *= -1;
	}
	m[i--] = '\0';
	while (num)
	{
		m[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (m);
}

// int main(void)
// {
// 	int s;
// 	s = -10;
// 	printf("%s", ft_itoa(s));
// 	return (0);
// }