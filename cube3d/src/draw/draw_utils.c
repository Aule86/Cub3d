/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:38:11 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/20 12:36:52 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	to_rgba_hex(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

void	free_array2(void **array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		free(array[i]);
	free(array);
}

void	free_data(t_game *game)
{
	free_array2((void **)game->texture.north.pixel);
	free_array2((void **)game->texture.south.pixel);
	free_array2((void **)game->texture.east.pixel);
	free_array2((void **)game->texture.west.pixel);
	if (game->mlx)
	{
		mlx_delete_image(game->mlx, game->viewpoint);
		mlx_terminate(game->mlx);
	}
}
