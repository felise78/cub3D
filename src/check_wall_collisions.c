/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_collisions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:10:01 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 13:17:35 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define GAP2 0.2 // trouver un autre nom et le mettre dans une struct ? 

int is_pixel_white(t_cub *cub, int index)
{
	t_pix pixel;
	
	pixel.B = cub->screen->addr[index * (cub->screen->bits_per_pixel / 8)];
    pixel.G = cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 1];
    pixel.R = cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 2];
    if (pixel.B == 255 && pixel.G == 255 && pixel.R == 255)
		return (1);
	else 
		return (0);
}

// essayer de voir comment je peux checker sur quelle case de la map est le pixel

int check_if_wall(t_cub *cub, float x, float y) 
{ 
	if (x < 0) 
	{
		if (is_pixel_white(cub, cub->player->sommet[TL] - 1) || is_pixel_white(cub, cub->player->sommet[BL] - 1))
			return (0);
	}
	else if (x > 0)
	{
		if (is_pixel_white(cub, cub->player->sommet[BR] + 1) || is_pixel_white(cub, cub->player->sommet[TR] + 1))
			return (0);
	}
	else if (y < 0)
	{
		if (is_pixel_white(cub, cub->player->sommet[TL] - cub->win->w) || is_pixel_white(cub, cub->player->sommet[TR] - cub->win->w))
			return (0);
	}
	else if (y > 0)
	{
		if (is_pixel_white(cub, cub->player->sommet[BR] + cub->win->w) || is_pixel_white(cub, cub->player->sommet[BL]+ cub->win->w))
			return (0);
	}
	return (1);
}