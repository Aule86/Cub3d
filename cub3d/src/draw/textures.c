/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:59:31 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/22 10:57:29 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	draw_north_texture(t_game *game, int x, int y)
{
	int	tx;
	int	ty;
	int	textures_width;

	textures_width = game->texture.north.width;
	tx = game->rayo[x].rx * textures_width / 32;
	ty = ((y - game->sky_size + game->wall_diff / 2)
			* game->texture.north.height) / (game->wall_size + game->wall_diff);
	mlx_put_pixel(game->viewpoint, x, y,
		game->texture.north.pixel[ty][tx % textures_width]);
}

void	draw_south_texture(t_game *game, int x, int y)
{
	int	tx;
	int	ty;
	int	textwidth;

	textwidth = game->texture.south.width - 1;
	tx = game->rayo[x].rx * textwidth / 32;
	ty = ((y - game->sky_size + game->wall_diff / 2)
			* game->texture.south.height) / (game->wall_size + game->wall_diff);
	mlx_put_pixel(game->viewpoint, x, y,
		game->texture.south.pixel[ty][(textwidth - (tx % textwidth))]);
}

void	draw_west_texture(t_game *game, int x, int y)
{
	int	tx;
	int	ty;
	int	textures_width;

	textures_width = game->texture.west.width - 1;
	tx = game->rayo[x].ry * textures_width / 32;
	ty = ((y - game->sky_size + game->wall_diff / 2)
			* game->texture.west.height) / (game->wall_size + game->wall_diff);
	mlx_put_pixel(game->viewpoint, x, y,
		game->texture.west.pixel[ty][(textures_width - (tx % textures_width))]);
}

void	draw_east_texture(t_game *game, int x, int y)
{
	int	tx;
	int	ty;
	int	textures_width;

	textures_width = game->texture.east.width;
	tx = game->rayo[x].ry * textures_width / 32;
	ty = ((y - game->sky_size + game->wall_diff / 2)
			* game->texture.east.height) / (game->wall_size + game->wall_diff);
	mlx_put_pixel(game->viewpoint, x, y,
		game->texture.east.pixel[ty][tx % textures_width]);
}

void	draw_textures(t_game *game, int x, int y)
{
	if (game->rayo[x].type == 'h' && game->rayo[x].angle < PI)
		draw_north_texture(game, x, y);
	else if (game->rayo[x].type == 'h')
		draw_south_texture(game, x, y);
	else if (game->rayo[x].type == 'v'
		&& (game->rayo[x].angle < NORTH || game->rayo[x].angle > SOUTH))
		draw_west_texture(game, x, y);
	else
		draw_east_texture(game, x, y);
}
