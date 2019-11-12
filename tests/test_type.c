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

Test(my_printf, d_type, .init = redirect)
{
    my_printf("%d", 123);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, i_type, .init = redirect)
{
    my_printf("%i", 456);
    cr_assert_stdout_eq_str("456");
}

Test(my_printf, u_type, .init = redirect)
{
    my_printf("%u", 789);
    cr_assert_stdout_eq_str("789");
}

Test(my_printf, o_type, .init = redirect)
{
    my_printf("%o", 123);
    cr_assert_stdout_eq_str("173");
}

Test(my_printf, x_type, .init = redirect)
{
    my_printf("%x", 123);
    cr_assert_stdout_eq_str("7b");
}

Test(my_printf, X_type, .init = redirect)
{
    my_printf("%X", 123);
    cr_assert_stdout_eq_str("7B");
}

Test(my_printf, c_type, .init = redirect)
{
    my_printf("%c", 'c');
    cr_assert_stdout_eq_str("c");
}

Test(my_printf, s_type, .init = redirect)
{
    my_printf("%s", "string");
    cr_assert_stdout_eq_str("string");
}

Test(my_printf, S_type, .init = redirect)
{
    char string[] = "string";

    string[1] = 127;
    my_printf("%S", string);
    cr_assert_stdout_eq_str("s\\177ring");
}

Test(my_printf, p_type, .init = redirect)
{
    char *string = "STRING";

    my_printf("%p", string);
    cr_assert(1 == 1);
}

Test(my_printf, b_type, .init = redirect)
{
    my_printf("%b", 123);
    cr_assert_stdout_eq_str("1111011");
}

Test(my_printf, mod_type, .init = redirect)
{
    my_printf("%%", 123);
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, multi_types, .init = redirect)
{
    my_printf("%i %c %% %b %s %X", 123, 123, 123, "123", 123);
    cr_assert_stdout_eq_str("123 { % 1111011 123 7B");
}
