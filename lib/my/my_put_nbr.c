/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** void
*/

void my_putchar(char c);
static long int poww3(int x, int n);

int my_put_nbr_ul(unsigned long long int nb)
{
    int i = 0;
    char c;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb / poww3(10, i) >= 10) {
        i++;
    }
    while (i >= 0) {
        c = ((nb / poww3(10, i)) % 10) + '0';
        my_putchar(c);
        i--;
    }
    return (0);
}

int my_put_nbr(long long int nb)
{
    int i = 0;
    char c;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb / poww3(10, i) >= 10) {
        i++;
    }
    while (i >= 0) {
        c = ((nb / poww3(10, i)) % 10) + '0';
        my_putchar(c);
        i--;
    }
    return (0);
}
static long int poww3(int x, int n)
{
    if (n == 0) {
        return (1);
    } else {
        return (x * poww3(x, n-1));
    }
}
