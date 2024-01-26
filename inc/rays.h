/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:24:50 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/24 17:09:08 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

	typedef struct s_ray{
		float cameraX;
		float rayDirX;
		float rayDirY;
		float sideDistX;
		float sideDistY;
		float deltaDistX;
		float deltaDistY;
		float perpWallDist;
		int	stepX;
		int stepY;
		int mapX;
		int mapY;
    	int side;
	} t_ray;

#endif