SRCS = wololo.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

#ifeq ($(shell uname), Linux)
#	LIBMLX_PATH = ./mlx_linux/
#else
#	LIBMLX_PATH = ./mlx/
#endif

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBS_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $? -Lmlx_linux -lmlx $(LIBS_FLAGS) 
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
