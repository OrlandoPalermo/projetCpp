#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "terrain.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Terrain terrain;
    terrain.show();

    return a.exec();
}
