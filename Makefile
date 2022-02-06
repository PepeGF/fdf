SRCS = main.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

RM = rm -f

LIBGNL_PATH = ./gnl/
LIB_GNL = -I$(LIBGNL_PATH) -L$(LIBGNL_PATH) -lgnl

LIBFT_PATH = ./libft/
LIB_FT = -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft

ifeq ($(shell uname), Linux)
	#LIBMLX_PATH = ./mlx_linux/
	OBJ_COMPIL = -I/usr/include -Imlx_linux -O3 -c $< -o $@
	LIB_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz
	LIB_COMPIL = -Lmlx_linux -lmlx $(LIB_FLAGS) $(LIB_GNL) $(LIB_FT)
	SO = Linux
else
	OBJ_COMPIL = -Imlx -c $< -o $@
	LIB_COMPIL = -lmlx -framework OpenGL -framework AppKit $(LIB_FLAGS) $(LIB_GNL) $(LIB_FT) -o $(NAME)
endif

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) $(OBJ_COMPIL)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBGNL_PATH) --silent
	@$(MAKE) -C $(LIBFT_PATH) --silent
	@$(CC) -o $(NAME) $? $(LIB_COMPIL) 
	@echo $(NAME)": ready to be executed"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBGNL_PATH) clean --silent
	@$(MAKE) -C $(LIBFT_PATH) clean --silent

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBGNL_PATH) fclean --silent
	@$(MAKE) -C $(LIBFT_PATH) fclean --silent

re: fclean $(NAME)

.PHONY: all clean fclean re
