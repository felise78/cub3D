/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:56:05 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/09 16:59:19 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

	typedef struct s_win
	{
		void	*mlx_ptr;
		void	*win_ptr;
		int		width;
		int		height;
	}				t_win;

#endif