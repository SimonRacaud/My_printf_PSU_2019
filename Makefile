##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## void
##

SRC	=	main_test.c		\
		my_printf.c		\
		my_put_double.c		\
		my_printf_display.c	\
		my_printf_disp01.c	\
		my_printf_disp02.c	\
		my_printf_disp_misc.c	\
		my_printf_misc.c	\
		search.c		\

SRC_TEST =	my_printf.c		\
		my_put_double.c		\
		my_printf_display.c	\
		my_printf_disp01.c	\
		my_printf_disp02.c	\
		my_printf_disp_misc.c	\
		my_printf_misc.c	\
		search.c		\

TESTS	 =	tests/test_my_printf.c		\
		tests/test_my_printf_int.c	\
		tests/test_my_printf_uint.c	\

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
	gcc -o $(NAME) $(SRC_TEST) $(TESTS) -lmy -L./lib/my -I./include -lcriterion && ./$(NAME)

tests_int:
	gcc -o $(NAME) $(SRC_TEST) tests/test_my_printf_int.c -lmy -L./lib/my -I./include -lcriterion && ./$(NAME)

tests_uint:
	gcc -o $(NAME) $(SRC_TEST) tests/test_my_printf_uint.c -lmy -L./lib/my -I./include -lcriterion && ./$(NAME)
