/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:02 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/12 11:45:20 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

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
