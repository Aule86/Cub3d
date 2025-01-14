/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:30:17 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/13 13:18:43 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

t_properties	texture_formatter(mlx_texture_t *texture)
{
	uint32_t		x;
	uint32_t		y;
	int				k;
	t_properties	new_texture;

	y = -1;
	new_texture.pixel = ft_calloc((texture->height + 1), sizeof(uint32_t *));
	new_texture.width = texture->width;
	new_texture.height = texture->height;
	while (texture->height > ++y)
	{
		new_texture.pixel[y] = ft_calloc((texture->width + 1),
				sizeof(uint32_t));
		x = -1;
		k = texture->width * 4 * y;
		while (++x < texture->width)
		{
			new_texture.pixel[y][x] = to_rgba_hex(texture->pixels[k],
					texture->pixels[k + 1],
					texture->pixels[k + 2], texture->pixels[k + 3]);
			k += 4;
		}
	}
	mlx_delete_texture(texture);
	return (new_texture);
}

void	init_texture(t_game *game)
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*west_texture;

	north_texture = mlx_load_png(game->map.no);
	south_texture = mlx_load_png(game->map.so);
	east_texture = mlx_load_png(game->map.ea);
	west_texture = mlx_load_png(game->map.we);
	if (!north_texture || !south_texture || !east_texture || !west_texture)
	{
		free(north_texture);
		free(south_texture);
		free(east_texture);
		free(west_texture);
		ft_error(11);
	}
	game->texture.north = texture_formatter(north_texture);
	game->texture.south = texture_formatter(south_texture);
	game->texture.east = texture_formatter(east_texture);
	game->texture.west = texture_formatter(west_texture);
	game->ceiling = game->map.c;
	game->floor = game->map.f;
}
