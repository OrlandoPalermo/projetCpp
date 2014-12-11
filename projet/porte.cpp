#include "porte.h"

using std::string;

Porte::Porte(string nom, QWidget* parent, int x, int y) : Decor(nom, parent, x, y)
{
    setFixedWidth(87);
    setFixedHeight(57);
}

int Porte::getLargeur()const
{
    return this->width();
}
int Porte::getHauteur()const
{
    return this->height();
}

void Porte::abstract() {}
