/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Test for disp_stdarg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include <stdio.h>

static void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, hash_flag_and_o_type, .init = redirect)
{
    my_printf("%#o", 123);
    cr_assert_stdout_eq_str("0173");
}

Test(my_printf, hash_flag_and_x_type, .init = redirect)
{
    my_printf("%#x", 123);
    cr_assert_stdout_eq_str("0x7b");
}

Test(my_printf, hash_flag_and_X_type, .init = redirect)
{
    my_printf("%#X", 123);
    cr_assert_stdout_eq_str("0X7B");
}

Test(my_printf, space_flag_and_d_type, .init = redirect)
{
    my_printf("% d", 123);
    cr_assert_stdout_eq_str(" 123");
}

Test(my_printf, space_flag_and_i_type, .init = redirect)
{
    my_printf("% i", -123);
    cr_assert_stdout_eq_str("-123");
}

Test(my_printf, plus_flag_and_d_type, .init = redirect)
{
    my_printf("%+d", 123);
    cr_assert_stdout_eq_str("+123");
}

Test(my_printf, plus_flag_and_i_type, .init = redirect)
{
    my_printf("%+i", -123);
    cr_assert_stdout_eq_str("-123");
}

Test(my_printf, zero_flag_and_d_type, .init = redirect)
{
    my_printf("%05d", -123);
    cr_assert_stdout_eq_str("-0123");
}

Test(my_printf, zero_flag_and_i_type, .init = redirect)
{
    my_printf("%05i", 123);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, zero_flag_and_o_type, .init = redirect)
{
    my_printf("%05o", 123);
    cr_assert_stdout_eq_str("00173");
}

Test(my_printf, zero_flag_and_u_type, .init = redirect)
{
    my_printf("%05u", 123);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, zero_flag_and_x_type, .init = redirect)
{
    my_printf("%05x", 123);
    cr_assert_stdout_eq_str("0007b");
}

Test(my_printf, zero_flag_and_X_type, .init = redirect)
{
    my_printf("%05X", 123);
    cr_assert_stdout_eq_str("0007B");
}

Test(my_printf, zero_flag_and_b_type, .init = redirect)
{
    my_printf("%010b", 123);
    cr_assert_stdout_eq_str("0001111011");
}

Test(my_printf, minus_flag_and_d_type, .init = redirect)
{
    my_printf("%-5d", 123);
    cr_assert_stdout_eq_str("123  ");
}

Test(my_printf, minus_flag_and_i_type, .init = redirect)
{
    my_printf("%-5i", -123);
    cr_assert_stdout_eq_str("-123 ");
}

Test(my_printf, minus_flag_and_u_type, .init = redirect)
{
    my_printf("%-5u", 123);
    cr_assert_stdout_eq_str("123  ");
}

Test(my_printf, minus_flag_and_o_type, .init = redirect)
{
    my_printf("%-5o", 123);
    cr_assert_stdout_eq_str("173  ");
}

Test(my_printf, minus_flag_and_x_type, .init = redirect)
{
    my_printf("%-5x", 123);
    cr_assert_stdout_eq_str("7b   ");
}

Test(my_printf, minus_flag_and_X_type, .init = redirect)
{
    my_printf("%-5X", 123);
    cr_assert_stdout_eq_str("7B   ");
}

Test(my_printf, minus_flag_and_c_type, .init = redirect)
{
    my_printf("%-5c", 'a');
    cr_assert_stdout_eq_str("a    ");
}

Test(my_printf, minus_flag_and_s_type, .init = redirect)
{
    my_printf("%-5s", "HEY");
    cr_assert_stdout_eq_str("HEY  ");
}

Test(my_printf, minus_flag_and_b_type, .init = redirect)
{
    my_printf("%-10b", 123);
    cr_assert_stdout_eq_str("1111011   ");
}

Test(my_printf, minus_flag_and_S_type, .init = redirect)
{
    char array[4] = "HEY";

    array[1] = 1;
    my_printf("%-10S", array);
    cr_assert_stdout_eq_str("H\\001Y    ");
}

Test(my_printf, minus_flag_and_S_type_with_prec, .init = redirect)
{
    char array[] = "HEY";

    array[1] = 1;
    my_printf("%-10.2S", array);
    cr_assert_stdout_eq_str("H\\001     ");
}
