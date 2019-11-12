/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int my_printf(char *format, ...);

Test(my_printf_uint, t01_disp_uint_diese, .init = redirect_all_stdout)
{
    my_printf("%#x", 1);
    cr_assert_stdout_eq_str("0x1");
}

Test(my_printf_uint, t02_disp_int, .init = redirect_all_stdout)
{
    my_printf("%o", 8);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf_uint, t03_disp_ints, .init = redirect_all_stdout)
{
    my_printf("%x %X", 15, 15);
    cr_assert_stdout_eq_str("f F");
}

Test(my_printf_uint, t04_flag_zero, .init = redirect_all_stdout)
{
    my_printf("%03X", 15);
    cr_assert_stdout_eq_str("00F");
}

Test(my_printf_uint, t05_flag_minus, .init = redirect_all_stdout)
{
    my_printf("%-3o", 8);
    cr_assert_stdout_eq_str("10 ");
}

Test(my_printf_uint, t06_flag_space, .init = redirect_all_stdout)
{
    my_printf("% x", 15);
    cr_assert_stdout_eq_str("f");
}

Test(my_printf_uint, t07_flag_plus, .init = redirect_all_stdout)
{
    my_printf("%+o", 3);
    cr_assert_stdout_eq_str("3");
}

Test(my_printf_uint, t08_bin, .init = redirect_all_stdout)
{
    my_printf("%b", 8);
    cr_assert_stdout_eq_str("1000");
}

Test(my_printf_uint, t09_fieldwidth, .init = redirect_all_stdout)
{
    my_printf("%5x", 15);
    cr_assert_stdout_eq_str("    f");
}

Test(my_printf_uint, t10_fieldwidthzero, .init = redirect_all_stdout)
{
    my_printf("%05x", 15);
    cr_assert_stdout_eq_str("0000f");
}

Test(my_printf_uint, t11_precision, .init = redirect_all_stdout)
{
    my_printf("%.5x", 15);
    cr_assert_stdout_eq_str("0000f");
}

Test(my_printf_uint, t12_incorrect, .init = redirect_all_stdout)
{
    my_printf("%.g5b", 15);
    cr_assert_stdout_eq_str("%.g5b");
}

Test(my_printf_uint, t13_incorrect2, .init = redirect_all_stdout)
{
    my_printf("%.5m", 15);
    cr_assert_stdout_eq_str("%.5m");
}

Test(my_printf_uint, t14_manyspaces, .init = redirect_all_stdout)
{
    my_printf("%    0  5u", 15);
    cr_assert_stdout_eq_str("00015");
}

Test(my_printf_uint, t15_manyspaces2, .init = redirect_all_stdout)
{
    my_printf("%    0  5.5u", 15);
    cr_assert_stdout_eq_str("00015");
}
