/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:58:48 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 19:07:59 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void rotate(t_cub *cub, int keysym)
{
	float oldDirX = cub->camera->dir.x;
   	float oldPlaneX = cub->camera->plane.x;
	if (keysym == XK_Right)
	{
      cub->camera->dir.x = oldDirX * cub->camera->cosRot - cub->camera->dir.y * cub->camera->sinRot;
      cub->camera->dir.y = oldDirX * cub->camera->sinRot + cub->camera->dir.y * cub->camera->cosRot;
      cub->camera->plane.x = oldPlaneX * cub->camera->cosRot - cub->camera->plane.y * cub->camera->sinRot;
      cub->camera->plane.y = oldPlaneX * cub->camera->sinRot + cub->camera->plane.y * cub->camera->cosRot;
	}
	else if (keysym == XK_Left)
	{
	  cub->camera->dir.x = oldDirX * cub->camera->cosRot + cub->camera->dir.y * cub->camera->sinRot;
      cub->camera->dir.y = -oldDirX * cub->camera->sinRot + cub->camera->dir.y * cub->camera->cosRot;
      cub->camera->plane.x = oldPlaneX * cub->camera->cosRot + cub->camera->plane.y * cub->camera->sinRot;
      cub->camera->plane.y = -oldPlaneX * cub->camera->sinRot + cub->camera->plane.y * cub->camera->cosRot;
	}
	draw_img(cub);
}