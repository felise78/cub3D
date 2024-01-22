/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:40 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/19 16:48:36 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

	#define NB_COLORS 5
	
	enum colors {
		WHITE,
		BLACK,
		GREY,
		YELLOW,
		DARKBLUE,
	};

	typedef struct s_pix
	{
		unsigned char R;
		unsigned char G;
		unsigned char B;
		unsigned char A;
	} t_pix;

#endif