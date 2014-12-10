#include "mur.h"

using std::string;

Mur::Mur(string nom, QWidget *parent, int x, int y, int largeur, int hauteur) : Decor(nom, parent, x, y)
{
    setLargeur(largeur);
    setHauteur(hauteur);
}

void Mur::setLargeur(int lar) {
    if (lar >= 0)
        largeur = lar;
    else
        largeur = 0;
}

void Mur::setHauteur(int hau) {
    if (hau >= 0)
        hauteur = hau;
    else
        hauteur = 0;
}

int Mur::getHauteur() const {
    return hauteur;
}

int Mur::getLargeur() const {
    return largeur;
}
