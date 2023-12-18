/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:46 by hemottu           #+#    #+#             */
/*   Updated: 2023/12/18 16:19:23 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../libft/src/strings/ft_strlen.c"

int	ft_check_file_ext(char *s)
{
	int		len;
	char	*s2;
	int		i;

	len = ft_strlen(s) - 1;
	s2 = ".cub";
	i = 3;
	while (s[len] && s2[i])
	{
		if (s[len] != s2[i])
		{
			ft_putstr_fd("Error\nYou must have a .cub file\n", 2);
			return (0);
		}
		len--;
		i--;
	}
	if (!s[len])
	{
		ft_putstr_fd("Error\nFile is a hidden file\n", 2);
		return (0);
	}
	return (1);
}