/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_little_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:39 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/11 14:40:31 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

enum color {
	WHITE,
	BLACK,
};

#define SIZE_TILE 16

void	draw_tile(t_cub *cub3D, int canvas_x, int canvas_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_TILE)
	{
		x = 0;
		while (x < SIZE_TILE)
		{
			if (y == 0 || x == 0 || y == SIZE_TILE - 1 || x == SIZE_TILE - 1)
				mlx_pixel_put(cub3D->win->mlx_ptr, cub3D->win->win_ptr, (x + canvas_x * SIZE_TILE + SIZE_TILE), (y + canvas_y * SIZE_TILE + SIZE_TILE), 0x00000000);
			else if (color == BLACK)
				mlx_pixel_put(cub3D->win->mlx_ptr, cub3D->win->win_ptr, (x + canvas_x * SIZE_TILE + SIZE_TILE), (y + canvas_y * SIZE_TILE + SIZE_TILE), 0x00000000);
			else if (color == WHITE)
				mlx_pixel_put(cub3D->win->mlx_ptr, cub3D->win->win_ptr, (x + canvas_x * SIZE_TILE + SIZE_TILE), (y + canvas_y * SIZE_TILE + SIZE_TILE), 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	
}

void draw_little_map(t_cub *cub3D)
{
	int	x;
	int	y;

	y = 0;
	while (cub3D->map[y])
	{
		x = 0;
		while (cub3D->map[y][x])
		{
			if (cub3D->map[y][x] == '1')
				draw_tile(cub3D, x, y, WHITE);
			else if (cub3D->map[y][x] == '0' || cub3D->map[y][x] == 'N') // ajouter WSE
				draw_tile(cub3D, x, y, BLACK);
			x++;
		}
		y++;
	}
}