/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:54:22 by ciestrad          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:53 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			cont;
	long int	num;

	num = 0;
	i = 0;
	cont = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cont++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (cont)
		return (num * -1);
	return (num);
}

/* int	spaces(const char *str, int *ip)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while ((str[i] == 45 && str[i] != '\0') || str[i] == 43)
	{
		if (str[i] == 45)
			j *= -1;
		i++;
	}
	*ip = i;
	return (j);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	resul;
	int	i;

	resul = 0;
	s = spaces((const char *)str, &i);
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		resul *= 10;
		resul += str[i] - 48;
		i++;
	}
	resul *= s;
	return (resul);
} */

/*#include <stdio.h>
int main(void)
{
	char *s = "   ---+--+1234ab567";
	printf("%d", ft_atoi(s));
}*/