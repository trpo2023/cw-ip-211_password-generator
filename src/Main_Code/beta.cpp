#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../Static_Libs/generate_func.h"
#include "../Static_Libs/input_func.h"
#include "../Static_Libs/output_func.h"

void add_memory(char** password, int& pass_amount, int& pass_length)
{
    for (int i = 0; i < pass_amount; i++) {
        password[i] = new char[pass_length];
    }
}

int main()
{
    // Variable length and number of passwords
    int pass_length, pass_amount;
    // The number of character variants in the password
    int character_variants_count = 0;
    // variables responsible for including characters in the password
    int add_numbers, add_lowercase_letters, add_capital_letters,
            add_special_characters;
    // array with character variants in the password
    int* character_variants_array = new int[character_variants_count];

    /*
    values in the array:
    1 = include numbers;
    2 = include lowercase letters;
    3 = include capital letters;
    4 = include special characters;
    */

    option_select(
            &pass_length,
            &pass_amount,
            &add_numbers,
            &add_lowercase_letters,
            &add_capital_letters,
            &add_special_characters);

    fill_options_arr(
            &add_numbers,
            &add_lowercase_letters,
            &add_capital_letters,
            &add_special_characters,
            character_variants_array,
            &character_variants_count);

    // creating a multidimensional dynamic array for storing passwords
    char** password = (char**)malloc(pass_amount * sizeof(char*));
    if (password == NULL) {
        return 1;
    }

    add_memory(password, pass_amount, pass_length);

    generate_password(
            password,
            &pass_length,
            &pass_amount,
            character_variants_array,
            &character_variants_count);

    print_password(password, &pass_length, &pass_amount);

    // freeing up the character_variants_arr memory
    free(character_variants_array);

    // freeing up the password array memory
    clear(password, &pass_amount);

    return 0;
}