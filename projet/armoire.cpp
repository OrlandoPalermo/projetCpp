#include "armoire.h"

using std::string;

Armoire::Armoire(string nom, QWidget* parent, int x, int y) : Decor(nom, parent, x, y)
{
    this->setFixedWidth(170);
    this->setFixedHeight(255);
}

void Armoire::abstract() {}
