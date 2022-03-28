# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:37:01 by hakim             #+#    #+#              #
#    Updated: 2022/03/28 15:15:33 by jaehwkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework Appkit
NAME = so_long
SRCS =	srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/init_game_feachers.c\
		srcs/init_game.c\
		srcs/init_keypress.c\
		srcs/main.c\
		srcs/map_check.c\
		srcs/map_draw.c\
		srcs/map_reader.c
OBJS = $(SRCS:%.c=%.o)
HDR = ./includes
INCLUDES = -I$(HDR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean re bonus
