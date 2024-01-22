/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:03:52 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/12 15:53:55 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check double textures
// check path to texture
// check xpm?
#include "textures.h"
#include "cub3D.h"
#include "libft.h"

int	check_texture_number(char *identifier, t_cub *cub3D, int option)
{
	char	*first;

	if (!cub3D || !(cub3D->file->cub_file))
		return (1);
	first = ft_strnstr(cub3D->file->cub_file, identifier,
			cub3D->file->file_len);
	while (first && first != cub3D->file->cub_file && *(first - 1) != '\n')
		first = ft_strnstr(first + option, identifier, cub3D->file->file_len);
	if (!first)
	{
		ft_dprintf(2, "Error: You need 1 %stexture\n", identifier);
		return (2);
	}
	if (ft_strnstr(first + option, identifier, cub3D->file->file_len))
	{
		ft_dprintf(2, "Error: Too many %stextures\n", identifier);
		return (3);
	}
	return (0);
}

void	set_texture_pointers(t_cub *cub3D, char **dir_pointer, char *ID, int max_free)
{
	char		*pos;
	int			i;
	int			len;

	len = ft_strlen(ID);
	pos = ft_strnstr(cub3D->file->cub_file, ID, cub3D->file->file_len);
	i = 0;
	while (pos && pos[i] && pos[i] != '\n')
		i++;
	*dir_pointer = ft_substr(pos, len, i - len);//MALLOCED
	if (!(*dir_pointer))
	{
		free_all(cub3D, 1, max_free);
		exit (EXIT_FAILURE);
	}
}

int	check_textures_valid(t_cub *cub, char *ID)
{
	int		i;
	char	*pos;
	char	**values;
	
	i = 0;
	while (cub->file->file_grid[i])
	{
		if (ft_strnstr(cub->file->file_grid[i], ID,
			ft_strlen(cub->file->file_grid[i])) == cub->file->file_grid[i])
		pos = ft_strnstr(cub->file->file_grid[i], ID,
			ft_strlen(cub->file->file_grid[i])) + 2;
		i++;
	}
	values = ft_split(pos, ',');
	if (!values)
		return (1);
	if (check_RGB_valid(cub, ID, values))
		return (free_all(cub, 1, 4), 1);
	free_tab(values);
	return (0);	
}



int	check_RGB_valid(t_cub *cub, char *ID, char **values)
{
	int		i;
	int		n;

	if (tab_size(values) != 3)
		return (free_tab(values), ft_dprintf(2, "Error: 3 RGB codes required\n"), 2);
	i = 0;
	while (i < 3 && values[i])
	{
		n = ft_atoi(values[i]);
		if ((!n && char_not_zero(values[i])) || n < 0 || n > 255)
			return (free_tab(values), ft_dprintf(2, "Error: RGB codes invalid\n"), 2);
		if (!ft_strncmp(ID, "C ", 10))
			(cub->textures->ceiling)[i] = n;
		if (!ft_strncmp(ID, "F ", 10))
			(cub->textures->floor)[i] = n;
		i++;
	}
	return (0);
}
