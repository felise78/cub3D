/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_first_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:38:16 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/10 16:07:52 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

void	set_first_position(t_cub *cub3D)
{
	int x = 0;
	int y = 0;
	while (cub3D->map[y])
	{
		x = 0;
		while(cub3D->map[y][x])
		{
			if (cub3D->map[y][x] == 'N' || cub3D->map[y][x] == 'W' || cub3D->map[y][x] == 'E' || cub3D->map[y][x] == 'S')
			{
				cub3D->player->x = x + 0.5;
				cub3D->player->y = y + 0.5;
				cub3D->player->mapX = (int)cub3D->player->x;
				cub3D->player->mapY = (int)cub3D->player->y;
				// if (cub3D->map[y][x] == 'N')
				// 	cub3D->player->orientation = 1.57079632679; // pi / 2
				// else if (cub3D->map[y][x] == 'W')
				// 	cub3D->player->orientation = 3.14159265359; // pi
				// else if (cub3D->map[y][x] == 'E')
				// 	cub3D->player->orientation = 0;
				// else if (cub3D->map[y][x] == 'S')
				// 	cub3D->player->orientation = 4.71238898038; // 3 pi / 2
				return ;
					
			}
			x++;
		}
		y++;
	}
}