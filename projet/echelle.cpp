#include "echelle.h"

using std::string;

Echelle::Echelle(string nom, QWidget* parent, int x, int y) : Decor(nom, parent, x, y)
{
    //insertion de l'image de l'objet ici

    this->setFixedWidth(45);
    this->setFixedHeight(221);
}

void Echelle::abstract() {}
