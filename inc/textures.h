/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 20:39:24 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

typedef struct s_cub	t_cub;
typedef struct s_img	t_img;

	typedef enum s_direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST
	}	t_direction;

	typedef struct s_tex
	{
		char	*directions[4];
		t_img	*img[4];
		int		h[4];
		int		floor[3]; 
		int		ceiling[3]; 
	}			t_tex;
	
#endif