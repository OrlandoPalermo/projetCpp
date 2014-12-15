#include "decor.h"

using std::string;

Decor::Decor(string nom, QWidget *parent, int x, int y) : Objet(nom, parent, x, y)
{
}

void Decor::setHeight(int haut)
{
    setFixedHeight(haut);
}
void Decor::setWidth(int larg)
{
    setFixedWidth(larg);
}
