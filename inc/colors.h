/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:40 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 20:57:21 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

	#define NB_COLORS 8
	
	enum colors {
		WHITE,
		BLACK,
		LIGHTGREY,
		GREY,
		YELLOW,
		RED,
		GREEN,
		BLUE,
	};

	typedef struct s_pix
	{
		unsigned char R;
		unsigned char G;
		unsigned char B;
		unsigned char A;
	} t_pix;

#endif