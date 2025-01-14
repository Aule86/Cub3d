/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:42:37 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/13 11:37:10 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_error(int code)
{
	if (code == 1)
		ft_putstr_fd("INVALID NUM ARGUMENTS", 2);
	if (code == 2)
		ft_putstr_fd("INVALID TYPE OF FILE NOT '.CUB'", 2);
	if (code == 3)
		ft_putstr_fd("NOT NUM  OF ELEMENTS IN LINE", 2);
	if (code == 4)
		ft_putstr_fd("MAP NEEDS TO HAVE THESE CHARACTERS '01NSEW'", 2);
	if (code == 5)
		ft_putstr_fd("FILE ERROR", 2);
	if (code == 6)
		ft_putstr_fd("Not all description line are present\n \
Usage: One line of each element\
``NO, SO, WE, EA, F, C`` only !\n", 2);
	if (code == 7)
		ft_putstr_fd("No map in file\n", 2);
	if (code == 8)
		ft_putstr_fd("ONE PLAYER IS NEEDED", 2);
	if (code == 9)
		ft_putstr_fd("Map must be enclosed\n", 2);
	if (code == 10)
		ft_putstr_fd("MALLOC ERROR", 2);
	if (code == 11)
		ft_putstr_fd("TEXTURE ERROR", 2);
	return (0);
}
