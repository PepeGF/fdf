SRCS = main.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

RM = rm -f

ifeq ($(shell uname), Linux)
	#LIBMLX_PATH = ./mlx_linux/
	OBJ_COMPIL = -I/usr/include -Imlx_linux -O3 -c $< -o $@
	LIB_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz
	LIB_COMPIL = -Lmlx_linux -lmlx $(LIB_FLAGS)
	SO = Linux
else
	OBJ_COMPIL = -Imlx -c $< -o $@
	LIB_COMPIL = -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	SO = Mac
endif

all: $(NAME)
#	@echo $(SO)

%.o:%.c
	@$(CC) $(CFLAGS) $(OBJ_COMPIL)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $? $(LIB_COMPIL) 
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
