// main.cpp
#include <QApplication>
#include "bmiwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BMIWidget w;
    w.show();
    return a.exec();
}
