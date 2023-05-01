#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

// using namespace std;

#define MAX_LENGTH 100

// checking the entered data
int data_check(char word[], int range_min, int range_max);

// print error message
int error_message()
{
    printf("\nIncorrect data entered! Try again.\n");
    return 1;
}

// data entry
int data_input(char word[], const char *type, int range_min, int range_max)
{
    // flag to check the correctness of the entered data
    int correct_data = 1;
    // while entered data is not correct
    while (correct_data != 0)
    {
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
    if (word == NULL)
    {
        // error without message
        return 1;
    }
    // if word is not empty and not a positive number
    for (int i = 0; i < int(strlen(word)); i++)
    {
        if (isdigit(word[i]) == 0)
        {
            // error
            return error_message();
        }
    }
    // if word is digit and is in range
    if (isdigit(*word) == 1 && int(atol(word)) >= range_min && int(atol(word)) <= range_max)
    {
        // correct data entered
        return 0;
    }
    // error
    return error_message();
}

// selection of options for password generation
void option_select(int *pass_length, int *pass_amount, int *add_numbers, int *add_lowercase_letters, int *add_capital_letters, int *add_special_characters)
{
    // a variable for checking the input of the password length and their number
    char pass_len[MAX_LENGTH], pass_amo[MAX_LENGTH], numbers[MAX_LENGTH], low_letters[MAX_LENGTH], capital_letters[MAX_LENGTH], special[MAX_LENGTH];
    printf("\nGreetings. This is a password generator.\n");

    *pass_length = data_input(pass_len, "Enter password length (4 - 32):", 4, 32);

    *pass_amount = data_input(pass_amo, "Enter number of passwords to be shown (1 - 16):", 1, 16);

    printf("----------------------------------\n");
    printf("Choose which characters to include in the password\n");
    printf("Enter '1' to include symbols\n");

    *add_numbers = data_input(numbers, "Add numbers to password generation? (1/0)", 0, 1);

    *add_lowercase_letters = data_input(low_letters, "Add lowercase letters to password generation? (1/0)", 0, 1);

    *add_capital_letters = data_input(capital_letters, "Add capital letters to password generation? (1/0)", 0, 1);

    *add_special_characters = data_input(special, "Add special characters to password generation? (1/0)", 0, 1);
}

// function to add symbols into the password
void generate_symbol(char **password, int *i, int *j, const char *str)
{
    int range = strlen(str) - 1;
    password[*i][*j] = str[rand() % range];
}

// password generation function
void generate_password(char **password, int length, int counting, int *character_variants_array, int character_variants_count)
{
    int r_elem;
    for (int i = 0; i < counting; i++)
    {
        for (int j = 0; j < length; j++)
        {
            // picking random element out of character_variants_array
            r_elem = character_variants_array[rand() % character_variants_count];
            switch (r_elem)
            {
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
void fill_options_arr(int add_numbers, int add_lowercase_letters, int add_capital_letters, int add_special_characters, int character_variants_array[], int &character_variants_count)
{
    if (add_numbers == 1)
    {
        character_variants_count += 1;
        character_variants_array[character_variants_count - 1] = 1;
    }
    if (add_lowercase_letters == 1)
    {
        character_variants_count += 1;
        character_variants_array[character_variants_count - 1] = 2;
    }
    if (add_capital_letters == 1)
    {
        character_variants_count += 1;
        character_variants_array[character_variants_count - 1] = 3;
    }
    if (add_special_characters == 1)
    {
        character_variants_count += 1;
        character_variants_array[character_variants_count - 1] = 4;
    }
    // if the user has not entered any options,
    // the password is generated from numbers by default
    if (character_variants_count == 0)
    {
        character_variants_count = 1;
        character_variants_array[character_variants_count - 1] = 1;
    }
}

// password output function
void print_password(char **password, int length, int counting)
{
    printf("\nYour password(s):\n\n");

    for (int i = 0; i < counting; i++)
    {
        printf("%2d. ", i + 1);
        for (int j = 0; j < length; j++)
        {
            printf("%c", password[i][j]);
        }
        puts("\n");
    }
}

void add_memory(char **password, int &pass_amount, int &pass_length)
{
    for (int i = 0; i < pass_amount; i++)
    {
        password[i] = new char[pass_length];
    }
}

void clear(char **password, int &pass_amount)
{
    for (int i = 0; i < pass_amount; i++)
    {
        free(password[i]);
    }
    free(password);
}

int main()
{
    srand(time(NULL));

    // Variable length and number of passwords
    int pass_length, pass_amount;
    // The number of character variants in the password
    int character_variants_count = 0;
    // variables responsible for including characters in the password
    int add_numbers, add_lowercase_letters, add_capital_letters, add_special_characters;
    // array with character variants in the password
    int *character_variants_array = new int[character_variants_count];

    /*
    values in the array:
    1 = include numbers;
    2 = include lowercase letters;
    3 = include capital letters;
    4 = include special characters;
    */

    option_select(&pass_length, &pass_amount, &add_numbers, &add_lowercase_letters, &add_capital_letters, &add_special_characters);
    fill_options_arr(add_numbers, add_lowercase_letters, add_capital_letters, add_special_characters, character_variants_array, character_variants_count);

    // creating a multidimensional dynamic array for storing passwords
    char **password = (char **)malloc(pass_amount * sizeof(char *));
    if (password == NULL)
    {
        return 1;
    }
    add_memory(password, pass_amount, pass_length);

    generate_password(password, pass_length, pass_amount, character_variants_array, character_variants_count);
    print_password(password, pass_length, pass_amount);

    // freeing up the character_variants_arr memory
    free(character_variants_array);

    // freeing up the password array memory
    clear(password, pass_amount);

    return 0;
}