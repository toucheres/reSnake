#include "reSnake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    system("chcp 65001");
    QApplication a(argc, argv);
    reSnake w;
    w.show();
    return a.exec();
}
