/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_first_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:38:16 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 20:02:25 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	allocate_structs(t_cub *cub)
{
	cub->player = malloc(sizeof(t_pos) * 1);
	if (!cub->player)
		return (ft_dprintf(2, "Error: Failed memory allocation"), 1);
	cub->camera = malloc (sizeof(t_cam) * 1);
	if (!cub->camera)
		return (ft_dprintf(2, "Error: Failed memory allocation"), free(cub->player), 2);
	cub->camera->rotSpeed = 0.4;
	cub->camera->cosRot = cos(cub->camera->rotSpeed);
	cub->camera->sinRot = sin(cub->camera->rotSpeed);
	cub->player->speed = 0.4;
	return (0);
}

static void	set_dir_vector(t_cub *cub, char dir)
{
	if (dir == 'N')
	{
		cub->camera->dir.x = 0;
		cub->camera->dir.y = -1;
		cub->camera->plane.x = 0.66;
		cub->camera->plane.y = 0;
	}	
	else if (dir == 'W')
	{
		cub->camera->dir.x = -1;
		cub->camera->dir.y = 0;
		cub->camera->plane.x = 0;
		cub->camera->plane.y = -0.66;
	}	
	else if (dir == 'E')
	{
		cub->camera->dir.x = 1;
		cub->camera->dir.y = 0;
		cub->camera->plane.x = 0;
		cub->camera->plane.y = 0.66;
	}	
	else if (dir == 'S') 
	{
		cub->camera->dir.x = 0;
		cub->camera->dir.y = 1;
		cub->camera->plane.x = -0.66;
		cub->camera->plane.y = 0;
	}	
}

int	set_player_pos(t_cub *cub3D, int x, int y)
{
	if (allocate_structs(cub3D))
		return (1);
	cub3D->player->pos.x = x + 0.5;
	cub3D->player->pos.y = y + 0.5;
	cub3D->player->mapX = x;
	cub3D->player->mapY = y;
	set_dir_vector(cub3D, cub3D->map->map_grid[y][x]);
	return (0);
}

int	set_first_position(t_cub *cub3D)
{
    int 	x;
    int 	y;
	bool	player_exists;

	player_exists = false;
	y = 0;
	while (cub3D->map->map_grid[y])
    {
        x = 0;
        while(cub3D->map->map_grid[y][x])
        {
            if (cub3D->map->map_grid[y][x] == 'N' || cub3D->map->map_grid[y][x] == 'W'
				|| cub3D->map->map_grid[y][x] == 'E' || cub3D->map->map_grid[y][x] == 'S')
            {
				if (!player_exists)
				{
					if (set_player_pos(cub3D, x, y))
						return (free_all(cub3D, 1, 4), 1);
					player_exists = true;
				}
				else
					return (ft_dprintf(2, "Error: Too many players\n"), free_all(cub3D, 2, 4), 2);
			}
            x++;
        }
        y++;
    }
	if (!player_exists)
		return (ft_dprintf(2, "Error: Player not found\n"), free_all(cub3D, 1, 4), 3);
	return (0);
}
