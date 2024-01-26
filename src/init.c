/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:43:06 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 21:44:50 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int init_index(t_cub *cub)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	cub->win->index = (int **)malloc(sizeof(int *) * cub->win->h);
	if (!cub->win->index)
		return (0);
	while (y < cub->win->h)
	{
		cub->win->index[y] = (int *)malloc(sizeof(int) * cub->win->w);
		if (!cub->win->index[y])
			return (0);
		y++;
	}
	y = 0;
	x = 0;
	while (i < cub->win->total_pixels)
	{
		cub->win->index[y][x] = i;
		i++;
		x++;
		if (x == cub->win->w)
		{
			y++;
			x = 0;
		}
	}
	return (1);
}

// int load_textures(t_cub *cub)
// {
// 	int	w;
// 	int h;

// 	cub->textures->img[NORTH]->ptr = mlx_xpm_file_to_image(cub->win->mlx_ptr,
// 			"images/floor.xpm", &size, &size);
// 	cub->textures->img[EAST]->ptr = mlx_xpm_file_to_image(cub->win->mlx_ptr,
// 			"images/wall.xpm", &size, &size);
// 	cub->textures->img[SOUTH]->ptr = mlx_xpm_file_to_image(cub->win->mlx_ptr,
// 			"images/key.xpm", &size, &size);
// 	cub->textures->img[WEST]->ptr = mlx_xpm_file_to_image(cub->win->mlx_ptr,
// 			"images/bat.xpm", &size, &size);
// 	if ()
// 		return (0);
// 	else
// 		return (1);
// }
// 	return (0);
// 	return (1);
// }

int	init_pointers(t_cub *cub, t_file *file, t_tex *textures, char *filename)
{
	cub->file = file;
	cub->file->filename = filename;
	cub->textures = textures;
	cub->file->cub_file = NULL;
	cub->file->file_grid = NULL;
	cub->file->file_len = 0;
	return (0);
}

int	init_cub3D(t_cub *cub)
{
	cub->win = malloc(sizeof(t_win));
	if (cub->win == NULL)
		return (0);
	cub->win->mlx_ptr = mlx_init();
	if (cub->win->mlx_ptr == NULL)
		return (0);
	// if (load_textures(cub) == 0)
	// 	return ;
	cub->screen = malloc (sizeof(t_img) * 1);
	if (!cub->screen)
		return (0);
	cub->map = malloc(sizeof(t_map) * 1);
	if (!cub->map)
		return (0);
	mlx_get_screen_size(cub->win->mlx_ptr, &cub->win->w, &cub->win->h);
	cub->win->total_pixels = cub->win->w * cub->win->h;
	cub->screen->ptr = mlx_new_image(cub->win->mlx_ptr, cub->win->w, cub->win->h);
	if (!cub->screen->ptr)
		return (0);
	cub->screen->addr = mlx_get_data_addr(cub->screen->ptr, &cub->screen->bits_per_pixel, &cub->screen->size_line, &cub->screen->endian);
	if (!cub->screen->addr)
		return (0);
	if (init_colors(cub) == 0)
		return (0);
	if (init_index(cub) == 0)
		return (0);
	cub->rays = malloc(sizeof(t_ray) * cub->win->w);
	if (!cub->rays)
		return (0);
	return (1);
}