/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:29 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/19 17:01:54 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int init_colors (t_cub *cub)
{
	cub->colors = malloc(sizeof(char *) * NB_COLORS);
	if (!cub->colors)
		return (0);
	cub->colors[WHITE] = ft_strdup("FFFFFFFF");
	cub->colors[BLACK] = ft_strdup("000000FF");
	cub->colors[GREY] = ft_strdup("888888FF");
	cub->colors[YELLOW] = ft_strdup("FFFF00FF");
	cub->colors[DARKBLUE] = ft_strdup("001633FF");
	return (1);
}

// format 	RED		GREEN	BLUE	ALPHA