/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:43 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 15:03:37 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac, char **av)
{
	t_cub	cub;
	
	(void)ac;
	(void)av;
	
	if (init_cub3D(&cub) == 0)
		return (printf("Error\nMemory allocation fail\n"), 1);
	if (init_map_test(&cub) == 0)
		return 1;
	//draw_first_image(&cub);
	create_window(&cub);
	//ray_casting(&cub);
	free_all(&cub, 2, 4);
	return (0);
}
