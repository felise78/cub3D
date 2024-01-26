/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:29 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 21:09:31 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int init_colors (t_cub *cub)
{
	cub->colors = malloc(sizeof(int *) * NB_COLORS);
	if (!cub->colors)
		return (0);
	int i = 0;
	while (i < NB_COLORS)
		cub->colors[i++] = malloc(sizeof(int) * 3);
	cub->colors[WHITE][0] = 255;
	cub->colors[WHITE][1] = 255;
	cub->colors[WHITE][2] = 255;
	cub->colors[BLACK][0] = 0;
	cub->colors[BLACK][1] = 0;
	cub->colors[BLACK][2] = 0;
	cub->colors[LIGHTGREY][0] = 230;
	cub->colors[LIGHTGREY][1] = 230;
	cub->colors[LIGHTGREY][2] = 230;
	cub->colors[GREY][0] = 63;
	cub->colors[GREY][1] = 63;
	cub->colors[GREY][2] = 63;
	cub->colors[YELLOW][0] = 255;
	cub->colors[YELLOW][1] = 255;
	cub->colors[YELLOW][2] = 0;
	cub->colors[RED][0] = 255;
	cub->colors[RED][1] = 0;
	cub->colors[RED][2] = 0;
	cub->colors[GREEN][0] = 0;
	cub->colors[GREEN][1] = 255;
	cub->colors[GREEN][2] = 0;
	cub->colors[BLUE][0] = 0;
	cub->colors[BLUE][1] = 0;
	cub->colors[BLUE][2] = 255;
	return (1);
}

// void	ft_get_pixel(t_img *img, int x, int y)
// {
// 	img->offset = (x * (img->bits_per_pixel / 8)) + (y * img->size_line);
// 	img->pixel = *(unsigned int *)(img->addr + img->offset);
// }

// void	ft_put_pixel(t_img *canvas, int x, int y, t_img *img)
// {
// 	canvas->offset = (x * (canvas->bits_per_pixel / 8))
// 		+ (y * canvas->size_line);
// 	*(unsigned int *)(canvas->addr + canvas->offset) = img->pixel;
// }