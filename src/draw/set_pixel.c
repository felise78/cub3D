/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:50:34 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/24 16:05:26 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void set_pixelRGB(t_cub *cub, int index, const int *value)
{
    
    t_pix pixel;
    
    pixel.R = value[0];
    pixel.G = value[1];
    pixel.B = value[2];
    pixel.A = 255;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8)] = pixel.B;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 1] = pixel.G;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 2] = pixel.R;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 3] = pixel.A;
}