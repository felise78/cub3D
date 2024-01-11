# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 16:54:30 by hemottu           #+#    #+#              #
#    Updated: 2024/01/11 15:31:42 by hemottu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = chips3D
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/
#LIBFT_DIR	=	libft/

RESET		=	\033[0m
GREEN		=	\033[32m

SRC_FILES = 	main.c \
				parsing/parsing.c \
				parsing/file_handling.c \
				parsing/map_checks.c \
				parsing/utils.c \
				parsing/texture_checks.c \
				window.c \
				free.c \
				signals.c \
				ray_casting/set_first_position.c \
				draw/canvas.c \
				draw/draw_little_map.c \
				map_test.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

MLX = minilibx-linux/libmlx.a

LIBFT = libft/libft.a

DEPS = $(OBJ:.o=.d)

all: $(NAME)
	@printf "\n$(GREEN)"
	@printf "      _     _           ____  _____\n"
	@printf "     | |   (_)         |___ \|  __ \ \n"
	@printf "  ___| |__  _ _ __  ___  __) | |  | |\n"
	@printf " / __| '_ \| | '_ \/ __||__ <| |  | |\n"
	@printf "| (__| | | | | |_) \__ \___) | |__| |\n"
	@printf " \___|_| |_|_| .__/|___/____/|_____/ \n"
	@printf "             | |  \n"
	@printf "             |_| $(RESET)\n"
	@printf "\n"

$(NAME): $(OBJ) $(MLX) $(HEADERS) $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -lX11 -lm -lXext -Lminilibx-linux/ -lmlx -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -I $(INC_DIR) -Iminilibx-linux/ -I libft/include/ -o $@ -c $<

-include $(DEPS)

$(MLX): 
	make -C minilibx-linux	

$(LIBFT):
	make -C libft


clean:
	rm -rf $(OBJ) $(OBJ_DIR)
	make clean -C minilibx-linux
	make clean -C libft

fclean:	clean
	rm -rf $(NAME) $(MLX) $(LIBFT)

re: fclean all

.PHONY:	all re clean fclean bonus
