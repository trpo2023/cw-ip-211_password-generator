#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "input_func.h"

#define MAX_LENGTH 100

// print error message
int error_message()
{
    printf("\nIncorrect data entered! Try again.\n");
    return 1;
}

// data entry
int data_input(char word[], const char* type, int range_min, int range_max)
{
    // flag to check the correctness of the entered data
    int correct_data = 1;
    // while entered data is not correct
    while (correct_data != 0) {
        // print a message of what user should enter
        printf("----------------------------------");
        printf("\n%s", type);
        // user enters data
        std::cin.getline(word, MAX_LENGTH);
        // fill the flag via data_check function
        correct_data = data_check(word, range_min, range_max);
    }
    // convert a string type into int type and return the value
    return int(atol(word));
}

// checking the entered data
int data_check(char word[], int range_min, int range_max)
{
    // if word is empty
    if (word == NULL) {
        // error without message
        return 1;
    }
    // if word is not empty and not a positive number
    for (int i = 0; i < int(strlen(word)); i++) {
        if (isdigit(word[i]) == 0) {
            // error
            return error_message();
        }
    }
    // if word is digit and is in range
    if (isdigit(*word) == 1 && int(atol(word)) >= range_min
        && int(atol(word)) <= range_max) {
        // correct data entered
        return 0;
    }
    // error
    return error_message();
}

// selection of options for password generation
void option_select(
        int* pass_length,
        int* pass_amount,
        int* add_numbers,
        int* add_lowercase_letters,
        int* add_capital_letters,
        int* add_special_characters)
{
    // a variable for checking the input of the password length and their number
    char pass_len[MAX_LENGTH], pass_amo[MAX_LENGTH], numbers[MAX_LENGTH],
            low_letters[MAX_LENGTH], capital_letters[MAX_LENGTH],
            special[MAX_LENGTH];
    printf("\nGreetings. This is a password generator.\n");

    *pass_length
            = data_input(pass_len, "Enter password length (4 - 32):", 4, 32);

    *pass_amount = data_input(
            pass_amo, "Enter number of passwords to be shown (1 - 16):", 1, 16);

    printf("----------------------------------\n");
    printf("Choose which characters to include in the password\n");
    printf("Enter '1' to include symbols\n");

    *add_numbers = data_input(
            numbers, "Add numbers to password generation? (1/0)", 0, 1);

    *add_lowercase_letters = data_input(
            low_letters,
            "Add lowercase letters to password generation? (1/0)",
            0,
            1);

    *add_capital_letters = data_input(
            capital_letters,
            "Add capital letters to password generation? (1/0)",
            0,
            1);

    *add_special_characters = data_input(
            special,
            "Add special characters to password generation? (1/0)",
            0,
            1);
}