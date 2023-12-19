/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:39:41 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 12:40:23 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

	typedef struct s_tex
	{
		void	*north;
		void	*east;
		void	*west;
		void	*south;
	}			t_tex;

#endif