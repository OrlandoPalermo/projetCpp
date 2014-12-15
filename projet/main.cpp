#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "menu.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu m;
    m.show();

    return a.exec();
}
