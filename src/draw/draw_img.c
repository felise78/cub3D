/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:51 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/22 15:59:08 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void calcul_dist(t_cub *cub); // test

// void    draw_raycast(t_cub *cub)
// {
//     calculate_rays(cub);
// }

void	draw_raycast(t_cub *cub);

void draw_img(t_cub * cub)
{
    mlx_clear_window(cub->win->mlx_ptr, cub->win->win_ptr);
   // draw_background(cub);
  //  draw_raycast(cub);
    draw_minimap(cub);
    draw_player(cub, YELLOW);
 //   calcul_dist(cub);
}

void draw_background(t_cub *cub)
{
    int i = 0;
    
    while (i < cub->win->total_pixels) {
        set_pixel(cub, i, cub->colors[GREY]);
        i++;
    }
}

int loop(t_cub *cub)
{
   // mlx_clear_window(cub->win->mlx_ptr, cub->win->win_ptr);
    mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr, cub->screen->ptr, 0, 0);
	
	return (0);
}