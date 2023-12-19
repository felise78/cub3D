/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:59:49 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 13:12:14 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

	#include "window.h"
	#include "textures.h"

	typedef struct s_win t_win;
	
	typedef struct s_cub
	{
		t_win	*win;
		t_tex	*textures;
		int		fd;
	}				t_cub;

#endif