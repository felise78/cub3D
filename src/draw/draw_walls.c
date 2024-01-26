/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:45:04 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 15:45:11 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_pixcolumn(t_cub *cub, int x, int y0, int y1)
{
	int *color;

	// a changer par les textures

	if (cub->rays[x].side == 0)
		color = &cub->colors[GREEN][0];
	else if (cub->rays[x].side == 1)
		color = &cub->colors[BLUE][0];
	else if (cub->rays[x].side == 2)
		color = &cub->colors[RED][0];
	else if (cub->rays[x].side == 3)
		color = &cub->colors[YELLOW][0];
	while (y0 < y1)
	{
		set_pixelRGB(cub, cub->win->index[y0][x], color);
		y0++;
	}
}

void draw_walls(t_cub *cub)
{
    int x;

    x = 0;
    while (x < cub->win->w)
    {
   		 if(cub->rays[x].side == EAST || cub->rays[x].side == WEST) 
	  		cub->rays[x].perpWallDist = (cub->rays[x].sideDistX - cub->rays[x].deltaDistX);
     	 else         
	  		cub->rays[x].perpWallDist = (cub->rays[x].sideDistY - cub->rays[x].deltaDistY);
	
      int lineHeight = (int)(cub->win->h / cub->rays[x].perpWallDist);
	  
      int wallStrat = -lineHeight / 2 + cub->win->h / 2;
      if(wallStrat < 0) wallStrat = 0;
      int wallEnd = lineHeight / 2 + cub->win->h / 2;
      if(wallEnd >= cub->win->h)
          wallEnd = cub->win->h - 1;
      draw_pixcolumn(cub, x, wallStrat, wallEnd);
    x++;
    }
}