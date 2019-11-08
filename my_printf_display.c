/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf display
*/

#include "my.h"
#include <stdarg.h>

typedef struct arg {
    char flags[6];
    int width;
    int precision;
    char length[3];
    char spec[2];
} arg_t;

void clean_flags(arg_t *arg);
int what_type(char spe);

void debug_display_arg(arg_t *arg) // DEBUG
{
    printf("flags : %s\n", arg->flags);
    printf("width : %d\n", arg->width);
    printf("precision : %d\n", arg->precision);
    printf("len : %s\n", arg->length);
    printf("spec : %s\n", arg->spec);
}

void display_number(arg_t *arg)
{
    if (arg->flags[0] == '#') {
        if (arg->spec[0] == 'o')
            my_putstr("0");
    }
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
    debug_display_arg(arg); // DEBUG
    if (what_type(arg->spec) <= 3) {

    } else if (arg->spec[0] == '%') {
        my_putchar('%');
    } else {

    }

    //va_arg(ap, int);
    return 0;
}
