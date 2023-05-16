#include "password_generator.h"
#include "ui_password_generator.h"
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Password_Generator::Password_Generator(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Password_Generator)
{
    ui->setupUi(this);

    for (int i = 1; i <= 16; i++)
        ui->number_of_pass->addItem(QString::number(i));

    for (int i = 4; i <= 32; i++)
        ui->length_of_pass->addItem(QString::number(i));
}

Password_Generator::~Password_Generator()
{
    delete ui;
}

void Password_Generator::print_password(QString* password, int* counting)
{
    for (int i = 0; i < *counting; i++) {
        ui->ListPasswords->addItem(password[i]);
    }
}

// function to add symbols into the password
void Password_Generator::generate_symbol(
        QString* password, int* i, const char* str)
{
    int range = strlen(str) - 1;
    password[*i] += str[rand() % range];
}

// password generation function
void Password_Generator::generate_password(
        QString* password,
        int* length,
        int* counting,
        int character_variants_array[],
        int* character_variants_count)
{
    for (int i = 0; i < *counting; i++) {
        for (int j = 0; j < *length; j++) {
            // picking random element out of character_variants_array
            int r_elem = character_variants_array[rand() % 4];
            while (r_elem == 0)
                r_elem = character_variants_array[rand() % 4];
            switch (r_elem) {
            case 1:
                // generate number
                generate_symbol(password, &i, "0123456789");
                break;
            case 2:
                // generate lowercase letter
                generate_symbol(password, &i, "abcdefghijklmnopqrstuvwxyz");
                break;
            case 3:
                // generate capital letter
                generate_symbol(password, &i, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                break;
            case 4:
                // generate special character
                generate_symbol(password, &i, "!@#$%&_-*");
                break;
            }
        }
    }
}

// filling in the array of options
// void Password_Generator::fill_options_arr(int* add_numbers, int*
// add_lowercase_letters, int* add_capital_letters,
//        int* add_special_characters, int character_variants_array[], int*
//        character_variants_count)
//{
////    if (*add_numbers == 1) {
////        *character_variants_count += 1;
////        character_variants_array[*character_variants_count - 1] = 1;
////    }
////    if (*add_lowercase_letters == 1) {
////        *character_variants_count += 1;
////        character_variants_array[*character_variants_count - 1] = 2;
////    }
////    if (*add_capital_letters == 1) {
////        *character_variants_count += 1;
////        character_variants_array[*character_variants_count - 1] = 3;
////    }
////    if (*add_special_characters == 1) {
////        *character_variants_count += 1;
////        character_variants_array[*character_variants_count - 1] = 4;
////    }

//}

void Password_Generator::fill_options_arr(
        int* add_numbers,
        int* add_lowercase_letters,
        int* add_capital_letters,
        int* add_special_characters,
        int character_variants_array[])
{
    int character_variants_count = 0;
    if (*add_numbers == 1) {
        character_variants_array[character_variants_count] = 1;
        character_variants_count += 1;
    } else {
        character_variants_array[character_variants_count] = 0;
        character_variants_count += 1;
    }
    if (*add_lowercase_letters == 1) {
        character_variants_array[character_variants_count] = 2;
        character_variants_count += 1;
    } else {
        character_variants_array[character_variants_count] = 0;
        character_variants_count += 1;
    }
    if (*add_capital_letters == 1) {
        character_variants_array[character_variants_count] = 3;
        character_variants_count += 1;
    } else {
        character_variants_array[character_variants_count] = 0;
        character_variants_count += 1;
    }
    if (*add_special_characters == 1) {
        character_variants_array[character_variants_count] = 4;
        character_variants_count += 1;
    } else {
        character_variants_array[character_variants_count] = 0;
        character_variants_count += 1;
    }
}

int Password_Generator::on_number_of_pass_activated()
{
    QString pa = ui->number_of_pass->currentText();
    int pass_amount = pa.toInt();

    return pass_amount;
}

int Password_Generator::on_length_of_pass_activated()
{
    QString pl = ui->length_of_pass->currentText();
    int pass_length = pl.toInt();

    return pass_length;
}

int Password_Generator::on_numbers_stateChanged()
{
    // adding numbers
    int add_numbers;
    if (ui->numbers->isChecked())
        add_numbers = 1;
    else
        add_numbers = 0;

    return add_numbers;
}

int Password_Generator::on_lowercase_letters_stateChanged()
{
    // adding lowercase letters
    int add_lowercase_letters;
    if (ui->lowercase_letters->isChecked())
        add_lowercase_letters = 1;
    else
        add_lowercase_letters = 0;

    return add_lowercase_letters;
}

int Password_Generator::on_capital_letters_stateChanged()
{
    // adding capital letters
    int add_capital_letters;
    if (ui->capital_letters->isChecked())
        add_capital_letters = 1;
    else
        add_capital_letters = 0;

    return add_capital_letters;
}

int Password_Generator::on_special_characters_stateChanged()
{
    // adding special characters
    int add_special_characters;
    if (ui->special_characters->isChecked())
        add_special_characters = 1;
    else
        add_special_characters = 0;

    return add_special_characters;
}

void Password_Generator::on_pushButton_clicked()
{
    ui->ListPasswords->clear();

    int add_numbers = on_numbers_stateChanged();
    int add_lowercase_letters = on_lowercase_letters_stateChanged();
    int add_capital_letters = on_capital_letters_stateChanged();
    int add_special_characters = on_special_characters_stateChanged();
    int pass_amount = on_number_of_pass_activated();
    int pass_length = on_length_of_pass_activated();
    int character_variants_count = 1;
    int character_variants_array[4];

    fill_options_arr(
            &add_numbers,
            &add_lowercase_letters,
            &add_capital_letters,
            &add_special_characters,
            character_variants_array);

    QString passwords[pass_amount];

    generate_password(
            passwords,
            &pass_length,
            &pass_amount,
            character_variants_array,
            &character_variants_count);

    print_password(passwords, &pass_amount);
}
