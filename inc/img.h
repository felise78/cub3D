/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:41:41 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/23 14:20:42 by hemottu          ###   ########.fr       */
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
		
	}			t_img;

#endif