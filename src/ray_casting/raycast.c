/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:23:52 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 15:52:23 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void calculate_steps(t_cub *cub, int x)
{
  cub->rays[x].mapX = cub->player->mapX;
      cub->rays[x].mapY = cub->player->mapY;
      if(cub->rays[x].rayDirX < 0)
      {
        cub->rays[x].stepX = -1;
        cub->rays[x].sideDistX = (cub->player->pos.x - cub->rays[x].mapX) * cub->rays[x].deltaDistX;
      }
      else
      {
        cub->rays[x].stepX = 1;
        cub->rays[x].sideDistX = (cub->rays[x].mapX + 1.0 - cub->player->pos.x) * cub->rays[x].deltaDistX;
      }
      if(cub->rays[x].rayDirY < 0)
      {
        cub->rays[x].stepY = -1;
        cub->rays[x].sideDistY = (cub->player->pos.y - cub->rays[x].mapY) * cub->rays[x].deltaDistY;
      }
      else
      {
        cub->rays[x].stepY = 1;
        cub->rays[x].sideDistY = (cub->rays[x].mapY + 1.0 - cub->player->pos.y) * cub->rays[x].deltaDistY;
      }
}

void dda_algo(t_cub *cub, int x)
{
   int hit = 0;
   
     while(hit == 0)
      {

        if(cub->rays[x].sideDistX < cub->rays[x].sideDistY)
        {
          cub->rays[x].sideDistX += cub->rays[x].deltaDistX;
          cub->rays[x].mapX += cub->rays[x].stepX;
          if (cub->rays[x].stepX > 0)
            cub->rays[x].side = EAST;
          else
            cub->rays[x].side = WEST;
        }
        else
        {
          cub->rays[x].sideDistY += cub->rays[x].deltaDistY;
          cub->rays[x].mapY += cub->rays[x].stepY;
          if (cub->rays[x].stepY > 0)
            cub->rays[x].side = SOUTH;
          else
            cub->rays[x].side = NORTH;
        }
        if(cub->rays[x].mapY < 0 || cub->rays[x].mapX < 0 || cub->map->map_grid[cub->rays[x].mapY][cub->rays[x].mapX] == '1') // 
        {
			      hit = 1;
        }
    	}
}

void calculate_rays(t_cub *cub)
{
  int x;

  x = 0;
  while(x < cub->win->w)
  {
    cub->rays[x].cameraX = 2 * x / (float)cub->win->w - 1; 
    cub->rays[x].rayDirX = cub->camera->dir.x + cub->camera->plane.x * cub->rays[x].cameraX;
    cub->rays[x].rayDirY = cub->camera->dir.y + cub->camera->plane.y * cub->rays[x].cameraX;
    cub->rays[x].deltaDistX = (cub->rays[x].rayDirX == 0) ? 1e30 : fabs(1 / cub->rays[x].rayDirX);
    cub->rays[x].deltaDistY = (cub->rays[x].rayDirY == 0) ? 1e30 : fabs(1 / cub->rays[x].rayDirY);
    calculate_steps(cub, x);
    dda_algo(cub, x);
    x++;
  }
}