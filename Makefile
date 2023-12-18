# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 16:54:30 by hemottu           #+#    #+#              #
#    Updated: 2023/12/18 20:21:06 by hemottu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = chips3D
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRC = 	src/main.c \
		src/parsing.c \
		src/window.c \
		src/signals.c

OBJ = $(SRC:.c=.o)

MLX = minilibx-linux/libmlx.a

all: $(NAME) 

$(MLX): 
	make -C minilibx-linux	

$(NAME): $(OBJ) $(MLX)
	$(CC) $(SRC) $(CFLAGS) -lX11 -lm -lXext -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -o $(NAME)

clean:
	$(RM) $(OBJ) 
	make clean -C minilibx-linux

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all re clean fclean bonus
