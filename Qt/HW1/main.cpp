//#include "mainwindow.h"
//#include "triangle.h"
#include "choise.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //Triangle t;
    //t.show();
    Choise c;
    c.show();
    return a.exec();
}
