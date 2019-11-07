/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** display a floating number
*/

#include "my.h"
#define POW(x, y) my_compute_power_rec(x, y)

void my_put_double(double nb, int nb_decimal)
{
    int integer = nb;
    double decimal = (float)(nb - (float)integer) * POW(10, nb_decimal);
    int decimal_len = 0;

    if (decimal < 0)
        decimal = -decimal;
    my_put_nbr((int)nb);
    my_putchar('.');
    if (decimal < 1) {
        decimal_len = 0;
    } else {
        while (decimal / my_compute_power_rec(10, decimal_len) >= 1)
            decimal_len++;
    }
    for (int i = (nb_decimal - decimal_len); i > 0; i--)
        my_putchar('0');
    if (decimal != 0)
        my_put_nbr(decimal);
}
