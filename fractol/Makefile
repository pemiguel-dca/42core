#-*- Makefile -*-

#target : dependencies
#       action

CFLAGS = -Wall -Werror -Wextra -std=gnu99 -I.

NAME = fractol

UTILS = utils.c utils2.c basics.c draw.c params.c main.c
OBJ_UTILS = $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_UTILS)
		cc $(CFLAGS) $(OBJ_UTILS) -lm -lbsd -lmlx -lXext -lX11 -o $(NAME)
		@printf [SUCCESS]"Program was created successfully!\n"

clean:
		rm -rf $(OBJ_UTILS)

fclean: clean
		rm -f $(NAME)

re : fclean all