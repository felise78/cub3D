/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:59:49 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/11 15:37:13 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

	#include "window.h"
	#include "textures.h"
	#include "img.h"
	#include "mlx.h"
	#include <fcntl.h>
	#include <sys/stat.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <stddef.h>
	#include <X11/X.h>
	#include <X11/keysym.h>
	#include <X11/Xlib.h>
	#include <math.h>
	
	// #define screenWidth 640
	// #define screenHeight 480
	// #define mapWidth 24
	// #define mapHeight 24
	#define PI 3.1415926535
	
	typedef struct s_win t_win;
	typedef struct s_file t_file;
	typedef struct s_pos t_pos;
	typedef struct s_fov t_fov;
	
	typedef struct s_cub
	{
		t_win	*win;
		t_img	*canvas; 
		t_tex	*textures;
		t_file	*file; // plus besoin ?
		char	**map;
		int		map_size;
		int 	**matrice;
		t_pos	*player;
		t_fov	*camera;
		
	}	t_cub;

	// garder float ou double ?
	typedef struct s_fov
	{
		// valeur trigonometrique
		float dir;
		float Lray;
		float Rray;
		
		// ou plutot faire avec des vecteurs ?
		float dirX; 
		float dirY;
		float LrayX;
		float LrayY;
		float RrayX;
		float RrayY;
		
		// je pourrais avoir seulement deux rayons ?
		
	} t_fov;
	
	typedef struct s_pos
	{
		// position precise du joueur
		float x;
		float y;
		// sur quel carre de la map il se trouve
		int mapX; 
		int mapY;
	}	t_pos;
	
	typedef struct s_file
	{
		char	*cub_file;
		int		file_len;
		char	*filename;
		char	**file_grid;
	}	t_file;

/*INIT*/
int init_map_test(t_cub *cub3D); // juste test
void	set_first_position(t_cub *cub3D);
int		load_textures(t_cub *cub3D);

/*ERRORS GENERAL*/
int		check_errors(t_cub *cub3D);
int		ft_check_file_ext(char *s);
int		check_file_pollution(t_cub *cub3D);

/*PARSING UTILS*/
int		close_fd_perror(int fd, char *error_msg, int return_code);
int		count_chars_in_file(char *filename);
int		copy_file(t_cub *cub3D);
int		in_charset(int c, char *charset);
int		check_line_valid(char *line);
char	*first_line_of_map(t_cub *cub3D);
char	*last_char_of_map(t_cub *cub3D);

/*MAP CHECKS*/
int		check_map_printable(char *filename);
int		map_is_last(t_cub *cub3D);
int		map_has_nl(t_cub *cub3D);
int		map_enclosed(t_cub *cub3D);

/*FREES AND EXIT*/
void	free_all(t_cub *cub3D, int level, int directions);
void	free_tab(char **tab);

/*WINDOW*/
void	create_window(t_cub *cub3D);
int	close_window(t_cub *cub3D);

/*DRAW*/
int loop(t_cub *cub3D);
void	draw_background(t_cub *cub3D);
void draw_little_map(t_cub *cub3D);

/*SIGNALS*/
int	handle_keypress(int keysym, t_cub *cub3D);
int handle_keyrelease(int keysym, t_cub *cub3D);

#endif