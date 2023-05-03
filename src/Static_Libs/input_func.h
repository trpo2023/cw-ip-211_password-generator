#pragma once

int data_input(char word[], const char* type, int range_min, int range_max);
int error_message();
int data_check(char word[], int range_min, int range_max);
void option_select(
        int* pass_length,
        int* pass_amount,
        int* add_numbers,
        int* add_lowercase_letters,
        int* add_capital_letters,
        int* add_special_characters);