/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:39 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 15:35:01 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_tile(t_cub *cub, int map_x, int map_y, int color)
{	
    int x_tile;
	int y_tile = 0;
    while (y_tile < SIZE_TILE)
    {
		x_tile = 0;
		while(x_tile < SIZE_TILE)
		{
			if (color == BLACK) // x_tile == 0 || y_tile == 0 || x_tile == SIZE_TILE - 1 || y_tile == SIZE_TILE - 1 || 
				set_pixel(cub, cub->win->index[SIZE_TILE * map_y + SIZE_TILE + y_tile][SIZE_TILE * map_x + SIZE_TILE + x_tile], cub->colors[BLACK]);
			else
				set_pixel(cub, cub->win->index[SIZE_TILE * map_y + SIZE_TILE + y_tile][SIZE_TILE * map_x + SIZE_TILE + x_tile], cub->colors[WHITE]);
			x_tile++;
		}
        y_tile++;
    }
}

void draw_player(t_cub *cub, int color)
{
	int x_start;
	int y_start;
	int x_end;
	int	y_end;
	int width;
	
	width = 4;
	y_start = (int)(cub->player->pos.y * SIZE_TILE) - width; // cub->player->w;
	x_start = (int)(cub->player->pos.x * SIZE_TILE) - width; //cub->player->w;
	x_end = (int)(cub->player->pos.x * SIZE_TILE) + width; //cub->player->w;
	y_end = (int)(cub->player->pos.y * SIZE_TILE) + width; //cub->player->w;
	cub->player->sommet[TL] = cub->win->index[y_start + SIZE_TILE][x_start + SIZE_TILE];
	cub->player->sommet[TR] = cub->win->index[y_start + SIZE_TILE][x_end + SIZE_TILE - 1];
	cub->player->sommet[BL] = cub->win->index[y_end + SIZE_TILE - 1][x_start + SIZE_TILE];
	cub->player->sommet[BR] = cub->win->index[y_end + SIZE_TILE - 1][x_end + SIZE_TILE - 1];
	while (y_start < y_end)
	{
		x_start = (int)(cub->player->pos.x * SIZE_TILE) - width; //cub->player->w;
		while (x_start < x_end)
		{
			set_pixel(cub, cub->win->index[y_start + SIZE_TILE][x_start + SIZE_TILE], cub->colors[color]);
			x_start++;
		}
		y_start++;
	}
}	

void draw_minimap(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map->map_grid[y])
	{
		x = 0;
		while (cub->map->map_grid[y][x])
		{
			if (cub->map->map_grid[y][x] == '1')
				draw_tile(cub, x, y, WHITE);
			else if (cub->map->map_grid[y][x] == '0' || cub->map->map_grid[y][x] == 'W' || cub->map->map_grid[y][x] == 'N' || cub->map->map_grid[y][x] == 'E' || cub->map->map_grid[y][x] == 'S')
				draw_tile(cub, x, y, BLACK);
			x++;
		}
		y++;
	}
}