/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:41:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/12 15:09:27 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

	typedef struct s_img
	{
		void	*ptr;
		char	*addr;
		int		bits_per_pixel;
		int		size_line;
		int		endian;
		int		offset;
		int		pixel; // ca sert a quelque chose ?
		//unsigned int		*pixels[];
		
	}			t_img;

#endif