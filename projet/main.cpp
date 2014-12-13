#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "terrain.h"

#include "menu.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    /*Terrain terrain;
    terrain.show();*/

    Menu m;
    m.show();

    return a.exec();
}
