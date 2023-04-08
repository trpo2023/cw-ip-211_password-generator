#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

#define max_length 1000
#define low_length 4
#define up_length 32
#define low_amount 1
#define up_amount 16

// the function of checking the entered values and correcting them otherwise
int data_input(char word[], const char *type)
{
    printf("----------------------------------");
    printf("\n%s", type);

    // writing a string with spaces to a char type variable
    cin.getline(word, max_length);
    // while entered data is not a positive number
    while (isdigit(*word) == 0 && word != NULL)
    {
        // error message and re-enrty
        printf("\nIncorrect data entered! Try again.\n");
        printf("----------------------------------");
        printf("\n%s", type);
        // writing a string with spaces to a char type variable
        cin.getline(word, max_length);
    }
    // if entered data is a positive number
    if (isdigit(*word) == 1)
    {
        // convert a string type into int type and return the value
        return int(atol(word));
    }
    return 1;
}

int variants_input(char word[], char *type)
{
    printf("----------------------------------");
    printf("\nAdd %s to password generation? (1/0) ", type);

    // writing a string with spaces to a char type variable
    cin.getline(word, max_length);
    // while entered data is not a positive number
    while (isdigit(*word) == 0 && word != NULL)
    {
        // error message and re-enrty
        printf("\nIncorrect data entered! Try again.\n");
        printf("----------------------------------");
        printf("\nAdd %s to password generation? (1/0) ", type);
        // writing a string with spaces to a char type variable
        cin.getline(word, max_length);
    }
    // if entered data is a positive number
    if (isdigit(*word) == 1)
    {
        // convert a string type into int type and return the value
        return int(atol(word));
    }
    return 1;
}

// selection of options for password generation
void option_select(int *pass_length, int *pass_amount, int *add_numbers, int *add_lowercase_letters, int *add_capital_letters, int *add_special_characters)
{
    // a variable for checking the input of the password length and their number
    char pass_len[max_length], pass_amo[max_length], numbers[max_length], low_letters[max_length], capital_letters[max_length], special[max_length];
    printf("\nGreetings. This is a password generator.\n");

    *pass_length = data_input(pass_len, "Enter password length (4 - 32):");

    *pass_amount = data_input(pass_amo, "Enter number of passwords to be shown (1 - 16):");

    printf("----------------------------------\n");
    printf("Choose which characters to include in the password\n");
    printf("Enter '1' to include symbols\n");

    *add_numbers = data_input(numbers, "Add numbers to password generation? (1/0)");

    *add_lowercase_letters = data_input(low_letters, "Add lowercase letters to password generation? (1/0)");

    *add_capital_letters = data_input(capital_letters, "Add capital letters to password generation? (1/0)");

    *add_special_characters = data_input(special, "Add special characters to password generation? (1/0)");
}
// function for checking input values
void check(int &pass_length, int &pass_amount)
{
    // lower limit of the password length
    if (pass_length < low_length)
    {
        pass_length = low_length;
    }
    // upper limit of the password length
    if (pass_length > up_length)
    {
        pass_length = up_length;
    }
    // lower limit of the password amount
    if (pass_amount < low_amount)
    {
        pass_amount = low_amount;
    }
    // upper limit of the password amount
    if (pass_amount > up_amount)
    {
        pass_amount = up_amount;
    }
}

// function to symbol into the password
void generate_symbol(char **password, int *i, int *j, char a, int l)
{
    password[*i][*j] = a + rand() % l;
}

// function to add special characters into the password
void generate_special_character(char **password, int *i, int *j)
{
    // array with special characters for password
    char special_characters[] = {'!', '@', '#', '$', '%', '&', '_', '-', '*'};
    password[*i][*j] = special_characters[rand() % 8];
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
                generate_symbol(password, &i, &j, '0', 10);
                break;
            case 2:
                generate_symbol(password, &i, &j, 'a', 26);
                break;
            case 3:
                generate_symbol(password, &i, &j, 'A', 26);
                break;
            case 4:
                generate_special_character(password, &i, &j);
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
    check(pass_length, pass_amount);
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