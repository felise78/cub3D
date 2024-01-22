/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:56:05 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 11:04:10 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

	typedef struct s_win
	{
		void	*mlx_ptr;
		void	*win_ptr;
		int		w;
		int		h;
		int		total_pixels;
		int		**index;
	}				t_win;

#endif