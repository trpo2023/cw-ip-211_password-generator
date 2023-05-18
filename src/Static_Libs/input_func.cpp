#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_func.h"

// checking the entered data
int data_check(char word[], int range_min, int range_max)
{
    // if word is empty
    if (word == NULL) {
        // error without message
        return 1;
    }
    // if word is not empty and not a positive number
    for (int i = 0; i < (int)(strlen(word)); i++) {
        if (isdigit(word[i]) == 0) {
            // error
            return 1;
        }
    }
    // if word is digit and is in range
    if (isdigit(*word) == 1 && (int)(atol(word)) >= range_min
        && (int)(atol(word)) <= range_max) {
        // correct data entered
        return 0;
    }
    // error
    return 1;
}