/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:51 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/11 14:53:25 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <stdlib.h>

// void	get_pixel(t_img *img, int x, int y)
// {
// 	img->offset = (x * (img->bits_per_pixel / 8)) + (y * img->size_line);
// 	img->pixel = *(unsigned int *)(img->addr + img->offset);
// }

// void	put_pixel(t_img *canvas, int x, int y, t_img *img)
// {
// 	canvas->offset = (x * (canvas->bits_per_pixel / 8))
// 		+ (y * canvas->size_line);
// 	*(unsigned int *)(canvas->addr + canvas->offset) = img->pixel;
// }

void	draw_background(t_cub *cub3D)
{
	int x;
	int y;

	x = 0;
	while (x < cub3D->win->width)
	{
		y = 0;
		while(y < cub3D->win->height)
		{
			mlx_pixel_put(cub3D->win->mlx_ptr, cub3D->win->win_ptr, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}	
}

int loop(t_cub *cub3D)
{
	
	draw_little_map(cub3D);

	return (0);
}