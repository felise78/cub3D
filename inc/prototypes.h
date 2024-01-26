/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:18:39 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/25 16:14:01 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

typedef struct s_cub t_cub;
typedef struct s_file t_file;
typedef struct s_tex t_tex;

/*INIT*/
int init_map_test(t_cub *cub3D); // juste test
int		set_first_position(t_cub *cub3D);
int		load_textures(t_cub *cub3D);
int		init_cub3D(t_cub *cub);
int 	init_colors(t_cub *cub);
int		init_pointers(t_cub *cub, t_file *file, t_tex *textures, char *filename);

/*ERRORS GENERAL*/
int		check_errors(t_cub *cub3D);
int		ft_check_file_ext(char *s);
int		check_file_pollution(t_cub *cub3D);

/*PARSING UTILS*/
int		set_map_dimensions(t_cub *cub);
int		close_fd_perror(int fd, char *error_msg, int return_code);
int		count_chars_in_file(char *filename);
int		copy_file(t_cub *cub3D);
int		in_charset(int c, const char *charset);
int		check_line_valid(char *line);
int		first_line_of_map(t_cub *cub3D);
char	*last_char_of_map(t_cub *cub3D);
int		char_not_zero(char *n);
int		tab_size(char **tab);
char	**copy_grid(char **original, int len);

/*MAP CHECKS*/
int		check_map_printable(char *filename);
int		map_is_last(t_cub *cub3D);
int		map_has_nl(t_cub *cub3D);
int		map_enclosed(t_cub *cub3D);
int		floodfill(t_cub *cub);
int		wrong_neighbour(char **grid, int y, int x, char *charset);

/*TEXTURES*/
int		check_texture_number(char *identifier, t_cub *cub3D, int option);
void	set_texture_pointers(t_cub *cub3D, char **dir_pointer, char *ID, int max_free);
int		check_textures_valid(t_cub *cub3D, char *ID);
int		check_RGB_valid(t_cub *cub, char *ID, char **values);

/*FREES AND EXIT*/
void	free_all(t_cub *cub3D, int level, int directions);
void	free_tab(char **tab);

/*WINDOW*/
void	create_window(t_cub *cub3D);
int		close_window(t_cub *cub3D);

/*DRAW*/
int		loop(t_cub *cub3D);
void	draw_img(t_cub * cub);
void	draw_background(t_cub *cub3D);
void draw_minimap(t_cub *cub3D);
void draw_tile(t_cub *cub, int canvas_x, int canvas_y, int color);
void set_pixelRGB(t_cub *cub, int index, const int *value);
int pix_index(t_cub *cub, int x, int y);
void draw_player(t_cub *cub, int color);
void draw_pixcolumn(t_cub *cub, int x, int y0, int y1);
 void draw_walls(t_cub *cub);
//void draw_walls(t_cub *cub, int x);

/*SIGNALS*/
int		handle_keypress(int keysym, t_cub *cub);
int		handle_keyrelease(int keysym, t_cub *cub3D);

/*MOVES*/
void	move_player(t_cub *cub, int keysym);
int		check_if_wall(t_cub *cub, float x, float y);

/*RAYCASTING*/
void	calculate_rays(t_cub *cub);
void	draw_raycast(t_cub *cub);

/*ROTATE*/
void	rotate(t_cub *cub, int keysym);
#endif