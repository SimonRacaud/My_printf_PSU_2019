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

Test(my_printf, h_size_sig, .init = redirect)
{
    my_printf("%hi\n", 123);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, h_size_uns, .init = redirect)
{
    my_printf("%hu", 123);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, l_size, .init = redirect)
{
    my_printf("%li", 1000000000000);
    cr_assert_stdout_eq_str("1000000000000");
}

Test(my_printf, l_size_uns, .init = redirect)
{
    my_printf("%lu", 100000000000000);
    cr_assert_stdout_eq_str("100000000000000");
}

Test(my_printf, q_size, .init = redirect)
{
    my_printf("%qi", 10000000000000000);
    cr_assert_stdout_eq_str("10000000000000000");
}

Test(my_printf, q_size_uns, .init = redirect)
{
    my_printf("%qu", 1000000000000000000);
    cr_assert_stdout_eq_str("1000000000000000000");
}

Test(my_printf, hh_size, .init = redirect)
{
    my_printf("%hhi\n", 123);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, ll_size, .init = redirect)
{
    my_printf("%lli", 10000000000000000);
    cr_assert_stdout_eq_str("10000000000000000");
}

Test(my_printf, ll_size_uns, .init = redirect)
{
    my_printf("%llu", 1000000000000000000);
    cr_assert_stdout_eq_str("1000000000000000000");
}
