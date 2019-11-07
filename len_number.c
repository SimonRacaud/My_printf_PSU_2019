/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** get length of a number (nb of digits)
*/

int is_digit(char c, int len_nbr)
{
    if ((c > '0' && c <= '9') || (c == '0' && len_nbr > 0))
        return (1);
    return (0);
}

static void incr_len(unsigned int *len, char c, char after_dot)
{
    if (is_digit(c, len[0])) {
        len[0]++;
    } else if (c != '.' && c != '0' && c != '-') {
        my_putstr_error("Error\n");
        exit(84);
    }
    if (is_digit(c, len[1]) && after_dot == 0)
        len[1]++;
    else if (is_digit(c, 1) && after_dot == 1)
        len[2]++;
}

int *len_nbr(char *nbr, int *len)
{
    int i = -1;
    char after_dot = 0;
    int zero_counter = 0;

    len[0] = 0;
    len[1] = 0;
    len[2] = 0;
    while (nbr[++i] != '\0') {
        if (nbr[i] == '.')
            after_dot = 1;
        if (nbr[i] == '0')
            zero_counter++;
        incr_len(len, nbr[i], after_dot);
    }
    if (len[0] == 0 && zero_counter > 0)
        len[0] = 1;
    return len;
}
