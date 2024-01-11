/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/09 18:04:33 by pichatte         ###   ########.fr       */
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
		void	*floor;
		void	*ceiling;
	}			t_tex;

/*PARSING*/
int		check_texture_number(char *identifier, t_cub *cub3D, int option);
void	set_texture_pointers(t_cub *cub3D, char **dir_pointer, char *ID, int i);

#endif