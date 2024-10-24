#include "reSnake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    reSnake w;
    w.show();
    return a.exec();
}
