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
    printf("\nYour passwords:\n\n");

    for (int i = 0; i < counting; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%c ", password[i][j]);
        }
        printf("\n-----------\n");
    }
}

int main()
{
    srand(time(NULL));

    // Variable length and number of passwords
    int length, counting;

    printf("\nGreetings. This is a password generator.");
    printf("\nPlease enter password length: ");
    scanf("%d", &length);
    printf("Enter number of passwords: ");
    scanf("%d", &counting);

    // creating a multidimensional dynamic array for storing passwords
    char **password = (char **)malloc(counting * sizeof(char *));
    if (password == NULL)
    {
        return 1;
    }
    for (int i = 0; i < counting; i++)
    {
        password[i] = (char *)malloc(length * sizeof(char));
    }

    // password generation function (so far in random form)
    generate(password, length, counting);

    // password output function
    print(password, length, counting);

    // freeing up the password array memory
    for (int i = 0; i < counting; i++)
    {
        free(password[i]);
    }
    free(password);
    return 0;
}