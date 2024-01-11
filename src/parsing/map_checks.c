/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichatte <pichatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:30:13 by pichatte          #+#    #+#             */
/*   Updated: 2024/01/10 18:40:43 by pichatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

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
			return (ft_dprintf(2, "Error: Map is not last\n"), 0);
		if (cub3D->file->cub_file[len - 1] == '\n')
			last_line = 0;
		len--;
	}
	return (1);
}

int	map_has_nl(t_cub *cub3D)
{
	char	*first_line_map;
	int		i;
	
	first_line_map = first_line_of_map(cub3D);
	if (!first_line_map)
		return (ft_dprintf(2, "Error: Closed map not found\n"), 1);
	i = 0;
	while (first_line_map[i] && first_line_map + i != last_char_of_map(cub3D))
	{
		if (first_line_map[i] == '\n' && first_line_map[i + 1] == '\n')
			return (ft_dprintf(2, "Error: Map has newline\n"), 1);
		i++;
	}
	return (0);
}

int	map_enclosed(t_cub *cub3D)
{
	(void) cub3D;
	return (1);
}