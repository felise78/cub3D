/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 11:48:57 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

typedef struct s_cub	t_cub;

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
		int		floor[3]; // le mettre direct en unsigned char ?
		int		ceiling[3]; // le mettre direct en unsigned char ?
	}			t_tex;

/*PARSING*/
int		check_texture_number(char *identifier, t_cub *cub3D, int option);
void	set_texture_pointers(t_cub *cub3D, char **dir_pointer, char *ID, int i);

#endif