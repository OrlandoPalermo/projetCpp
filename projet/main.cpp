#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "terrain.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);*/

    Terrain terrain;
    terrain.show();

    return a.exec();
}
