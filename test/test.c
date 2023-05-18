#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/Static_Libs/generate_func.h"
#include "../src/Static_Libs/input_func.h"
#include "../test_header/ctest.h"

CTEST(input_check, check_length_correct)
{
    char length[] = "12";
    int min = 4, max = 32;

    int expected = 0;
    int real = data_check(length, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_length_incorrect_1)
{
    char length[] = "bb!";
    int min = 4, max = 32;

    int expected = 1;
    int real = data_check(length, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_length_incorrect_2)
{
    char length[] = "ch30ck";
    int min = 4, max = 32;

    int expected = 1;
    int real = data_check(length, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_amount_correct)
{
    char amount[] = "12";
    int min = 1, max = 16;

    int expected = 0;
    int real = data_check(amount, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_amount_incorrect_1)
{
    char amount[] = "!!@#$!";
    int min = 1, max = 16;

    int expected = 1;
    int real = data_check(amount, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_amount_incorrect_2)
{
    char amount[] = "6asder";
    int min = 1, max = 16;

    int expected = 1;
    int real = data_check(amount, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_correct)
{
    char add_content[] = "1";
    int min = 0, max = 1;

    int expected = 0;
    int real = data_check(add_content, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_1)
{
    char add_content[] = "4";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_2)
{
    char add_content[] = "a";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_3)
{
    char add_content[] = "!";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, *min, *max);

    ASSERT_EQUAL(expected, real);
}

CTEST(input_check, check_input_content_incorrect_4)
{
    char add_content[] = " ";
    int min = 0, max = 1;

    int expected = 1;
    int real = data_check(add_content, *min, *max);

    ASSERT_EQUAL(expected, real);
}