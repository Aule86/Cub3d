/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:52 by aszamora          #+#    #+#             */
/*   Updated: 2025/01/28 13:09:08 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	check_elements(t_map *map)
{
	if (!map->no || !map->so || !map->ea || !map->we)
		return (6);
	if (map->f == -1 || map->c == -1)
		return (6);
	if (!map->map)
		return (7);
	return (0);
}

int	flot_fill(t_map *map, char **map_copy, int y, int x)
{
	int	error;

	if (map_copy[y][x] == '1')
		return (0);
	if (y == 0 || x == 0 || y == map->height -1 || x == map->width - 1)
		return (1);
	map_copy[y][x] = '1';
	error = 0;
	error += flot_fill(map, map_copy, y + 1, x);
	error += flot_fill(map, map_copy, y - 1, x);
	error += flot_fill(map, map_copy, y, x + 1);
	error += flot_fill(map, map_copy, y, x - 1);
	if (error == 0)
		return (0);
	return (9);
}

static void	init_angel(t_map *map, char pos)
{
	if (pos == 'N')
		map->player.angulo = NORTH;
	if (pos == 'S')
		map->player.angulo = SOUTH;
	if (pos == 'E')
		map->player.angulo = EAST;
	if (pos == 'W')
		map->player.angulo = WEST;
}

int	check_players(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player.py = i * BLOCK_SIZE;
				map->player.px = j * BLOCK_SIZE;
				map->player.player++;
				init_angel(map, map->map[i][j]);
				count++;
			}
		}
	}
	return ((count != 1) * 8);
}

int	check_map(t_map *map)
{
	int		error;
	char	**map_cpy;

	error = check_elements(map);
	if (error)
		return (error);
	error = check_players(map);
	if (error)
		return (error);
	map_cpy = copy_map(map);
	error = flot_fill(map, map_cpy,
			map->player.py / BLOCK_SIZE, map->player.px / BLOCK_SIZE);
	free_array(map_cpy);
	if (error)
		return (free_array(map->map), error);
	return (0);
}
