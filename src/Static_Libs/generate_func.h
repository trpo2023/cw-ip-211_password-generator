#pragma once

void generate_symbol(char** password, int* i, int* j, const char* str);
void generate_password(
        char** password,
        int* length,
        int* counting,
        int character_variants_array[],
        int* character_variants_count);
void fill_options_arr(
        int* add_numbers,
        int* add_lowercase_letters,
        int* add_capital_letters,
        int* add_special_characters,
        int character_variants_array[],
        int* character_variants_count);