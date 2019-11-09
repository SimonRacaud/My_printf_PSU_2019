/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf display
*/

#include "my.h"
#include <stdarg.h>
#include "my_printf.h"

const void (*TYPES[10])(arg_t *arg, va_list *ap) = {&disp_int, &disp_uint_xX,
&disp_uint_o, &disp_uint_b, &disp_uint_u, &disp_char, &disp_str, &disp_uint_p,
&disp_l_llq, &disp_ul_ullq};

//const char *PATT[10] = {"d i ", "x X ", "o", "b", "u", "c hh", "s S", "p", "l llq", "ul ullq"};
////////////////////////////////////////
#include <stdio.h>
void debug_display_arg(arg_t *arg) // DEBUG
{
    printf("flags : %s\n", arg->flags);
    printf("width : %d\n", arg->width);
    printf("precision : %d\n", arg->precision);
    printf("len : %s\n", arg->length);
    printf("spec : %s\n", arg->spec);
}//////////////////////////////////////

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

int display_arg(arg_t *arg, va_list *ap, char *ptrformat)
{
    int i = 0;

    if (arg->spec[0] == '.') {
        while (*(ptrformat - i) != '%')
            i++;
        for (int j = 0; j <= i; j++)
            my_putchar(*(ptrformat - (i - j)));
        return i;
    }
    clean_flags(arg);
    if (arg->spec[0] == '%') {
        my_putchar('%');
    } else {
        if (what_type(arg->spec[0]) == 1) {
            if (arg->length[0] == 'l' || arg->length[0] == 'q') {
                TYPES[8](arg, ap);
                return 0;
            }
        }
        if (what_type(arg->spec[0]) == 2) {
            if (arg->length[0] == 'l' || arg->length[0] == 'q') {
                TYPES[9](arg, ap);
                return 0;
            }
        }
        if (arg->spec[0] == 'c' || arg->length[1] == 'h')
            TYPES[5](arg, ap);
        if (what_type(arg->spec[0]) == 1)
            TYPES[0](arg, ap);
        if (arg->spec[0] == 'x' || arg->spec[0] == 'X')
            TYPES[1](arg, ap);
        if (arg->spec[0] == 'o')
            TYPES[2](arg, ap);
        if (arg->spec[0] == 'b')
            TYPES[3](arg, ap);
        if (arg->spec[0] == 'u')
            TYPES[4](arg, ap);
        if (arg->spec[0] == 's' || arg->spec[0] == 'S')
            TYPES[6](arg, ap);
        if (arg->spec[0] == 'p')
            TYPES[7](arg, ap);
    }
    return 0;
}
