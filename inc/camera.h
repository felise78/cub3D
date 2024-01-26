/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:53:01 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 18:55:19 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

	typedef struct s_cam 
	{
		t_vec dir;
		t_vec plane;
		float rotSpeed;
		float cosRot;
		float _cosRot;
		float sinRot;
		float _sinRot;
		
	} t_cam;

 #endif