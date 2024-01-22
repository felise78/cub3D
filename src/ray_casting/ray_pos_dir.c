/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pos_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:17:20 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/19 17:08:10 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define DEPTH 12.0f

void calculate_rays(t_cub *cub)
{
	float rayAngle;
	int x;
	int y;
	bool hit;
	float distanceToWall = 0;

	x = 0;
	hit = false;
	while(x < cub->win->w) // probablement a refaire car dda algo fonctionnera mieux
	{
		rayAngle = (cub->player->ang - cub->player->fov / 2.0f) + ((float)x / (float)cub->win->w) * cub->player->fov;
		

		float EyeX = sinf(rayAngle); // unit vector for ray in player space
		float EyeY = cosf(rayAngle);
		
		while(!hit && distanceToWall < cub->map->map_len)
		{
			distanceToWall += 0.1f ;

			int TestX = (int)(cub->player->pos.x + EyeX * distanceToWall); // a remplacer par le dda algo ? // other video
			int TestY = (int)(cub->player->pos.y + EyeY * distanceToWall);

			if (TestX < 0 || TestX >= cub->map->map_len || TestY < 0 || TestY >= cub->map->map_height)
			{
				hit = true;
				distanceToWall = DEPTH; //set the distance to maximum depth in case it doesn't hit a wall
			}
			else
			{
				// ray is inbounds / test if the ray cell is a wall block
				if (cub->map->map_grid[TestY][TestX] == '1')
					hit = true;
			}
		}
		x++;
	}
			//calculate distance to ceiling and floor
	int ceiling = (float)(cub->win->h / 2.0) - cub->win->h / (float)distanceToWall;
	//int floor = cub->win->h - ceiling;
	y = 0;
	while (y < cub->win->h)
	{
		if (y < ceiling)
		{
			set_pixel(cub, cub->win->index[y][x], cub->colors[DARKBLUE]);
		}
		//else if (y > ceiling && y <= floor)
		y++;
	}
	
}

// PlayerX : cub->player->pos.x
// PlayerY : cub->player->pos.Y
// PlayerA : cub->player->ang // c'est pas ca du coup a la place de dir ?

// EyeX : // du coup ca je ne sais pas
// EyeY : // il dit : unit vector for ray in player space