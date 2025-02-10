/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:21:36 by ciestrad          #+#    #+#             */
/*   Updated: 2025/02/03 12:10:05 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	correct_file(char *line)
{
	if (ft_strlen(line) >= 5
		&& ft_strncmp(line + ft_strlen(line) - 4, ".cub", 4) == 0
		&& line[ft_strlen(line) - 5] != '/')
		return (0);
	return (1);
}

void	init_data(t_game *game)
{
	game->player.fov = 60;
	game->texture.north.pixel = NULL;
	game->texture.south.pixel = NULL;
	game->texture.west.pixel = NULL;
	game->texture.east.pixel = NULL;
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUBED", true);
	game->viewpoint = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->viewpoint, 0, 0);
}

void	init_player(t_game *game)
{
	game->player.px = game->map.player.px;
	game->player.py = game->map.player.py;
	game->player.angulo = game->map.player.angulo;
	game->player.fov = 60;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		error;

	if (argc != 2)
		return (ft_error(1));
	if (correct_file(argv[1]))
		return (ft_error(2));
	ft_memset(&game, 0, sizeof(t_game));
	init_data(&game);
	error = check_input(&(game.map), argv[1]);
	init_player(&game);
	if (error)
		return (ft_error(error));
	if (init_texture(&game))
		return (free_data(&game), ft_error(11));
	rayos(&game);
	draw_imagen(&game);
	mlx_loop_hook(game.mlx, movement, &game);
	mlx_loop(game.mlx);
	free_data(&game);
	return (0);
}
