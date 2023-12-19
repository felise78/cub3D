/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:39:28 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 22:15:57 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/window.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "../inc/cube3D.h"


int	close_window(t_cub *cub3D);

int	handle_keypress(int keysym, t_cub *cub3D)
{
	if (keysym == XK_Escape)
		close_window(cub3D);
	else if (keysym == XK_a)
		; // deplace le personnage
	else if (keysym == XK_d)
		; // deplace le personnage
	else if (keysym == XK_s)
		; // deplace le personnage
	else if (keysym == XK_w)
		; // deplace le personnage
	else if (keysym == XK_Left)
		; // rotate la camera
	else if (keysym == XK_Up)
		; // rotate la camera
	else if (keysym == XK_Right)
		; // rotate la camera
	else if (keysym == XK_Down)
		; // rotate la camera
	return (1);
}

int handle_keyrelease(int keysym, t_cub *cub3D)
{
	(void)cub3D; //
	if (keysym == XK_Left)
		; // arreter de rotate la camera ?
	else if (keysym == XK_Up)
		; // arreter de rotate la camera ?
	else if (keysym == XK_Right)
		; // arreter de rotate la camera ?
	else if (keysym == XK_Down)
		; // arreter de rotate la camera ?
	return (1);
}