/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:53:00 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/12 12:54:48 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	set_map(t_map *map)
{
	map->map = 0;
	map->height = 0;
	map->width = 0;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->f = -1;
	map->c = -1;
}

/*funcion que chequea si existen los cracteres necesarios del mapa*/
int	set_map_size(char *file, int *size)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = 0;
	if (fd == -1)
		return (5);
	while (get_next_line(fd, &line, 0) != 0)
	{
		if (set_only(line, " 01NSEW\n") && !set_only(line, " "))
			break ;
		free(line);
	}
	while (line)
	{
		if (ft_strlen(line) && set_only(line, " 01NSEW\n"))
			*size += 1;
		else
			break ;
		free(line);
		get_next_line(fd, &line, 0);
	}
	if (line != 0)
		return (free(line), close(fd), 4);
	return (close(fd), 0);
}

/*menu del parseo*/
int	check_input(t_map *map, char *line)
{
	int	error;

	set_map(map);
	error = set_map_size(line, &map->height);
	if (error)
		return (error);
	map->map = ft_calloc(sizeof(char *), map->height + 1);
	if (!map->map)
		return (10);
	error = read_file(map, line, map->height);
	if (error)
		return (error);
	error = check_map(map);
	if (error)
		return (error);
	return (0);
}
