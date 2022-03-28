CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework Appkit
NAME = so_long
SRCS =	get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		init_game/init_game_feachers.c\
		init_game/init_game.c\
		init_game/init_keypress.c\
		main.c\
		map/map_check.c\
		map/map_draw.c\
		map/map_reader.c
OBJS = $(SRCS:%.c=%.o)
HDR = ./includes
# INCLUDES = -I$(HDR)

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
