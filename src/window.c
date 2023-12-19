/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:07 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 22:15:05 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3D.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

int	handle_keypress(int keysym, t_cub *cub3D);
int handle_keyrelease(int keysym, t_cub *cub3D);

int	close_window(t_cub *cub3D)
{
	// bien free tout ce qu'il y a a free ici
	mlx_destroy_window(cub3D->win->mlx_ptr, cub3D->win->win_ptr);
	mlx_destroy_display(cub3D->win->mlx_ptr);
	free(cub3D->win->mlx_ptr);
	free(cub3D->win);
	exit(0);
}

void	create_window(t_cub *cub3D)
{
	cub3D->win->win_ptr = mlx_new_window(cub3D->win->mlx_ptr, 720, 900, "CHIPS3D"); 
	// ici modifier les valeurs de la taille de fenetre
	// aller chercher la taille de l'ecran ?
	if (cub3D->win->win_ptr == NULL)
	{
		mlx_destroy_display(cub3D->win->mlx_ptr);
		return ;
	}
	// draw la premiere image
	mlx_hook(cub3D->win->win_ptr, DestroyNotify, 0, close_window, cub3D);
	mlx_hook(cub3D->win->win_ptr, KeyPress, KeyPressMask, handle_keypress, cub3D);
	mlx_hook(cub3D->win->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, cub3D);
	mlx_loop(cub3D->win->mlx_ptr);
}