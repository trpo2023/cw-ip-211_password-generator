#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generate_func.h"

// function to add symbols into the password
void generate_symbol(char** password, int* i, int* j, const char* str)
{
    int range = strlen(str) - 1;
    password[*i][*j] = str[rand() % range];
}

// password generation function
void generate_password(
        char** password,
        int* length,
        int* counting,
        int character_variants_array[],
        int* character_variants_count)
{
    int r_elem;
    for (int i = 0; i < *counting; i++) {
        for (int j = 0; j < *length; j++) {
            // picking random element out of character_variants_array
            r_elem = character_variants_array
                    [rand() % (*character_variants_count)];
            switch (r_elem) {
            case 1:
                // generate number
                generate_symbol(password, &i, &j, "0123456789");
                break;
            case 2:
                // generate lowercase letter
                generate_symbol(password, &i, &j, "abcdefghijklmnopqrstuvwxyz");
                break;
            case 3:
                // generate capital letter
                generate_symbol(password, &i, &j, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                break;
            case 4:
                // generate special character
                generate_symbol(password, &i, &j, "!@#$%&_-*");
                break;
            }
        }
    }
}

// filling in the array of options
void fill_options_arr(
        int* add_numbers,
        int* add_lowercase_letters,
        int* add_capital_letters,
        int* add_special_characters,
        int character_variants_array[],
        int* character_variants_count)
{
    if (*add_numbers == 1) {
        *character_variants_count += 1;
        character_variants_array[*character_variants_count - 1] = 1;
    }
    if (*add_lowercase_letters == 1) {
        *character_variants_count += 1;
        character_variants_array[*character_variants_count - 1] = 2;
    }
    if (*add_capital_letters == 1) {
        *character_variants_count += 1;
        character_variants_array[*character_variants_count - 1] = 3;
    }
    if (*add_special_characters == 1) {
        *character_variants_count += 1;
        character_variants_array[*character_variants_count - 1] = 4;
    }
    // if the user has not entered any options,
    // the password is generated from numbers by default
    if (*character_variants_count == 0) {
        *character_variants_count = 1;
        character_variants_array[*character_variants_count - 1] = 1;
    }
}