/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:46 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/12 16:08:33 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3D.h"
#include "textures.h"

int	map_to_grid(t_cub *cub3D)
{
	int 	i;
	int		j;
	char	*charset;

	charset = "1 ";
	i = 0;
	while (cub3D->file->file_grid[i])
	{
		j = 0;
		while (cub3D->file->file_grid[i][j])
		{
			if (!in_charset(cub3D->file->file_grid[i][j], charset))
				break;
			j++;
		}
		if (!cub3D->file->file_grid[i][j])
		{
			cub3D->map->map_grid = &(cub3D->file->file_grid[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map(t_cub *cub3D)
{
	if (!map_is_last(cub3D))
		return (free_all(cub3D, 1, 4), 1);
	if (map_has_nl(cub3D))
		return (free_all(cub3D, 1, 4), 2);
	if (map_to_grid(cub3D))
		return (3);
	/*CHECK GRID*/
	int i = 0;
	while (cub3D->map->map_grid[i])
	{
		ft_dprintf(1, "%s\n", cub3D->map->map_grid[i]);
		i++;
	}
	if (set_map_dimensions(cub3D))
		return (free_all(cub3D, 1, 4), 4);
	if (!map_enclosed(cub3D))
		return (free_all(cub3D, 1, 4), 4);
	return (0);
}

int	check_textures(t_cub *cub3D)
{
	const char	textures_array[7][4] = {"NO ", "EA ", "SO ", "WE ", "C ", "F "};
	int			i;

	i = 0;
	while (textures_array[i] && textures_array[i][0])
	{
		if (check_texture_number((char *)(textures_array[i]), cub3D,
			ft_strlen(textures_array[i])))
		{
			free_all(cub3D, 1, i);
			return (1);
		}
		if (i < 4) 
			set_texture_pointers(cub3D, &(cub3D->textures->directions[i]), (char *)textures_array[i], i);	
		i++;
	}
	if (check_textures_valid(cub3D, "C "))
		return (1);
	if (check_textures_valid(cub3D, "F "))
		return (1);
	/*Checking if all 6 textures exist*/
	for (i = 0; i < 3; i++)
	{
		ft_dprintf(1, "Ceiling value %d is: %d\n", i, cub3D->textures->ceiling[i]);
		ft_dprintf(1, "Floor value %d is: %d\n", i, cub3D->textures->floor[i]);
	}
	for (i = 0; i < 4; i++)
		ft_dprintf(1, "%s\n", cub3D->textures->directions[i]);
	return (0);
	/**/
}

int	check_errors(t_cub *cub3D)
{
	if (ft_check_file_ext(cub3D->file->filename))
		return (1);
	if (check_map_printable(cub3D->file->filename)) //also checks if file exists, if .cub is directory
		return (2);
	if (copy_file(cub3D))
		return (3);
	if (check_file_pollution(cub3D))
		return (4);
	if (check_textures(cub3D))
		return (5);
	if (check_map(cub3D))
		return (6);
	return (0);
}
