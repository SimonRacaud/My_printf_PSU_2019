/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int my_printf(char *format, ...);

Test(my_printf, t01_disp_str, .init = redirect_all_stdout)
{
    my_printf("abc 1234");
    cr_assert_stdout_eq_str("abc 1234");
}

Test(my_printf, t02_disp_int, .init = redirect_all_stdout)
{
    my_printf("%d", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, t03_disp_ints, .init = redirect_all_stdout)
{
    my_printf("%d %i", 12, 21);
    cr_assert_stdout_eq_str("12 21");
}

Test(my_printf, t04_disp_uints, .init = redirect_all_stdout)
{
    my_printf("%o %u %x %X", 9, 9, 15, 15);
    cr_assert_stdout_eq_str("11 9 f F");
}

Test(my_printf, t05_disp_char, .init = redirect_all_stdout)
{
    my_printf("%c %c", 's', 32);
    cr_assert_stdout_eq_str("s  ");
}

Test(my_printf, t06_disp_str, .init = redirect_all_stdout)
{
    my_printf("%s |", "Hello world");
    cr_assert_stdout_eq_str("Hello world |");
}

Test(my_printf, t07_disp_ptr, .init = redirect_all_stdout)
{
    int *ptr = NULL;

    my_printf("%p", ptr);
    cr_assert_stdout_eq_str("(nil)");
}

Test(my_printf, t08_disp_perc, .init = redirect_all_stdout)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, t09_disp_bin, .init = redirect_all_stdout)
{
    my_printf("%b", (unsigned int)5);
    cr_assert_stdout_eq_str("101");
}

Test(my_printf, t10_disp_npstr, .init = redirect_all_stdout)
{
    my_printf("%S\n", "\n\t");
    cr_assert_stdout_eq_str("\\012\\011\n");
}

Test(my_printf, t11_flag_diese1, .init = redirect_all_stdout)
{
    my_printf("%#o", 8);
    cr_assert_stdout_eq_str("010");
}

Test(my_printf, t12_flag_diese2, .init = redirect_all_stdout)
{
    my_printf("%#x", 15);
    cr_assert_stdout_eq_str("0xf");
}

Test(my_printf, t13_flag_diese3, .init = redirect_all_stdout)
{
    my_printf("%#X", 15);
    cr_assert_stdout_eq_str("0XF");
}

Test(my_printf, t14_flag_zero, .init = redirect_all_stdout)
{
    my_printf("%03d", 15);
    cr_assert_stdout_eq_str("015");
}

Test(my_printf, t15_flag_minus, .init = redirect_all_stdout)
{
    my_printf("%-3d", 15);
    cr_assert_stdout_eq_str("15 ");
}

Test(my_printf, t16_flag_space, .init = redirect_all_stdout)
{
    my_printf("% d", 15);
    cr_assert_stdout_eq_str(" 15");
}

Test(my_printf, t17_flag_plus, .init = redirect_all_stdout)
{
    my_printf("%+d", 15);
    cr_assert_stdout_eq_str("+15");
}

Test(my_printf, t18_negative_nbr, .init = redirect_all_stdout)
{
    my_printf("%d", -15);
    cr_assert_stdout_eq_str("-15");
}

Test(my_printf, t19_fieldwidth, .init = redirect_all_stdout)
{
    my_printf("%5d", 15);
    cr_assert_stdout_eq_str("   15");
}

Test(my_printf, t20_fieldwidthzero, .init = redirect_all_stdout)
{
    my_printf("%05d", 15);
    cr_assert_stdout_eq_str("00015");
}

Test(my_printf, t21_precision, .init = redirect_all_stdout)
{
    my_printf("%.5d", 15);
    cr_assert_stdout_eq_str("00015");
}

Test(my_printf, t22_precision_str, .init = redirect_all_stdout)
{
    my_printf("%.2s", "abc");
    cr_assert_stdout_eq_str("ab");
}

Test(my_printf, t23_precision_str2, .init = redirect_all_stdout)
{
    my_printf("%.s ", "abc");
    cr_assert_stdout_eq_str(" ");
}

Test(my_printf, t24_longlong, .init = redirect_all_stdout)
{
    my_printf("%lld", 123456789123456789);
    cr_assert_stdout_eq_str("123456789123456789");
}

Test(my_printf, t25_ulonglong, .init = redirect_all_stdout)
{
    my_printf("%llu", 123456789123456789);
    cr_assert_stdout_eq_str("123456789123456789");
}

Test(my_printf, t26_simpleint_withstr, .init = redirect_all_stdout)
{
    my_printf("i (%d)", 123456789);
    cr_assert_stdout_eq_str("i (123456789)");
}

Test(my_printf, t27_len_wrote, .init = redirect_all_stdout)
{
    int ret = my_printf("%d\n", 123456789);

    cr_assert_eq(ret, 10);
}

Test(my_printf, t28_len_wrote2, .init = redirect_all_stdout)
{
    int ret = my_printf("%s %#-5.8o\n", "abc", 2);

    cr_assert_eq(ret, 13);
}

Test(my_printf, t29_len_wrote3, .init = redirect_all_stdout)
{
    int ret = my_printf("%.5s\n", "0123456789");

    cr_assert_eq(ret, 6);
}

Test(my_printf, t30_len_wrote4, .init = redirect_all_stdout)
{
    int *ptr = NULL;
    int ret = my_printf("%p\n", ptr);

    cr_assert_eq(ret, 6);
}

Test(my_printf, t31_len_wrote5, .init = redirect_all_stdout)
{
    int data = 42;
    int *ptr = &data;
    int ret = my_printf("%p\n", ptr);

    cr_assert_eq(ret, 15);
}

Test(my_printf, t32_len_wrote6, .init = redirect_all_stdout)
{
    int ret = my_printf("%%\n");

    cr_assert_eq(ret, 2);
}

Test(my_printf, t33_len_wrote7, .init = redirect_all_stdout)
{
    int ret = my_printf("%#0-hh5.7y\n");

    cr_assert_eq(ret, 11);
}

Test(my_printf, t34_len_wrote8, .init = redirect_all_stdout)
{
    int ret = my_printf("%b\n", 42);

    cr_assert_eq(ret, 7);
}

Test(my_printf, t35_q, .init = redirect_all_stdout)
{
    my_printf("%qd", 1234567891234567899);
    cr_assert_stdout_eq_str("1234567891234567899");
}

Test(my_printf, t36_q, .init = redirect_all_stdout)
{
    my_printf("%qu", 18446744073709551615);
    cr_assert_stdout_eq_str("18446744073709551615");
}
