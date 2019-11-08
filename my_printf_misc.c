/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf misc
*/

#include "my.h"

int is_digit(char c, int len_nbr);

int what_type(char spe)
{
    if (spe == 'd' || spe == 'i')
        return 1;
    if (spe == 'o' || spe == 'u' || spe == 'x' || spe == 'X' || spe == 'b')
        return 2;
    if (spe == 'p')
        return 3;
    if (spe == 'c')
        return 4;
    if (spe == 's' || spe == 'S')
        return 5;
    if (spe == '%')
        return 6;
    return 42;
}

void get_nbr_fromformat(char *format, int *i, int *nbr)
{
    *nbr = my_getnbr(&format[*i]);
    if (format[*i] == '.')
        (*i)++;
    while (is_digit(format[*i], 1))
        (*i)++;
}
