##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## void
##

SRC	=	lib/my/my_printf_display.c	\
		lib/my/my_printf_disp01.c	\
		lib/my/my_printf_disp02.c	\
		lib/my/my_printf_disp03.c	\
		lib/my/my_printf_disp_misc.c	\
		lib/my/my_printf_misc.c		\
		lib/my/my_printf_search.c	\
		tests/test_my_printf.c            \
		tests/test_my_printf_int.c        \
		tests/test_my_printf_uint.c       \
		tests/test_flag.c                 \
		tests/test_global.c               \
		tests/test_size.c                 \
		tests/test_type.c

OBJ     =       $(SRC:.c=.o)

CFLAGS  +=       -Wall -Wextra -I./include --coverage -lcriterion

all:
	make -C lib/my

fclean:
	make fclean -C lib/my

clean:
	rm -f $(OBJ)

re:	fclean all

LIB:
	make -C lib/my

tests_run:	LIB $(OBJ)
	gcc $(SRC) -o my_printf -I./include -lmy -L./lib/my $(CFLAGS) && ./my_printf
	rm -f ./my_printf
