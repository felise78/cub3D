/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:43 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/19 12:08:03 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../libft/src/strings/ft_putstr_fd.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../inc/window.h"

int	ft_check_file_ext(char *s);
void	ft_create_window(t_win *win);

int main (int ac, char **av)
{
	int fd;
	t_win win;
	
	if (ac != 2)
	{
		ft_putstr_fd("Error\nYou must have 1 argument\n", 2);
		return (1);
	}
	if (ft_check_file_ext(av[1]) == 0)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCould not open the file\n", 2);
		return (1);
	}
	// parser la carte
	ft_create_window(&win);
}