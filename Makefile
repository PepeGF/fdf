SRCS = main.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

#ifeq ($(shell uname), Linux)
#	LIBMLX_PATH = ./mlx_linux/
#else
#	LIBMLX_PATH = ./mlx/
#endif

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
