#-*- Makefile -*-

#target : dependencies
#       action

CFLAGS = -Wall -Wextra -Werror
MAND = sort_normal.c create_arr.c write_term.c helpers.c sort_normal.c write_term.c find_max_min.c actions.c actions_2.c lets_sort.c exception.c push_swap.c

OBJ_MAND = $(MAND:.c=.o)

NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJ_MAND)
		ar rc $(NAME) $(OBJ_MAND)

clean:
		rm -rf $(OBJ_MAND) $(OBJ_BONUS)

fclean: clean
		rm -f $(NAME)

re : fclean all
