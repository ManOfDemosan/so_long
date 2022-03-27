NAME 		=	so_long
SRCS		=	main.c\
				get_nextline/*.c\
				map/*.c\
				init_game/*.c

OBJS		=	$(SRCS:.c=.o)

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX			=	libmlx.dylib

.PHONY: all clean fclean re

all: $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX) -c $< -o  $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -I $(MLX) $@ $^ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all