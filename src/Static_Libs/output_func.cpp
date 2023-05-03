#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "output_func.h"

void print_password(char** password, int* length, int* counting)
{
    printf("\nYour password(s):\n\n");

    for (int i = 0; i < *counting; i++) {
        printf("%2d. ", i + 1);
        for (int j = 0; j < *length; j++) {
            printf("%c", password[i][j]);
        }
        puts("\n");
    }
}

void clear(char** password, int* pass_amount)
{
    for (int i = 0; i < *pass_amount; i++) {
        free(password[i]);
    }
    free(password);
}