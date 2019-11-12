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

Test(my_printf_int, t01_disp_str, .init = redirect_all_stdout)
{
    my_printf("abc 1234");
    cr_assert_stdout_eq_str("abc 1234");
}

Test(my_printf_int, t02_disp_int, .init = redirect_all_stdout)
{
    my_printf("%d", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf_int, t03_disp_ints, .init = redirect_all_stdout)
{
    my_printf("%d %i", 12, 21);
    cr_assert_stdout_eq_str("12 21");
}

Test(my_printf_int, t04_flag_zero, .init = redirect_all_stdout)
{
    my_printf("%03d", 15);
    cr_assert_stdout_eq_str("015");
}

Test(my_printf_int, t05_flag_minus, .init = redirect_all_stdout)
{
    my_printf("%-3d", 15);
    cr_assert_stdout_eq_str("15 ");
}

Test(my_printf_int, t06_flag_space, .init = redirect_all_stdout)
{
    my_printf("% d", 15);
    cr_assert_stdout_eq_str(" 15");
}

Test(my_printf_int, t07_flag_plus, .init = redirect_all_stdout)
{
    my_printf("%+d", 15);
    cr_assert_stdout_eq_str("+15");
}

Test(my_printf_int, t08_negative_nbr, .init = redirect_all_stdout)
{
    my_printf("%d", -15);
    cr_assert_stdout_eq_str("-15");
}

Test(my_printf_int, t09_fieldwidth, .init = redirect_all_stdout)
{
    my_printf("%5d", 15);
    cr_assert_stdout_eq_str("   15");
}

Test(my_printf_int, t10_fieldwidthzero, .init = redirect_all_stdout)
{
    my_printf("%05d", 15);
    cr_assert_stdout_eq_str("00015");
}

Test(my_printf_int, t11_precision, .init = redirect_all_stdout)
{
    my_printf("%.5d", 15);
    cr_assert_stdout_eq_str("00015");
}

Test(my_printf_int, t12_incorrect, .init = redirect_all_stdout)
{
    my_printf("%.g5d", 15);
    cr_assert_stdout_eq_str("%.g5d");
}

Test(my_printf_int, t13_incorrect2, .init = redirect_all_stdout)
{
    my_printf("%.5m", 15);
    cr_assert_stdout_eq_str("%.5m");
}

Test(my_printf_int, t14_manyspaces, .init = redirect_all_stdout)
{
    my_printf("%    0  5d", 15);
    cr_assert_stdout_eq_str(" 0015");
}

Test(my_printf_int, t15_manyspaces2, .init = redirect_all_stdout)
{
    my_printf("%    0  5.5d", 15);
    cr_assert_stdout_eq_str(" 00015");
}
