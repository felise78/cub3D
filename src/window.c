/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:07 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/11 15:37:41 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_cub *cub3D)
{
	int i;

	i = 0;
	while (cub3D->map[i])
	{
		free(cub3D->map[i]);
		i++;
	}
	free(cub3D->map[i]);
	free(cub3D->map);
	mlx_destroy_image(cub3D->win->mlx_ptr, cub3D->canvas->ptr);
	mlx_destroy_window(cub3D->win->mlx_ptr, cub3D->win->win_ptr);
	mlx_destroy_display(cub3D->win->mlx_ptr);
	free(cub3D->win->mlx_ptr);
	free_all(cub3D, 2, 4);
	free(cub3D->win);
	free(cub3D->player);
	free(cub3D->camera);
	free(cub3D->canvas);
	// bien free tout ce qu'il y a a free ici 
	exit(0);
}

void	create_window(t_cub *cub3D)
{
	cub3D->win->win_ptr = mlx_new_window(cub3D->win->mlx_ptr, cub3D->win->width, cub3D->win->height, "CHIPS3D");
	if (cub3D->win->win_ptr == NULL)
	{
		mlx_destroy_display(cub3D->win->mlx_ptr);
		return ;
	}
	draw_background(cub3D);
	mlx_hook(cub3D->win->win_ptr, DestroyNotify, 0, close_window, cub3D);
	mlx_hook(cub3D->win->win_ptr, KeyPress, KeyPressMask, handle_keypress, cub3D);
	mlx_hook(cub3D->win->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, cub3D);
	mlx_loop_hook(cub3D->win->mlx_ptr, loop, cub3D);
	mlx_loop(cub3D->win->mlx_ptr); // cette loupe garde la fenetre ouverte
}