/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

const char FLAGS[5] = {'#', '0', '-', ' ', '+'};
const char *SPECIFIERS[6] = {"di", "ouxX", "c", "sS", "p", "%"};
const char *LENGTH[] = {"hh", "h", "l", "ll", "q"};

typedef struct arg {
    char *flags[6];
    int width;
    int precision;
    char *length[3];
    char specifier;
} arg_t;

static void search_flags(char *format, int *i, arg_t *arg)
{
    short arg_idx = 0;

    while (arg_idx <= 5) {
        if (format[*i] == FLAGS[arg_idx]) {
            arg->flags[arg_idx] = FLAGS[arg_idx];
            break;
        }
        arg_idx++;
    }
    if (arg_idx < 6) {
        (*i)++;
        search_flags(format, i, arg);
    }
}

static void get_nbr_fromformat(char *format, int *i, int *nbr)
{
    *nbr = my_getnbr(format[*i]);
    if (format[*i] == '.')
        (*i)++;
    while (is_digit(format[*i]))
        (*i)++;
}

static int search_pattern(char *format, int *i, const char *pat, char *dest)
{
    int pattern_found = -1;
    int idx_pat = 0;

    for (int j = 0; pat[idx_pat][j] != '\0'; j++) {
        if (pat[idx_pat][j] != format[i + j]) {
            idx_pat++;
            j = -1;
        }
        if (j != -1 && pat[idx_pat][j + 1] == '\0' && pattern_found == -1)
            pattern_found = idx_pat;
        else if (j != -1 && pat[idx_pat][j + 1] == '\0') {
            *dest = my_strlen(pat[pattern_found]);
            return 1;
        }
    }
    if (pattern_found != -1) {
        my_strcpy(dest, pat[pattern_found]);
        return 0;
    }
    return -1;
}

static arg_t analyse_arg(char *format, int *i)
{
    arg_t arg = {".....", -1, -1, "  ", 0, NULL};
    int i_save;

    search_flags(format, i, &arg);
    if (is_digit(format[*i]) == 1)
        get_nbr_fromformat(format, i, &(arg.width));
    else if (format[*i] == '.')
        get_nbr_fromformat(format, i, &(arg.precision));
    if (search_pattern(format, i, LENGTH, &(arg.length)) > 0) {
        // supprimer pattern
    }
    if (!search_pattern(format, i, SPECIFIERS, &(arg.flags))) {
        return arg;
    return ;
}

static int display_arg(arg_t *arg)
{

}

int my_printf(char *format, ...)
{
    int i = -1;
    int len = 0;
    int len_arg = 0;
    valist ap;

    va_start(ap, format);
    while (format[++i] != '\0') {
        if (format[i] == '%')
            len_arg = analyse_arg(format, &(++i));
            len +=
            va_arg(ap, int);
        else {
            my_putchar(format[i]);
            len++;
        }
    }
    va_end(ap);
    return len;
}
