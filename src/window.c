/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:07 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/18 20:19:32 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/window.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

int	handle_keypress(int keysym, t_win *win);

int	ft_close_window(t_win *win)
{
	// if (game->floor)
	// 	mlx_destroy_image(game->mlx_ptr, game->floor);
	// if (game->wall)
	// 	mlx_destroy_image(game->mlx_ptr, game->wall);
	// if (game->key)
	// 	mlx_destroy_image(game->mlx_ptr, game->key);
	// if (game->bat)
	// 	mlx_destroy_image(game->mlx_ptr, game->bat);
	// if (game->exit)
	// 	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	//ft_free(win->map);
	exit(0);
}

void	ft_create_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		return ;
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			720, 900, "CHIPS3D");
	if (win->win_ptr == NULL)
	{
		mlx_destroy_display(win->mlx_ptr);
		return ;
	}
	// if (!ft_load_textures(game))
	// {
	// 	ft_putstr("Error\nDid not find all the images\n");
	// 	ft_close_window(game);
	// 	return ;
	// }
	//ft_draw_img(game);
	//game->g_exit = 0;
	mlx_hook(win->win_ptr, DestroyNotify, 0, ft_close_window, win);
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, handle_keypress, win);
	// je crois il faut aussi gerer le key release 
	mlx_loop(win->mlx_ptr);
}