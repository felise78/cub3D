/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:07 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 12:21:55 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/window.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

int	handle_keypress(int keysym, t_win *win);
int handle_keyrelease(int keysym, t_win *win);

int	ft_close_window(t_win *win)
{
	// bien free tout ce qu'il y a a free ici
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
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
	// loader les textures
	// draw la premiere image
	mlx_hook(win->win_ptr, DestroyNotify, 0, ft_close_window, win);
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, handle_keypress, win);
	mlx_hook(win->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, win);// je crois il faut aussi gerer le key release 
	mlx_loop(win->mlx_ptr);
}