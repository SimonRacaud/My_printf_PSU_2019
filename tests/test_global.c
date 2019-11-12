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

Test(my_printf, hash_flag_width_sup_prec_and_x_type, .init = redirect)
{
    my_printf("%#10.4x", 123);
    cr_assert_stdout_eq_str("    0x007b");
}

Test(my_printf, hash_flag_width_sup_prec_and_X_type, .init = redirect)
{
    my_printf("%#10.4X", 123);
    cr_assert_stdout_eq_str("    0X007B");
}

Test(my_printf, hash_flag_width_sup_prec_and_o_type, .init = redirect)
{
    my_printf("%#10.4o", 123);
    cr_assert_stdout_eq_str("      0173");
}

Test(my_printf, plus_flag_width_sup_prec_and_d_type, .init = redirect)
{
    my_printf("%+10.4d", 123);
    cr_assert_stdout_eq_str("     +0123");
}

Test(my_printf, space_flag_width_sup_prec_and_d_type, .init = redirect)
{
    my_printf("% 10.4d", 123);
    cr_assert_stdout_eq_str("      0123");
}

Test(my_printf, width_sup_prec_and_s_type, .init = redirect)
{
    my_printf("%4.3s", "HELLO");
    cr_assert_stdout_eq_str(" HEL");
}

Test(my_printf, width_eq_prec_and_s_type, .init = redirect)
{
    my_printf("%4.4s", "HELLO");
    cr_assert_stdout_eq_str("HELL");
}

Test(my_printf, width_inf_prec_and_s_type, .init = redirect)
{
    my_printf("%3.4s", "HELLO");
    cr_assert_stdout_eq_str("HELL");
}

Test(my_printf, width_and_s_type, .init = redirect)
{
    my_printf("%3s", "HELLO");
    cr_assert_stdout_eq_str("HELLO");
}

Test(my_printf, width_sup_len_sup__prec_and_s_type, .init = redirect)
{
    my_printf("%10.3s", "HELLO");
    cr_assert_stdout_eq_str("       HEL");
}
