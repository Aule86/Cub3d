/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:17:57 by aszamora          #+#    #+#             */
/*   Updated: 2024/12/02 14:06:15 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		size;
	char	*result;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (free(s1), (char *)0);
	result[size] = 0;
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	return (free(s1), result);
}

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		readed;

	buffer = NULL;
	buffer = ft_strjoin_gnl(buffer, save);
	if (!buffer)
		return (0);
	readed = BUFFER_SIZE;
	while (ft_strchr(buffer, '\n') == 0 && readed == BUFFER_SIZE)
	{
		readed = read(fd, save, BUFFER_SIZE);
		if (readed == 0 || readed == -1)
			break ;
		save[readed] = 0;
		buffer = ft_strjoin_gnl(buffer, save);
		if (!buffer)
			return (0);
	}
	if (ft_strlen(buffer) == 0)
		return (free(buffer), (char *)0);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(buffer), (char *)0);
	line[i] = 0;
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	free(buffer);
	return (line);
}

void	remake_save(char *save)
{
	int	i;
	int	j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	j = 0;
	while (save[i])
	{
		save[j] = save[i];
		j++;
		i++;
	}
	save[j] = 0;
}

char	*get_next_line(int fd, char **out, int clear)
{
	static char	save[1024][BUFFER_SIZE + 1];
	char		*buffer;
	char		*line;

	if (clear)
	{
		ft_memset(save[fd], 0, BUFFER_SIZE + 1);
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	buffer = ft_read(fd, save[fd]);
	line = get_line(buffer);
	remake_save(save[fd]);
	if (!line)
		save[fd][0] = 0;
	*out = line;
	return (line);
}