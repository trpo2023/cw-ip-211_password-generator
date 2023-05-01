#include "password_generator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Password_Generator w;
    w.show();
    return a.exec();
}
