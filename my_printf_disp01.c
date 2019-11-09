/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** File 1 : display arg
*/

#include "my_printf.h"
#include "my.h"
#include <stdio.h>

int disp_int(arg_t *arg, va_list *ap)
{
    int data = va_arg(*ap, int);
    int len_space = define_len_space(arg, (long long int)data, 10);
    int len_preci = define_len_preci(arg, (long long int)data, 10);

    if (arg->flags[3] == ' ' && data != 0)
        my_putchar(' ');
    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if (arg->flags[4] == '+' && data >= 0)
        my_putchar('+');
    disp_zeros(arg->flags[1], len_space, len_preci);
    my_put_nbr(data);
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
}

int disp_uint_xX(arg_t *arg, va_list *ap)
{
    unsigned int data = va_arg(*ap, unsigned int);
    int len_space = define_len_space(arg, (long long int)data, 16);
    int len_preci = define_len_preci(arg, (long long int)data, 16);

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'x' && data != 0)
        my_putstr("0x");
    if (arg->flags[0] == '#' && arg->spec[0] == 'X' && data != 0)
        my_putstr("0X");
    disp_zeros(arg->flags[1], len_space, len_preci);
    if (arg->spec[0] == 'x')
        my_putnbr_base(data, "0123456789abcdef");
    else if (arg->spec[0] == 'X')
        my_putnbr_base(data, "0123456789ABCDEF");
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
}

int disp_uint_o(arg_t *arg, va_list *ap)
{
    unsigned int data = va_arg(*ap, unsigned int);
    int len_space = define_len_space(arg, (long long int)data, 8);
    int len_preci = define_len_preci(arg, (long long int)data, 8);

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'o' && data != 0)
        my_putstr("0");
    disp_zeros(arg->flags[1], len_space, len_preci);
    my_putnbr_base(data, "01234567");
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
}

int disp_uint_b(arg_t *arg, va_list *ap)
{
    unsigned int data = va_arg(*ap, unsigned int);
    int len_space = define_len_space(arg, (long long int)data, 2);
    int len_preci = define_len_preci(arg, (long long int)data, 2);

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'o' && data != 0)
        my_putstr("0");
    disp_zeros(arg->flags[1], len_space, len_preci);
    my_putnbr_base(data, "01");
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
}

int disp_uint_u(arg_t *arg, va_list *ap)
{
    unsigned int data = va_arg(*ap, unsigned int);
    int len_space = define_len_space(arg, (long long int)data, 10);
    int len_preci = define_len_preci(arg, (long long int)data, 10);

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'o' && data != 0)
        my_putstr("0");
    disp_zeros(arg->flags[1], len_space, len_preci);
    my_put_nbr(data);
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
}
