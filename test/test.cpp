#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/Static_Libs/generate_func.cpp"
#include "../src/Static_Libs/input_func.cpp"
#include "../test_header/ctest.h"

CTEST(input_check, check_length_correct)
{
    char length[] = "12";
    int min = 4, max = 32;

    int expected = 0;
    int real = data_check(length, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_length_incorrect_1)
{
    char length[] = "bb!";
    int min = 4, max = 32;

    int expected = 1;
    int real = data_check(length, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_length_incorrect_2)
{
    char length[] = "ch30ck";
    int min = 4, max = 32;

    int expected = 1;
    int real = data_check(length, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_amount_correct)
{
    char amount[] = "12";
    int min = 1, max = 16;

    int expected = 0;
    int real = data_check(amount, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_amount_incorrect_1)
{
    char amount[] = "!!@#$!";
    int min = 1, max = 16;

    int expected = 1;
    int real = data_check(amount, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_amount_incorrect_2)
{
    char amount[] = "6asder";
    int min = 1, max = 16;

    int expected = 1;
    int real = data_check(amount, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_correct)
{
    char add_content[] = "1";
    int min = 0, max = 1;

    int expected = 0;
    int real = data_check(add_content, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_1)
{
    char add_content[] = "4";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_2)
{
    char add_content[] = "a";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_3)
{
    char add_content[] = "!";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_4)
{
    char add_content[] = " ";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, min, max);

    ASSERT_EQUAL(expected, real);
}

CTEST(fill_options_check, variants_count_check_1)
{
    int* variants_array = new int[0];
    int real = 0, numbers = 0, lowercase = 0, uppercase = 0, symbols = 0;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &real);

    int expected = 1;

    ASSERT_EQUAL(expected, real);
}

CTEST(fill_options_check, variants_count_check_2)
{
    int* variants_array = new int[0];
    int real = 0, numbers = 1, lowercase = 1, uppercase = 0, symbols = 0;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &real);
    int expected = 2;

    ASSERT_EQUAL(expected, real);
}

CTEST(fill_options_check, variants_count_check_3)
{
    int* variants_array = new int[0];
    int real = 0, numbers = 0, lowercase = 1, uppercase = 1, symbols = 1;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &real);
    int expected = 3;

    ASSERT_EQUAL(expected, real);
}

CTEST(fill_options_check, variants_count_check_4)
{
    int* variants_array = new int[0];
    int real = 0, numbers = 1, lowercase = 1, uppercase = 1, symbols = 1;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &real);
    int expected = 4;

    ASSERT_EQUAL(expected, real);
}

CTEST(fill_options_check, variants_array_check_1)
{
    int* variants_array = new int[0];
    int count = 0, numbers = 0, lowercase = 0, uppercase = 0, symbols = 0;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &count);

    int real = variants_array[0];
    int expected = 1;

    ASSERT_EQUAL(expected, real);
}

CTEST(fill_options_check, variants_array_check_2)
{
    int* variants_array = new int[0];
    int count = 0, numbers = 0, lowercase = 1, uppercase = 1, symbols = 0;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &count);

    int real_1 = variants_array[0], real_2 = variants_array[count - 1];
    int expected_1 = 2, expected_2 = 3;

    ASSERT_EQUAL(expected_1, real_1);
    ASSERT_EQUAL(expected_2, real_2);
}

CTEST(fill_options_check, variants_array_check_3)
{
    int* variants_array = new int[0];
    int count = 0, numbers = 0, lowercase = 1, uppercase = 1, symbols = 1;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &count);

    int real_1 = variants_array[0], real_2 = variants_array[count - 2],
        real_3 = variants_array[count - 1];
    int expected_1 = 2, expected_2 = 3, expected_3 = 4;

    ASSERT_EQUAL(expected_1, real_1);
    ASSERT_EQUAL(expected_2, real_2);
    ASSERT_EQUAL(expected_3, real_3);
}

CTEST(fill_options_check, variants_array_check_4)
{
    int* variants_array = new int[0];
    int count = 0, numbers = 1, lowercase = 1, uppercase = 1, symbols = 1;
    fill_options_arr(
            &numbers, &lowercase, &uppercase, &symbols, variants_array, &count);

    int real_1 = variants_array[0], real_2 = variants_array[count - 3],
        real_3 = variants_array[count - 2], real_4 = variants_array[count - 1];
    int expected_1 = 1, expected_2 = 2, expected_3 = 3, expected_4 = 4;

    ASSERT_EQUAL(expected_1, real_1);
    ASSERT_EQUAL(expected_2, real_2);
    ASSERT_EQUAL(expected_3, real_3);
    ASSERT_EQUAL(expected_4, real_4);
}