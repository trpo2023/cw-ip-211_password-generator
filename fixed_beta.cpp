#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// selection of options for password generation
void option_select(int *pass_length, int *pass_amount, int *add_numbers, int *add_lowercase_letters, int *add_capital_letters, int *add_special_characters)
{
    printf("\nGreetings. This is a password generator.\n");
    printf("----------------------------------");
    printf("\nEnter password length (4 - 32): ");
    scanf("%d", &*pass_length);
    printf("----------------------------------\n");
    printf("Enter number of passwords to be shown (1 - 16): ");
    scanf("%d", &*pass_amount);
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
    if (pass_length < 4)
    {
        pass_length = 4;
    }
    // upper limit of the password length
    if (pass_length > 32)
    {
        pass_length = 32;
    }
    // lower limit of the password amount
    if (pass_amount < 1)
    {
        pass_amount = 1;
    }
    // upper limit of the password amount
    if (pass_amount > 16)
    {
        pass_amount = 16;
    }
}

// function to add numbers into the password
void generate_number(char **password, int *i, int *j)
{
    password[*i][*j] = '0' + rand() % 10;
}

// function to add lowercase letters into the password
void generate_lowercase_letter(char **password, int *i, int *j)
{
    password[*i][*j] = 'a' + rand() % 26;
}

// function to add capital letters into the password
void generate_capital_letter(char **password, int *i, int *j)
{
    password[*i][*j] = 'A' + rand() % 26;
}

// function to add special characters into the password
void generate_special_character(char **password, int *i, int *j)
{
    password[*i][*j] = '!' + rand() % 10;
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
            r_elem = character_variants_array[rand() % character_variants_count] - 1;
            switch (r_elem)
            {
            case 0:
                generate_number(password, &i, &j);
                break;
            case 1:
                generate_lowercase_letter(password, &i, &j);
                break;
            case 2:
                generate_capital_letter(password, &i, &j);
                break;
            case 3:
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
void print(char **password, int length, int counting)
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

// prints Pepe the frog
void pepe()
{
    printf(".\n");
    printf("══════════▄█▀▀▀▀▀▀█▄══▄▀▀▀▀▀▀▄\n");
    printf("════════▄▀░░░░░░▄▄▄▄▀█░░░░░░░░▀▄\n");
    printf("═══════█░░░░░░▀▀░░░░▀▀█▄▀▀▀▀▀▀▀█▄\n");
    printf("══════█░░░░░░░░▄▄████████▄░▄███████▄\n");
    printf("═════▄▀░░░░░░░▀███████████▄██████████▄\n");
    printf("════█▀░░░░░▄▀▀█▀░▄█▄███▄░▀█░▄█▄███░░░█\n");
    printf("═══█░░░░░░░▀▀█▀▀▄▄█████▄▄▀▀▄▄█████▀▀▀█\n");
    printf("══█▀░░░░░░░░░░▀▄▄▄▄▄▄▄▄▄▄▀░░░░░░░░▄█▀\n");
    printf("══█░░░░░░░░░░░░░░░░░░▄▀░░░░░░▀█▀▀▀█▄\n");
    printf("══█░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░█\n");
    printf("══█░░░░░░░░▄▀▀░▄▄░▀▀▀▀▀▄▄▄▄▄▄▄▀▀▀▀▀▀█\n");
    printf("══▀█░░░░░█░▀▄▀▀░░▀▀▀▀▀▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
    printf("══▄█▄▄░░░▀▄░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄▄▄▄▄▄▀\n");
    printf("▄▀▀░▀██▄░░░▀▀░░░░░░░░░░░░░░▄▄▄▀▀\n");
    printf("░░░░░░▀▀███▄▄▄▄▄▄▄▄▄▄▄▄▄████▄\n");
    printf("░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░░░▀█▄\n");
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n");
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
    for (int i = 0; i < pass_amount; i++)
    {
        password[i] = (char *)malloc(pass_length * sizeof(char));
    }

    generate_password(password, pass_length, pass_amount, character_variants_array, character_variants_count);
    print(password, pass_length, pass_amount);

    // freeing up the character_variants_arr memory
    free(character_variants_array);

    // freeing up the password array memory
    for (int i = 0; i < pass_amount; i++)
    {
        free(password[i]);
    }
    free(password);

    pepe();

    return 0;
}