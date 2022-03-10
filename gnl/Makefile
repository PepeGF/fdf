SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = libgnl.a

CC = gcc

CFLAGSS = -g -O0 -Wall -Werror -Wextra

RM = rm -f

all:	$(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo $(NAME)" successfully compiled"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all bonus clean fclean re
