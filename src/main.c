/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:43 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 16:14:36 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac, char **av)
{
	t_cub	cub;
	// t_tex	textures;
	// t_file	file;
	// t_map	map;
	
	(void)ac;
	(void)av;
	// if (ac != 2)
	// {
	// 	ft_dprintf(2, "Error\nYou must have 1 argument\n");
	// 	return (1);
	// }
	// if (init_pointers(&cub, &file, &textures, av[1]))
	// 	return (2);
	// cub.map = &map;
	// if (check_errors(&cub))
	// 	return (1);
	if (init_cub3D(&cub) == 0)
		return (printf("Error\nMemory allocation fail\n"), 1);
	if (init_map_test(&cub) == 0)
		return 1;
	//calculate_rays(&cub);
	create_window(&cub);
	free_all(&cub, 3, 4);
	return (0);
}