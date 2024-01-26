/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:53:31 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/22 15:13:50 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

int	tab_size(char **tab)
{
	int	i;

	if (!tab)
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**copy_grid(char **original, int len)
{
	char	**copy;
	int		size;
	int		i;

	size = tab_size(original);
	copy = ft_calloc(sizeof(char *), size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_calloc(sizeof(char), len + 1);
		if (!copy[i])
		{
			free_tab(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], original[i], len + 1);
		i++;
	}
	return (copy);
}
