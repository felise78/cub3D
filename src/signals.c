/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:39:28 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/18 20:18:33 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/window.h"
#include <X11/X.h>
#include <X11/keysym.h>


int	ft_close_window(t_win *win);

int	handle_keypress(int keysym, t_win *win)
{
	if (keysym == XK_Escape)
		ft_close_window(win);
	else if (keysym == XK_a)
		write(1, "A", 1);
	else if (keysym == XK_d)
		write(1, "D", 1);
	else if (keysym == XK_s)
		write(1, "S", 1);
	else if (keysym == XK_w)
		write(1, "W", 1);
	else if (keysym == XK_Left)
		write(1, "left", 4);
	else if (keysym == XK_Up)
		write(1, "up", 2);
	else if (keysym == XK_Right)
		write(1, "right", 5);
	else if (keysym == XK_Down)
		write(1, "down", 4);
	return (1);
}