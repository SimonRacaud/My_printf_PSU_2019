##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## void
##

SRC	=	main.c		\
		my_printf.c	\
		my_put_double

OBJ	=	$(SRC:.c=.o)

CFLAGS +=	-I./include -g -Wall -Wextra

NAME	=	printf.out

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lmy -L./lib/my

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o $(NAME) my_printf.c tests/test_my_printf.c -lmy -L./lib/my -I./include -lcriterion && ./$(NAME)
