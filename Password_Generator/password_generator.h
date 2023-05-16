#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Password_Generator;
}
QT_END_NAMESPACE

class Password_Generator : public QMainWindow {
    Q_OBJECT

public:
    Password_Generator(QWidget* parent = nullptr);
    ~Password_Generator();

private slots:
    void print_password(QString* password, int* counting);

    void generate_symbol(QString* password, int* i, const char* str);

    void generate_password(
            QString* password,
            int* length,
            int* counting,
            int character_variants_array[],
            int* character_variants_count);

    void fill_options_arr(
            int* add_numbers,
            int* add_lowercase_letters,
            int* add_capital_letters,
            int* add_special_characters,
            int character_variants_array[]);

    int on_number_of_pass_activated();

    int on_length_of_pass_activated();

    int on_numbers_stateChanged();

    int on_lowercase_letters_stateChanged();

    int on_capital_letters_stateChanged();

    int on_special_characters_stateChanged();

    void on_pushButton_clicked();

private:
    Ui::Password_Generator* ui;
};
#endif // PASSWORD_GENERATOR_H
