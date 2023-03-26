#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// password generation function (so far in random form)
void generate(char **password, int length, int counting, int type_id)
{
    switch (type_id)
    {
    case 0:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                password[i][j] = '0' + rand() % 10;
            }
        }
        break;
    case 1:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                password[i][j] = 'a' + rand() % 26;
            }
        }
        break;
    case 2:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                password[i][j] = 'A' + rand() % 26;
            }
        }
        break;
    case 3:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                password[i][j] = '!' + rand() % 5;
            }
        }
        break;
    case 4:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 2; // Variable for random selection of elements from those selected for the password
                if (token == 1)
                {
                    password[i][j] = '0' + rand() % 10;
                }
                else
                {
                    password[i][j] = 'a' + rand() % 26;
                }
            }
        }
        break;
    case 5:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 2; // Variable for random selection of elements from those selected for the password
                if (token == 1)
                {
                    password[i][j] = '0' + rand() % 10;
                }
                else
                {
                    password[i][j] = 'A' + rand() % 26;
                }
            }
        }
        break;
    case 6:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 2; // Variable for random selection of elements from those selected for the password
                if (token == 1)
                {
                    password[i][j] = '0' + rand() % 10;
                }
                else
                {
                    password[i][j] = '!' + rand() % 5;
                }
            }
        }
        break;
    case 7:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 2; // Variable for random selection of elements from those selected for the password
                if (token == 1)
                {
                    password[i][j] = 'a' + rand() % 26;
                }
                else
                {
                    password[i][j] = 'A' + rand() % 26;
                }
            }
        }
        break;
    case 8:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 2; // Variable for random selection of elements from those selected for the password
                if (token == 1)
                {
                    password[i][j] = 'a' + rand() % 26;
                }
                else
                {
                    password[i][j] = '!' + rand() % 5;
                }
            }
        }
        break;
    case 9:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 2; // Variable for random selection of elements from those selected for the password
                if (token == 1)
                {
                    password[i][j] = 'A' + rand() % 26;
                }
                else
                {
                    password[i][j] = '!' + rand() % 5;
                }
            }
        }
        break;
    case 10:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 3; // Variable for random selection of elements from those selected for the password
                switch (token)
                {
                case 1:
                    password[i][j] = '0' + rand() % 10;
                    break;
                case 2:
                    password[i][j] = 'a' + rand() % 26;
                    break;
                case 3:
                    password[i][j] = 'A' + rand() % 26;
                    break;
                }
            }
        }
        break;
    case 11:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 3; // Variable for random selection of elements from those selected for the password
                switch (token)
                {
                case 1:
                    password[i][j] = '0' + rand() % 10;
                    break;
                case 2:
                    password[i][j] = 'a' + rand() % 26;
                    break;
                case 3:
                    password[i][j] = '!' + rand() % 5;
                    break;
                }
            }
        }
        break;
    case 12:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 3; // Variable for random selection of elements from those selected for the password
                switch (token)
                {
                case 1:
                    password[i][j] = '!' + rand() % 5;
                    break;
                case 2:
                    password[i][j] = 'a' + rand() % 26;
                    break;
                case 3:
                    password[i][j] = 'A' + rand() % 26;
                    break;
                }
            }
        }
        break;
    case 13:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 3; // Variable for random selection of elements from those selected for the password
                switch (token)
                {
                case 1:
                    password[i][j] = '0' + rand() % 10;
                    break;
                case 2:
                    password[i][j] = '!' + rand() % 5;
                    break;
                case 3:
                    password[i][j] = 'A' + rand() % 26;
                    break;
                }
            }
        }
        break;
    case 14:
        for (int i = 0; i < counting; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int token = 1 + rand() % 4; // Variable for random selection of elements from those selected for the password
                switch (token)
                {
                case 1:
                    password[i][j] = '0' + rand() % 10;
                    break;
                case 2:
                    password[i][j] = 'a' + rand() % 26;
                    break;
                case 3:
                    password[i][j] = 'A' + rand() % 26;
                    break;
                case 4:
                    password[i][j] = '!' + rand() % 5;
                    break;
                }
            }
        }
        break;
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

// function for checking input values
void check(int &pass_length, int &pass_amount)
{
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

// information input function
void enter_info(int &pass_length, int &pass_amount, int &type_id)
{
    printf("\nGreetings. This is a password generator.\n");
    printf("----------------------------------");
    printf("\nEnter password length (4 - 32): ");
    scanf("%d", &pass_length);
    printf("----------------------------------\n");
    printf("Enter number of passwords to be shown (1 - 16): ");
    scanf("%d", &pass_amount);
    printf("----------------------------------\n");
    printf("Choose what the password will consist of:\n");
    printf("1. Uppercase letters (a)\n");
    printf("2. Capital letters (A)\n");
    printf("3. Special characters (!)\n");
    printf("4. Numbers and uppercase letters (1a)\n");
    printf("5. Numbers and capital letters (1A)\n");
    printf("6. Numbers and special characters (1!)\n");
    printf("7. Uppercase letters and capital letters (aA)\n");
    printf("8. Uppercase letters and special characters (a!)\n");
    printf("9. Capital letters and special characters (A!)\n");
    printf("10. Numbers and uppercase letters and capital letters (1aA)\n");
    printf("11. Numbers and uppercase letters and special characters (1a!)\n");
    printf("12. Uppercase letters and capital letters and special characters (aA!)\n");
    printf("13. Number and capital letters and special characters (1A!)\n");
    printf("14. All inclusive (1aA!)\n");
    printf("If you want to default then press 0\n");
    printf("Your choice: ");
    scanf("%d", &type_id); // The variable responsible for what the password consists of
}

int main()
{
    srand(time(NULL));

    // Variable length and number of passwords
    int pass_length, pass_amount, type_id;

    enter_info(pass_length, pass_amount, type_id);
    check(pass_length, pass_amount);

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
    generate(password, pass_length, pass_amount, type_id);

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