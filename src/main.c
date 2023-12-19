/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:43 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 22:20:26 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../libft/src/strings/ft_putstr_fd.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../inc/cube3D.h"
#include "../minilibx-linux/mlx.h"

void	create_window(t_cub *cub3D);
int		ft_check_file_ext(char *s);
int		load_textures(t_cub *cub3D);

int	init_cub3D(t_cub *cub3D)
{
	cub3D->win = malloc(sizeof(t_win));
	if (cub3D->win == NULL)
		return (0);
	cub3D->win->mlx_ptr = mlx_init();
	if (cub3D->win->mlx_ptr == NULL)
		return (0);
	// if (load_textures(win, textures) == 0)
	// 	return ;
	return (1);
}

int main(int ac, char **av)
{
	t_cub cub3D;
	
	if (ac != 2)
	{
		ft_putstr_fd("Error\nYou must have 1 argument\n", 2);
		return (1);
	}
	if (ft_check_file_ext(av[1]) == 0)
		return (1);
	cub3D.fd = open(av[1], O_RDONLY);
	if (cub3D.fd < 0)
	{
		ft_putstr_fd("Error\nCould not open the file\n", 2);
		return (1);
	}
	// parser et charger la carte
	if (init_cub3D(&cub3D) == 0)
		return (1);
	create_window(&cub3D);
}
