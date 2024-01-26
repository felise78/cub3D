/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:51 by hemottu           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/25 21:44:39 by hemottu          ###   ########.fr       */
=======
/*   Updated: 2024/01/25 21:39:42 by hemottu          ###   ########.fr       */
>>>>>>> e88b4ae (degrade sol qui peut etre affecte aux valeurs de F)
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// RGBColor interpolateColors(RGBColor start, RGBColor end, float t) {
//     RGBColor result;
//     result.red = start.red + t * (end.red - start.red);
//     result.green = start.green + t * (end.green - start.green);
//     result.blue = start.blue + t * (end.blue - start.blue);
//     return result;
// }


static void draw_sky_and_floor(t_cub *cub)
{
    int rgb[3];
    int i = 0;
    float d;
    
    while (i < cub->win->total_pixels / 2) {
        set_pixelRGB(cub, i, cub->colors[WHITE]); // a modifier avec la valeur de C
        i++;
    }
    while (i < cub->win->total_pixels) {
        d = (float)i / (float)cub->win->total_pixels;
         // a modifier avec la valeur de F
        rgb[0] = cub->colors[LIGHTGREY][0] + d * -170;
        rgb[1] = cub->colors[LIGHTGREY][1] + d * -170;
        rgb[2] = cub->colors[LIGHTGREY][2] + d * -170;
        set_pixelRGB(cub, i, rgb);
        i++;
    }
}

void draw_img(t_cub * cub)
{
    draw_sky_and_floor(cub);
    calculate_rays(cub); 
    draw_walls(cub);
    draw_minimap(cub);
    draw_player(cub, YELLOW);
}


int loop(t_cub *cub)
{
    mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr, cub->screen->ptr, 0, 0);
	return (0);
}