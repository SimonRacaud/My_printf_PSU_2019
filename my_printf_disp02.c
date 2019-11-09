/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** File 2 : display arg
*/

#include "my_printf.h"
#include "my.h"
#include <stdio.h>

int disp_char(arg_t *arg, va_list *ap)
{
    char data = va_arg(*ap, int);
    int space_len = arg->width - 1;

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(space_len, 0);
    my_putchar(data);
    if (arg->flags[2] == '-')
        disp_width(space_len, 0);
    return (1 + space_len);
}

int disp_str(arg_t *arg, va_list *ap)
{
    char *data = va_arg(*ap, char *);
    int space_len = arg->width - my_strlen_spec(data, arg->spec[0]);

    if (arg->precision == -1)
        arg->precision = my_strlen_spec(data, arg->spec[0]);
    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(space_len, 0);
    for (int i = 0; i < arg->precision && data[i] != '\0'; i++) {
        if (arg->spec[0] == 's' || (data[i] >= 32 && data[i] <= 126)) {
            my_putchar(data[i]);
        } else {
            my_putchar('\\'); // IN PROGRESS
        }
    }
    if (arg->flags[2] == '-')
        disp_width(space_len, 0);
    return (my_strlen_spec(data, arg->spec[0]) + space_len);
}

int disp_uint_p(arg_t *arg, va_list *ap)
{
    void *data = va_arg(*ap, void *);
    int len_space = define_len_space(arg, (long long int)data, 16);
    int len_preci = define_len_preci(arg, (long long int)data, 16);

    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if ((unsigned long int)data != 0)
        my_putstr("0x");
    disp_zeros(arg->flags[1], len_space, len_preci);
    if ((unsigned long int)data != 0)
        my_putnbr_base((unsigned long int)data, "0123456789abcdef");
    else
        my_putstr("(nil)");
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
    return 0;
}

int disp_l_llq(arg_t *arg, va_list *ap)
{
    long long int data;
    int len_space = define_len_space(arg, (long long int)data, 10);
    int len_preci = define_len_preci(arg, (long long int)data, 10);

    if (arg->length[0] == 'l' && arg->length[1] == '.')
        data = va_arg(*ap, long int);
    else
        data = va_arg(*ap, long long int);
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

int disp_ul_ullq(arg_t *arg, va_list *ap)
{
    unsigned long long int data;
    int len_space = define_len_space(arg, (long long int)data, 10);
    int len_preci = define_len_preci(arg, (long long int)data, 10);

    if (arg->length[0] == 'l' && arg->length[1] == '.')
        data = va_arg(*ap, unsigned long int);
    else
        data = va_arg(*ap, unsigned long long int);
    if (arg->flags[1] != '0' && arg->flags[2] != '-')
        disp_width(len_space, len_preci);
    if (arg->flags[0] == '#' && arg->spec[0] == 'o' && data != 0)
        my_putstr("0");
    disp_zeros(arg->flags[1], len_space, len_preci);
    my_put_nbr_ul(data);
    if (arg->flags[2] == '-')
        disp_width(len_space, len_preci);
}
