#include "password_generator.h"
#include "ui_password_generator.h"

Password_Generator::Password_Generator(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Password_Generator)
{
    ui->setupUi(this);
    ui->ListPasswords;

    for (int i = 1; i <= 16; i++)
        ui->number_of_pass->addItem(QString::number(i));

    for (int i = 4; i <= 32; i++)
        ui->length_of_pass->addItem(QString::number(i));
}

Password_Generator::~Password_Generator()
{
    delete ui;
}

void Password_Generator::on_number_of_pass_activated(int index)
{
    QString number = ui->number_of_pass->currentText();
}

void Password_Generator::on_length_of_pass_activated(int index)
{
    QString length = ui->length_of_pass->currentText();
}

void Password_Generator::on_numbers_stateChanged(int arg1)
{
    // adding numbers
}

void Password_Generator::on_lowercase_letters_stateChanged(int arg1)
{
    // adding lowercase letters
}

void Password_Generator::on_capital_letters_stateChanged(int arg1)
{
    // adding capital letters
}

void Password_Generator::on_special_characters_stateChanged(int arg1)
{
    // adding special characters
}

void Password_Generator::on_pushButton_clicked()
{
    ui->ListPasswords->clear();
    QString number = ui->number_of_pass->currentText();
    QString length = ui->length_of_pass->currentText();
    int n = number.toInt();
    int l = length.toInt();
    QString passwords[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            passwords[i] += QString::number(rand() % 10);
        }
        ui->ListPasswords->addItem(passwords[i]);
    }
}
