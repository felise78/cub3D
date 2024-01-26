/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:30:13 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/24 19:00:39 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

int	set_map_dimensions(t_cub *cub)
{
	int	i;
	
	if (!cub || !(cub->map) || !(cub->map->map_grid))
		return (-1);
	cub->map->map_width = 0;
	i = 0;
	while (cub->map->map_grid[i])
	{
		if (ft_strlen(cub->map->map_grid[i]) > (size_t)cub->map->map_width)
			cub->map->map_width = ft_strlen(cub->map->map_grid[i]);
		i++;
	}
	cub->map->map_height = i;
	ft_dprintf(1, "Map width: %d, map height: %d\n", cub->map->map_width, cub->map->map_height);
	return (0);
}

int check_map_printable(char *filename)
{
	int fd;
	char buffer[100];
	int	bytes_read;
	int	i;
	
	fd = open(filename, __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), ft_dprintf(2, "%s is a directory\n", filename), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	bytes_read = 1;
	i = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer + i, 1);
		if (bytes_read == -1)
			return (close_fd_perror(fd, "Read error\n", -2));
		if (buffer[i] != '\n' && !ft_isprint(buffer[i]))
			return (close_fd_perror(fd, "Map is not printable\n", 2));
		i++;
		if (i == 99)
			i = 0;
	}
	return (close_fd_perror(fd, "", 0));
}

int	map_is_last(t_cub *cub3D)
{
	int		len;
	char	*charset_last;
	int		last_line;

	last_line = 1;
	charset_last = "1 \n";
	len = cub3D->file->file_len;
	while (cub3D->file->cub_file[len - 1] == '\n')
		len--;
	while (len - 1 && last_line)
	{
		if (!in_charset(cub3D->file->cub_file[len - 1], charset_last))
			return (ft_dprintf(2, "Error: Map is not last or invalid\n"), 0);
		if (cub3D->file->cub_file[len - 1] == '\n')
			last_line = 0;
		len--;
	}
	return (1);
}

int	nl(t_cub *cub);

int	map_has_nl(t_cub *cub3D)
{
	int			first_line;
	const char	*charset = "10 ";
	
	if (nl(cub3D))
		return (1);
	first_line = first_line_of_map(cub3D);
	if (!first_line)
		return (ft_dprintf(2, "Error: Closed map not found\n"), 2);
	while (cub3D->file->file_grid[first_line])
	{
		if (!in_charset(cub3D->file->file_grid[first_line][0], charset))
			return (ft_dprintf(2, "Error: Invalid map\n"), 3);
		first_line++;
	}
	return (0);
}

int	wrong_neighbour(char **grid, int y, int x, char *charset)
{
	if (in_charset (grid[y][x + 1], charset)
		&& (x > 0 && in_charset (grid[y][x - 1], charset))
		&& (grid[y + 1] && in_charset (grid[y + 1][x], charset))
		&& (y > 0 && in_charset (grid[y - 1][x], charset)))
		return (0);
	return (1);
}

int	nl(t_cub *cub)
{
	char		*file;
	int 		i;
	int			j;
	int			len;
	const char	*charset = "1 ";
	
	file = cub->file->cub_file;
	i = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			j = i + 1;
			while (in_charset(file[j], charset))
				j++;
			if (file[j] == '\n' && j != i + 1)
				break;	
		}
		i++;
	}
	if (!file[i])
		return (ft_dprintf(2, "Closed map not found\n"), 1);
	len = cub->file->file_len - 1;
	while (len && file[len] == '\n')
		len--;
	while (len && len != i + 1)
	{
		if (file[len] == '\n' && len - 1 && file[len - 1] == '\n')
			return (ft_dprintf(2, "Newline in map\n"), 2);
		len--;
	}
	return (0);
}