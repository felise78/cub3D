/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:29:49 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/24 17:14:23 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

int in_charset(int c, const char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int	check_line_valid(char *line)
{
	int			i;
	int			j;
	const char	textures_array[7][4] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	const char	charset[8] = "10NSEW ";
	
	if (!line)
		return (1);
	j = 0;
	while (textures_array[j] && textures_array[j][0])
	{
		if (ft_strnstr(line, textures_array[j], 5) == line)
			return (1);
		j++;
	}
	i = 0;
	while (line[i])
	{
		if (!in_charset(line[i], (char *)charset))
			return (0);
		i++;
	}
	return (1);
}

int	first_line_of_map(t_cub *cub3D)
{
	int		i;
	int		j;
	char	*charset_first;

	charset_first = "1 ";
	i = 0;
	while (cub3D->file->file_grid[i])
	{
		if (in_charset(cub3D->file->file_grid[i][0], charset_first))
		{
			j = 0;
			while (in_charset(cub3D->file->file_grid[i][j], charset_first))
				j++;
			if (!(cub3D->file->file_grid[i][j]))
				return (i);
		}
		i++;
	}
	return (0);
}

char	*last_char_of_map(t_cub *cub3D)
{
	int len;

	len = cub3D->file->file_len;
	while (len - 1 && cub3D->file->cub_file[len - 1] == '\n')
		len--;
	return (cub3D->file->cub_file + len - 1); 
}

int	char_not_zero(char *n)
{
	int	i;

	if (!n)
		return (1);
	i = 0;
	while (n && n[i] && !(ft_isdigit(n[i])))
		i++;
	if (!n[i])
		return (1);
	while (n[i])
	{
		if (n[i] != '0')
			return (1);
		i++;
	}
	return (0);
}
