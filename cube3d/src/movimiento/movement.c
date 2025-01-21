/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:06:43 by aszamora          #+#    #+#             */
/*   Updated: 2025/01/21 11:49:13 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	camera_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player.angulo -= 0.05;
		if (game->player.angulo <= 0)
			game->player.angulo = 6.28319;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player.angulo += 0.05;
		if (game->player.angulo >= 6.28319)
			game->player.angulo = 0.000001;
	}
}

void	check_movement(t_game *game, double delta_x, double delta_y)
{
	int	new_x;
	int	new_y;

	new_x = (game->player.px + delta_x) / 32;
	new_y = (game->player.py + delta_y) / 32;
	if (game->map.map[(int)(game->player.py / 32)][new_x] != '1')
		game->player.px += delta_x;
	if (game->map.map[new_y][(int)(game->player.px / 32)] != '1')
		game->player.py += delta_y;
}

void	player_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_I))
		printf(HBLU"debug: \nplayer pos (%f, %f) \t player angle(%f)\n"RST, game->player.px, game->player.py, game->player.angulo);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		check_movement(game, -cos(game->player.angulo) * 2,
			-sin(game->player.angulo) * 2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		check_movement(game, cos(game->player.angulo) * 2,
			sin(game->player.angulo) * 2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		check_movement(game, cos(game->player.angulo + (PI / 2)) * 2,
			sin(game->player.angulo + (PI / 2)) * 2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		check_movement(game, -cos(game->player.angulo + (PI / 2)) * 2,
			-sin(game->player.angulo + (PI / 2)) * 2);
}

void	movement(void *mlx)
{
	t_game	*game;
	int		px_o;
	int		py_o;
	double	angle_o;

	game = mlx;
	px_o = game->player.px;
	py_o = game->player.py;
	angle_o = game->player.angulo;
	player_movement(game);
	camera_movement(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_data(game);
		exit(EXIT_FAILURE);
	}
	if (px_o != game->player.px || py_o != game->player.py
		|| game->player.angulo != angle_o)
	{
		rayos(game);
		draw_imagen(game);
	}
}
