/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:11:18 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/09 10:51:21 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ray_east(t_game *game, double agn, t_ray *ray)
{
	int	i;

	i = -1;
	ray->angle = agn;
	ray->rx = ((int)(game->player.px / 32 + 1) * 32);
	ray->ry = (game->player.px - ray->rx) * -tan(agn) + game->player.py;
	while (++i < 100)
	{
		if (ray->ry < 0 || ray->rx < 0
			|| ray->ry > (game->map.height - 1) * 32
			|| ray->rx > (game->map.width - 1) * 32)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (game->map.map[(int)ray->ry / 32][(int)ray->rx / 32] == '1')
			break ;
		else
		{
			ray->rx += 32;
			ray->ry += -32 * -tan(agn);
		}
	}
	ray->lenght = sqrt((ray->rx - game->player.px) * (ray->rx - game->player.px)
			+ (ray->ry - game->player.py) * (ray->ry - game->player.py));
}

void	ray_west(t_game *game, double agn, t_ray *ray)
{
	int	i;

	i = -1;
	ray->angle = agn;
	ray->rx = ((int)(game->player.px / 32) * 32) - 0.0001;
	ray->ry = (game->player.px - ray->rx) * -tan(agn) + game->player.py;
	while (++i < 100)
	{
		if (ray->ry < 0 || ray->rx < 0
			|| ray->ry > (game->map.height - 1) * 32
			|| ray->rx > (game->map.width - 1) * 32)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (game->map.map[(int)ray->ry / 32][(int)ray->rx / 32] == '1')
			break ;
		else
		{
			ray->rx += -32;
			ray->ry += 32 * -tan(agn);
		}
	}
	ray->lenght = sqrt((ray->rx - game->player.px) * (ray->rx - game->player.px)
			+ (ray->ry - game->player.py) * (ray->ry - game->player.py));
}

void	ray_south(t_game *game, double agn, t_ray *ray)
{
	int		i;

	i = -1;
	ray->angle = agn;
	ray->ry = ((int)(game->player.py / 32) * 32) - 0.0001;
	ray->rx = (game->player.py - ray->ry) * -1 / tan(agn) + game->player.px;
	while (++i < 100)
	{
		if (ray->ry < 0 || ray->rx < 0
			|| ray->ry > (game->map.height - 1) * 32
			|| ray->rx > (game->map.width - 1) * 32)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (game->map.map[(int)ray->ry / 32][(int)ray->rx / 32] == '1')
			break ;
		else
		{
			ray->rx += 32 * (-1 / tan(agn));
			ray->ry += -32;
		}
	}
	ray->lenght = sqrt((ray->rx - game->player.px) * (ray->rx - game->player.px)
			+ (ray->ry - game->player.py) * (ray->ry - game->player.py));
}

void	ray_north(t_game *game, double agn, t_ray *ray)
{
	int		i;

	i = -1;
	ray->angle = agn;
	ray->ry = ((int)(game->player.py / 32 + 1) * 32);
	ray->rx = (game->player.py - ray->ry) * -1 / tan(agn) + game->player.px;
	while (++i < 100)
	{
		if (ray->ry < 0 || ray->rx < 0
			|| ray->ry > (game->map.height - 1) * 32
			|| ray->rx > (game->map.width - 1) * 32)
		{
			ray->lenght = __DBL_MAX__;
			return ;
		}
		if (game->map.map[(int)ray->ry / 32][(int)ray->rx / 32] == '1')
			break ;
		else
		{
			ray->rx += -32 * (-1 / tan(agn));
			ray->ry += 32;
		}
	}
	ray->lenght = sqrt((ray->rx - game->player.px) * (ray->rx - game->player.px)
			+ (ray->ry - game->player.py) * (ray->ry - game->player.py));
}
