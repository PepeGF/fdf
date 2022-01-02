
#SRCS = main.c 

#OBJS = $(SRCS:.c=.o)

#NAME = fdf 

#LIBMLX_PATH = mlx/

#CC = gcc

#CFLAGS = -g -Wall -Werror -Wextra

#RM = rm -f

#all: $(NAME)

#%.o:%.c
#	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(LIBMLX_PATH)

#$(NAME): $(OBJS)
#	@$(MAKE) -C $(LIBFT_PATH) --silent
#	@$(CC) -o $(NAME) $? -I. -L./libft -lft
#	@echo "push_swap: ready to be executed"

#clean:
#	@$(RM) $(OBJS)
#	@$(MAKE) -C $(LIBFT_PATH) clean --silent

#fclean: clean
#	@$(RM) $(NAME)
#	@$(MAKE) -C $(LIBFT_PATH) fclean --silent

#re: fclean $(NAME)
#	@$(MAKE) -C $(LIBFT_PATH) clean --silent

#.PHONY: all clean fclean re

operative = $(shell uname)

ifeq ($(operative), Linux)
	so = Linux
else
	so = Mac
endif

all:
	@echo Sistema operativo: $(operative)
	@echo Resultado del if:  $(so)
