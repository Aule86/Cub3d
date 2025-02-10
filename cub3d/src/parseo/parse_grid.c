/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:02 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/22 12:03:10 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	check_f_c(char *element)
{
	if (check_alpha(element) == 1)
		return (1);
	else
		return (0);
}

int	check_alpha(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_isalpha(array[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	**fill_map_x(char **map)
{
	size_t	len;
	size_t	max;
	int		x;
	size_t	y;
	char	*tmp;

	max = max_line(map) - 1;
	x = -1;
	while (map[++x])
	{
		y = -1;
		tmp = map[x];
		len = ft_strlen(map[x]);
		map[x] = (char *)malloc(sizeof(char *) * (max + 1));
		map[x][max + 1] = '\0';
		while (++y <= max)
		{
			if (y >= len || tmp[y] == ' ')
				map[x][y] = '0';
			else
				map[x][y] = tmp[y];
		}
		free(tmp);
	}
	return (map);
}
