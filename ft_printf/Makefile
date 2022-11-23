#-*- Makefile -*-

#target : dependencies
#	action
CFLAGS = -Wall -Wextra -Werror
MAND = ft_printf.c ft_putnbr_u.c ft_printhex.c ft_printpointer.c ft_putnbr_dec.c ft_puts.c

OBJ_MAND = $(MAND:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ_MAND)
	ar rc $(NAME) $(OBJ_MAND)

clean:
	rm -rf $(OBJ_MAND) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re : fclean all
