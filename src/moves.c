/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:58 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 20:01:24 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall_colision(t_cub *cub, int keysym)
{
	if (keysym == XK_w)
	{
		cub->player->n_pos.x = cub->player->pos.x + cub->player->speed * cub->camera->dir.x;
		cub->player->n_pos.y = cub->player->pos.y + cub->player->speed * cub->camera->dir.y;
	}
	else if (keysym == XK_s)
	{
		cub->player->n_pos.x = cub->player->pos.x + -cub->player->speed * cub->camera->dir.x;
		cub->player->n_pos.y = cub->player->pos.y + -cub->player->speed * cub->camera->dir.y;
	}
	else if (keysym == XK_d)
	{
		cub->player->n_pos.x = cub->player->pos.x + cub->player->speed * cub->camera->plane.x;
		cub->player->n_pos.y = cub->player->pos.y + cub->player->speed * cub->camera->plane.y;
	}
	else if (keysym == XK_a)
	{
		cub->player->n_pos.x = cub->player->pos.x + -cub->player->speed * cub->camera->plane.x;
		cub->player->n_pos.y = cub->player->pos.y + -cub->player->speed * cub->camera->plane.y;
	}
	if (cub->map->map_grid[(int)(cub->player->n_pos.y)][(int)(cub->player->n_pos.x)] == '1')
		return (1);
	return (0);
}

void	move_player(t_cub *cub, int keysym)
{
	if (wall_colision(cub, keysym))
		return;
	cub->player->pos.x = cub->player->n_pos.x;
	cub->player->pos.y = cub->player->n_pos.y;
	cub->player->mapX = (int)cub->player->pos.x;
	cub->player->mapY = (int)cub->player->pos.y;
	draw_img(cub);
}