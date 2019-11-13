##
## EPITECH PROJECT, 2019
## PSU_my_printf_2019
## File description:
## void
##

all:
	make -C lib/my

fclean:
	make fclean -C lib/my

re:	fclean all

tests_run:
	make tests_run -C lib/my
