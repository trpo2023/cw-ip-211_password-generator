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
    void on_number_of_pass_activated(int index);

    void on_length_of_pass_activated(int index);

    void on_numbers_stateChanged(int arg1);

    void on_lowercase_letters_stateChanged(int arg1);

    void on_capital_letters_stateChanged(int arg1);

    void on_special_characters_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::Password_Generator* ui;
};
#endif // PASSWORD_GENERATOR_H
