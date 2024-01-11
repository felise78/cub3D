/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:08:46 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/09 19:10:18 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//dda : digital differential analyser
// L'algorithme DDA est utilisé pour le tracé de lignes droites sur un écran d'ordinateur. 
// Il est particulièrement utile dans les applications graphiques, où il peut être utilisé 
// pour générer des lignes en calculant les coordonnées des pixels à tracer.



// FOV : field of view
// si le direction vector est pres de 0 : le FOV est de 180, ce qui est le 
// maximum
// if the direction vector and the camera plane vector have the same length
// the FOV est de 90*


// theoreme de Pythagore : c² = a² + b²;
// c = √(a² + b²);
// permet de calculer la distance entre le personnage et le mur


// //what direction to step in x or y-direction (either +1 or -1)
// int stepX;
// int stepY;
// int hit = 0; //was there a wall hit?
// int side; //was a NS or a EW wall hit?
// //calculate step and initial sideDist
// if(rayDirX < 0)
// {
// 	stepX = -1;
// 	sideDistX = (posX - mapX) * deltaDistX;
// }
// else
// {
// 	stepX = 1;
// 	sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// }
// if(rayDirY < 0)
// {
// 	stepY = -1;
// 	sideDistY = (posY - mapY) * deltaDistY;
// }
// else
// {
// 	stepY = 1;
// 	sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// }