#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define low_length 4
#define up_length 32
#define low_amount 1
#define up_amount 16

// selection of options for password generation
void option_select(int *pass_length, int *pass_amount, int *add_numbers, int *add_lowercase_letters, int *add_capital_letters, int *add_special_characters)
{
    // a variable for checking the input of the password length and their number
    char pass_len[10], pass_amo[10];
    printf("\nGreetings. This is a password generator.\n");
    printf("----------------------------------");
    printf("\nEnter password length (4 - 32): ");
    scanf("%s", pass_len);
    // checking the entered value
    if (isdigit(*pass_len) == 0)
    {
        *pass_length = up_length;
    }
    if (isdigit(*pass_len) == 1)
    {
        *pass_length = int(atol(pass_len));
    }
    printf("----------------------------------\n");
    printf("Enter number of passwords to be shown (1 - 16): ");
    scanf("%s", pass_amo);
    // checking the entered value
    if (isdigit(*pass_amo) == 0)
    {
        *pass_amount = up_amount;
    }
    if (isdigit(*pass_amo) == 1)
    {
        *pass_amount = int(atol(pass_amo));
    }
    printf("----------------------------------\n");
    printf("Choose which characters to include in the password\n");
    printf("Enter '1' to include symbols\n");
    printf("----------------------------------\n");
    printf("Add numbers to password generation? (1/0) ");
    scanf("%d", &*add_numbers);
    printf("Add lowercase letters to password generation? (1/0) ");
    scanf("%d", &*add_lowercase_letters);
    printf("Add capital letters to password generation? (1/0) ");
    scanf("%d", &*add_capital_letters);
    printf("Add special characters to password generation? (1/0) ");
    scanf("%d", &*add_special_characters);
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