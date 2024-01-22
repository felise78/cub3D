/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:18:39 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/19 17:03:15 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

typedef struct s_cub t_cub;

/*INIT*/
int init_map_test(t_cub *cub3D); // juste test
//void	set_first_position(t_cub *cub3D);
int		load_textures(t_cub *cub3D);
int	init_cub3D(t_cub *cub);
int 	init_colors(t_cub *cub);

/*ERRORS GENERAL*/
int		check_errors(t_cub *cub3D);
int		ft_check_file_ext(char *s);
int		check_file_pollution(t_cub *cub3D);

/*PARSING UTILS*/
int		set_map_dimensions(t_cub *cub);
int		close_fd_perror(int fd, char *error_msg, int return_code);
int		count_chars_in_file(char *filename);
int		copy_file(t_cub *cub3D);
int		in_charset(int c, char *charset);
int		check_line_valid(char *line);
char	*first_line_of_map(t_cub *cub3D);
char	*last_char_of_map(t_cub *cub3D);
int		char_not_zero(char *n);
int		tab_size(char **tab);

/*MAP CHECKS*/
int		check_map_printable(char *filename);
int		map_is_last(t_cub *cub3D);
int		map_has_nl(t_cub *cub3D);
int		map_enclosed(t_cub *cub3D);

/*TEXTURES*/
int		check_textures_valid(t_cub *cub3D, char *ID);
int		check_RGB_valid(t_cub *cub, char *ID, char **values);

/*FREES AND EXIT*/
void	free_all(t_cub *cub3D, int level, int directions);
void	free_tab(char **tab);

/*WINDOW*/
void	create_window(t_cub *cub3D);
int	close_window(t_cub *cub3D);

/*DRAW*/
int loop(t_cub *cub3D);
void draw_img(t_cub * cub);
void	draw_background(t_cub *cub3D);
void draw_minimap(t_cub *cub3D);
void draw_tile(t_cub *cub, int canvas_x, int canvas_y, int color);
void set_pixel(t_cub *cub, int index, const char *value);
int pix_index(t_cub *cub, int x, int y);
void draw_player(t_cub *cub, int color);

/*SIGNALS*/
int	handle_keypress(int keysym, t_cub *cub);
int handle_keyrelease(int keysym, t_cub *cub3D);

/*MOVES*/
void	move_player(t_cub *cub, int keysym);
int check_if_wall(t_cub *cub, float x, float y);

/*RAYCASTING*/
int ray_casting(t_cub *cub); // test
void calculate_rays(t_cub *cub); // test

#endif