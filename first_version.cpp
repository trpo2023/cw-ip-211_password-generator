#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// password generation function (so far in random form)
void generate(char **password, int length, int counting)
{
    // password count cycle
    for (int i = 0; i < counting; i++)
    {
        // password length cycle
        for (int j = 0; j < length; j++)
        {

            /*the variable responsible
            for the characters in the password. so far,
            a random number is being generated*/
            int type = 1 + rand() % 4;

            // the variable responsible for uppercase letters
            char letter_low = 'a' + rand() % 26;

            // the variable responsible for numbers
            char number = '0' + rand() % 10;

            // the variable responsible for capital letters
            char letter_high = 'A' + rand() % 26;

            // variable responsible for special characters
            char special = '!' + rand() % 5;

            // the function responsible for the type of element in the password
            switch (type)
            {
            case 1:
                password[i][j] = letter_low;
                break;
            case 2:
                password[i][j] = letter_high;
                break;
            case 3:
                password[i][j] = number;
                break;
            case 4:
                password[i][j] = special;
                break;
            }
        }
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

int main()
{
    srand(time(NULL));

    // Variable length and number of passwords
    int pass_length, pass_amount;

    printf("\nGreetings. This is a password generator.");
    printf("\nEnter password length (4 - 32): ");
    scanf("%d", &pass_length);
    printf("Enter number of passwords to be shown (1 - 16): ");
    scanf("%d", &pass_amount);

    // checking for correctly entered data

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

    // password generation function (so far in random form)
    generate(password, pass_length, pass_amount);

    // password output function
    print(password, pass_length, pass_amount);

    // freeing up the password array memory
    for (int i = 0; i < pass_amount; i++)
    {
        free(password[i]);
    }
    free(password);

    return 0;
}