#pragma execution_character_set("utf-8")
#include "reSnake.h"
#include <QtWidgets/QApplication>
//#include <QTextCodec> // ����ͷ�ļ�

int main(int argc, char *argv[])
{
    system("chcp 65001");
    QApplication a(argc, argv);
    reSnake w;
    w.show();
    return a.exec();
}
