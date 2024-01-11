/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:50:15 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/02 16:38:05 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "window.h"
#include "cub3D.h"

int	load_textures(t_cub *cub3D)
{
	int	size;

	cub3D->textures->north = mlx_xpm_file_to_image(cub3D->win->mlx_ptr,
			"images/floor.xpm", &size, &size);
	cub3D->textures->east = mlx_xpm_file_to_image(cub3D->win->mlx_ptr,
			"images/wall.xpm", &size, &size);
	cub3D->textures->west = mlx_xpm_file_to_image(cub3D->win->mlx_ptr,
			"images/key.xpm", &size, &size);
	cub3D->textures->south = mlx_xpm_file_to_image(cub3D->win->mlx_ptr,
			"images/bat.xpm", &size, &size);
	if (cub3D->textures->north == NULL || cub3D->textures->east == NULL
		|| cub3D->textures->west == NULL || cub3D->textures->south == NULL)
		return (0);
	else
		return (1);
}