/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf display
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int define_len_space(arg_t *arg, long long int data, int base)
{
    int len_flags = 0;
    int space = -1;

    if (arg->flags[0] == '#' && arg->spec[0] != 'o')
        len_flags += 2;
    if (arg->flags[3] == ' ' || arg->flags[4] == '+')
        len_flags++;
    space = arg->width - len_flags;
    space -= len_nbr(data, base);
    if (space < 0)
        space = 0;
    return space;
}

int define_len_preci(arg_t *arg, long long int data, int base)
{
    int zero = -1;

    zero = arg->precision;
    zero -= len_nbr(data, base);
    if (zero < 0)
        zero = 0;
    return zero;
}

void disp_zeros(char flag_zero, int len_space, int len_preci)
{
    if (flag_zero == '0') {
        for (int i = 0; i < len_space; i++)
            my_putchar('0');
    }
    if (len_preci > 0) {
        for (int i = 0; i < len_preci; i++)
            my_putchar('0');
    }
}

void disp_width(int len_space, int len_preci)
{
    for (int i = 0; i < len_space - len_preci; i++)
        my_putchar(' ');
}
