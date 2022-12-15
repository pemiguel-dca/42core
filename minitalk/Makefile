#-*- Makefile -*-

#target : dependencies
#       action
CFLAGS = -Wall -Wextra -Werror
MAND = utils.c client.c server.c

OBJ_MAND = $(MAND:.c=.o)

NAME = minitalk.a

all: $(NAME)

$(NAME): $(OBJ_MAND)
		ar rc $(NAME) $(OBJ_MAND)

clean:
		rm -rf $(OBJ_MAND)

fclean: clean
		rm -f $(NAME)

re : fclean all
