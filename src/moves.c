/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:58 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 15:13:45 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define GAP 0.1 // speed ?
#define GAP2 0.2



static int	modify_player_data(t_cub *cub, float x, float y)
{
	if (check_if_wall(cub, x, y) == 0)
		return(0);
	cub->player->pos.x += x;
	cub->player->pos.y += y;
	cub->player->mapX = (int)cub->player->pos.x;
	cub->player->mapY = (int)cub->player->pos.y;
	return (1);
}

// void	move_player(t_cub *cub, int keysym)
// {
// 	draw_player(cub, BLACK);
// 	if (keysym == XK_a)
// 	{
// 		if (modify_player_data(cub, -GAP, 0) == 0)
// 			return;
// 	}
// 	else if (keysym == XK_d)
// 	{
// 		if (modify_player_data(cub, GAP, 0) == 0)
// 			return;
// 	}
// 	else if (keysym == XK_s)
// 	{
// 		if (modify_player_data(cub, 0, GAP) == 0)
// 			return;
// 	}
// 	else if  (keysym == XK_w)
// 	{
// 		if (modify_player_data(cub, 0, -GAP) == 0)
// 			return;
// 	}
// 	draw_player(cub, YELLOW);
// }

void	move_player(t_cub *cub, int keysym)
{
	draw_player(cub, BLACK);
	if (keysym == XK_a)
		modify_player_data(cub, -GAP, 0);
	else if (keysym == XK_d)
		modify_player_data(cub, GAP, 0);
	else if (keysym == XK_s)
		modify_player_data(cub, 0, GAP);
	else if  (keysym == XK_w)
		modify_player_data(cub, 0, -GAP);
	draw_player(cub, YELLOW);
}