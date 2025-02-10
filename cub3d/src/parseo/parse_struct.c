/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:23:35 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/22 12:09:22 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	get_element(t_map *map, char *line)
{
	char	**element;

	element = ft_split(line, ' ');
	if (!element)
		return (10);
	if (count_arrays(element) != 2)
		return (free_array(element), 3);
	if (ft_strcmp(element[0], "NO") == 0 && !map->no)
		map->no = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "SO") == 0 && !map->so)
		map->so = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "WE") == 0 && !map->we)
		map->we = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "EA") == 0 && !map->ea)
		map->ea = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "F") == 0 && map->f == -1
		&& check_f_c(element[1]) == 0)
		map->f = ft_color(element[1]);
	else if (ft_strcmp(element[0], "C") == 0 && map->c == -1
		&& check_f_c(element[1]) == 0)
		map->c = ft_color(element[1]);
	else
		return (free_array(element), 1);
	return (free_array(element), 0);
}

int	check_element(t_map *map, char *line)
{
	int	error;

	if (ft_strlen(line) == 0 || set_only(line, " "))
		return (free(line), 0);
	else
	{
		if (set_only(line, " 01NSEW\n"))
			return (-1);
		error = get_element(map, line);
		free(line);
		line = NULL;
		if (error)
			return (error);
	}
	return (0);
}

size_t	max_line(char **map)
{
	size_t	max;
	int		i;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

int	get_map(int fd, t_map *map, char *file, int size)
{
	int	i;

	i = 0;
	while (file)
	{
		map->map[i] = file;
		get_next_line(fd, &file, 0);
		i++;
	}
	map->width = max_line(map->map);
	map->map = fill_map_x(map->map);
	if (i != size)
		return (free_map(map), 10);
	return (0);
}

int	read_file(t_map *map, char *file, int size)
{
	int		fd;
	int		error;
	char	*line;

	error = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (5);
	while (error == 0 && get_next_line(fd, &line, 0) != 0)
		error = check_element(map, line);
	if (error != -1 || line == NULL)
		return (error);
	error = get_map(fd, map, line, size);
	if (error)
		return (error);
	return (0);
}
