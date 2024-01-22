/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:46 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/19 18:42:47 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

	enum sommets {
		TL, // top left
		TR, // top right
		BL, // bottom left
		BR, // bottom right
	};

	typedef struct s_vec
	{
		float x;
		float y;
	} t_vec;

	typedef struct s_pos
	{
		t_vec pos;
		t_vec dir;
		t_vec plane; // le plane de la camera
		float fov;
		// sur quel carre de la map il se trouve
		int mapX; 
		int mapY;
		int	sommet[4]; // jspr trouver une meilleure solution ... 
	}	t_pos;

	// typedef struct s_fov
	// {
	// } t_fov;
	
#endif