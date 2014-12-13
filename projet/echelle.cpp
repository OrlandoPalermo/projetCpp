#include "echelle.h"

using std::string;

Echelle::Echelle(string nom, QWidget* parent, int x, int y) : Decor(nom, parent, x, y)
{


    this->setFixedWidth(21);// base a 45
    this->setFixedHeight(121);// base a 139
}

int Echelle::getLargeur()const
{
    return this->width();
}
int Echelle::getHauteur()const
{
    return this->height();
}

void Echelle::abstract() {}
