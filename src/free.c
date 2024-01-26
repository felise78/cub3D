/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:29:34 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/24 15:37:38 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

void	free_all(t_cub *cub3D, int level, int directions)
{
	int	i;

	if (level > 2)
		free (cub3D->win);
	if (level > 1)
	{
		free(cub3D->camera);
		free(cub3D->player);	
	}
	if (level > 0)
	{
		i = 0;
		while (i < directions && i < 4)
		{	
			free((cub3D->textures->directions)[i]);
			(cub3D->textures->directions)[i] = NULL;
			i++;
		}
	}
	free (cub3D->file->cub_file);
	cub3D->file->cub_file = NULL;
	free_tab(cub3D->file->file_grid);
	cub3D->file->file_grid = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
	tab = NULL;
}