#-*- Makefile -*-

#target : dependencies
#       action

CFLAGS = -Wall -Wextra -Werror
MAND = sort_normal.c create_arr.c write_term.c helpers.c find_max_min.c actions.c actions_2.c lets_sort.c exception.c sort_complex.c push_swap.c
OBJ_MAND = $(MAND:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_MAND)
		cc $(CFLAGS) -g $(OBJ_MAND) -o $(NAME)

clean:
		rm -rf $(OBJ_MAND) $(OBJ_BONUS)

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY: $(NAME)
