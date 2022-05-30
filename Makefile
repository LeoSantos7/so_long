CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = srcs/render.c srcs/hooks.c srcs/load_map.c srcs/parse_map.c
SRCS += srcs/so_long.c srcs/get_next_line.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a printf/printf.a
	$(CC) $(CFLAGS) $^ -lmlx -lXext -lX11 -o $(NAME)

libft/libft.a:
	make -C libft

printf/printf.a:
	make -C printf

objs/%.o: srcs/%.c includes/so_long.h
	mkdir -p objs
	$(CC) $(CFLAGS) -I includes -I printf -I libft -c $< -o $@

clean:
	make -C libft clean
	make -C printf clean
	rm -rf objs

fclean: clean
	make -C libft fclean
	make -C printf fclean
	rm -f so_long

re: fclean all

.PHONY: all clean fclean re
