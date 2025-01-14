/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:33:32 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/14 11:30:54 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	draw_sky(t_game *game, int sky_size, int x)
{
	int	y;

	y = -1;
	while (++y < sky_size)
		mlx_put_pixel(game->viewpoint, x, y, game->ceiling);
}

void	draw_floor(t_game *game, int sky_size, int x)
{
	int	y;

	y = sky_size - 1;
	while (++y < HEIGHT)
		mlx_put_pixel(game->viewpoint, x, y, game->floor);
}

void	draw_imagen(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		game->wall_size = (32 * HEIGHT) / game->rayo[x].lenght;
		if (game->wall_size > HEIGHT)
		{
			game->wall_diff = game->wall_diff - HEIGHT;
			game->wall_size = HEIGHT;
		}
		else
			game->wall_diff = 0;
		game->sky_size = (HEIGHT - game->wall_size) / 2
			+ (HEIGHT - game->wall_size) % 2;
		y = game->sky_size - 1;
		draw_sky(game, game->sky_size, x);
		while (++y < (HEIGHT / 2) + (game->wall_size / 2))
			draw_textures(game, x, y);
		draw_floor(game, y, x);
	}
}
