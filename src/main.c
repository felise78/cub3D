/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:43 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/11 15:36:23 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include "cub3D.h"

void	get_screen_size(t_cub *cub3D)
{
   Display* display = XOpenDisplay(NULL);
   if (display == NULL) {
       printf("Impossible d'ouvrir le display\n");
       return;
   }

   int screenNumber = DefaultScreen(display);
   Window rootWindow = RootWindow(display, screenNumber);

   XWindowAttributes windowAttr;
   XGetWindowAttributes(display, rootWindow, &windowAttr);

	cub3D->win->width = windowAttr.width;
	cub3D->win->height = windowAttr.height;

   XCloseDisplay(display);
   return;
}

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
	cub3D->player = malloc(sizeof(t_pos) * 1);
	if (!cub3D->player)
		return (0);
	cub3D->camera = malloc (sizeof(t_fov) * 1);
	if (!cub3D->camera)
		return (0);
	cub3D->canvas = malloc (sizeof(t_img) * 1);
	if (!cub3D->canvas)
		return (0);
	get_screen_size(cub3D);
	cub3D->canvas->ptr = mlx_new_image(cub3D->win->mlx_ptr, cub3D->win->width, cub3D->win->height);
	if (!cub3D->canvas->ptr)
		return (0);
	// cub3D->canvas->addr = mlx_get_data_addr(cub3D->canvas->ptr,
	// 		&cub3D->canvas->bits_per_pixel, &cub3D->canvas->size_line,
	// 		&cub3D->canvas->endian);
	// if (!cub3D->canvas->addr)
	// 	return (0);
	return (1);
}

int	init_pointers(t_cub *cub3D, t_file *file, t_tex *textures, char *filename)
{
	cub3D->file = file;
	cub3D->file->filename = filename;
	cub3D->textures = textures;
	cub3D->file->cub_file = NULL;
	cub3D->file->file_grid = NULL;
	cub3D->file->file_len = 0;
	return (0);
}


int main(int ac, char **av)
{
	t_cub	cub3D;
	t_tex	textures;
	t_file	file;
	
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nYou must have 1 argument\n");
		return (1);
	}
	if (init_pointers(&cub3D, &file, &textures, av[1]))
		return (2);
	if (check_errors(&cub3D))
		return (1);
	// if (load_map_and_tex(&cub3D))
	// 	return (1);
	if (init_cub3D(&cub3D) == 0)
		return (printf("Error\nMemory allocation fail\n"), 1);
	// parser et charger la carte
	if (init_map_test(&cub3D) == 0)
		return 1;
	//draw_first_image(&cub3D);
	create_window(&cub3D);
	free_all(&cub3D, 2, 4);
	return (0);
}

// Makefile :
// changer les messages 