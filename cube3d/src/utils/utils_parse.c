/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:20:44 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/04 14:10:12 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

/*mira el caracter necesario en sí si no encuentra caracter return (0)*/
int	is_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*te mira si en la linea que llega esta los caracteres 
necesarios si no encueentra es retun(0)*/
int	set_only(char *line, char *set)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (is_set(line[i], set) == 0)
			return (0);
		i++;
	}
	return (1);
}

size_t	count_arrays(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

size_t	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
	return (i);
}

void	free_map(t_map *map)
{
	if (map->map)
		free_array(map->map);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
}
