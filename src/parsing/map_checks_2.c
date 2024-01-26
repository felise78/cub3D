/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:54 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/24 18:51:41 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

void	replace_floor(char ***grid, int y, int x)
{
	if ((*grid)[y][x] == '1' || (*grid)[y][x] == 'X' || (*grid)[y][x] == 'I')
		return ;
	else if ((*grid)[y][x] == ' ')
		(*grid)[y][x] = 'I';
	else
		(*grid)[y][x] = 'X';
	if ((*grid)[y][x + 1])
		replace_floor(grid, y, x + 1);
	if (x > 0)
		replace_floor(grid, y, x - 1);	
	if ((*grid)[y + 1])
		replace_floor(grid, y + 1, x);
	if (y > 0)
		replace_floor(grid, y - 1, x);
}

int	check_for_char(char **grid, char c)
{
	int	y;
	int	x;

	if (!grid || !(*grid))
		return (-1);
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*DELETE LATER*/
void	print_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		ft_dprintf(1, "%d. %s\n", y, tab[y]);
		y++;
	}
}
/**/

int	check_for_boundaries(char **grid)
{
	int	y;
	int	x;

	if (!grid)
		return (-1);
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'X' && wrong_neighbour(grid, y, x, "1X"))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	floodfill(t_cub *cub)
{
	char	**grid_copy;

	grid_copy = copy_grid(cub->map->map_grid, cub->map->map_width);
	if (!grid_copy)
		return (1);
	replace_floor(&grid_copy, cub->player->mapY, cub->player->mapX);
	if (check_for_char(grid_copy, 'I'))
		return (free_tab(grid_copy), ft_dprintf(2, "Error: Map not closed\n"), 1);
	if (check_for_boundaries(grid_copy))
		return (free_tab(grid_copy), ft_dprintf(2, "Error: Map not closed\n"), 1);
	free_tab(grid_copy);
	return (0);
}