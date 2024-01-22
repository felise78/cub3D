/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:07 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 15:39:45 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->map->map_grid[i])
	{
		free(cub->map->map_grid[i]);
		i++;
	}
	free(cub->map->map_grid[i]);
	free(cub->map->map_grid);
	mlx_destroy_image(cub->win->mlx_ptr, cub->screen->ptr);
	mlx_destroy_window(cub->win->mlx_ptr, cub->win->win_ptr);
	mlx_destroy_display(cub->win->mlx_ptr);
	free(cub->win->mlx_ptr);
	//free_all(cub, 2, 4);
	free(cub->map);
	free(cub->win);
	free(cub->player);
	//free(cub->camera);
	free(cub->screen);
	i = 0;
	while (i < NB_COLORS)
		free(cub->colors[i++]);
	free(cub->colors);
	free(cub->win->index);
	// bien free tout ce qu'il y a a free ici 
	exit(0);
}

void	create_window(t_cub *cub)
{
	cub->win->win_ptr = mlx_new_window(cub->win->mlx_ptr, cub->win->w, cub->win->h, "CHIPS3D");
	if (cub->win->win_ptr == NULL)
	{
		mlx_destroy_display(cub->win->mlx_ptr);
		return ;
	}
	draw_img(cub);
	mlx_hook(cub->win->win_ptr, DestroyNotify, 0, close_window, cub);
	mlx_hook(cub->win->win_ptr, KeyPress, KeyPressMask, handle_keypress, cub);
	mlx_hook(cub->win->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, cub);
	mlx_loop_hook(cub->win->mlx_ptr, loop, cub); // put img to window is on loop;
	mlx_loop(cub->win->mlx_ptr); // cette loop garde la fenetre ouverte
}