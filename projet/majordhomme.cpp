#include "majordhomme.h"

Majordhomme::Majordhomme(int vitesse, QWidget* parent, int x, int y, int l, int h, int vision, bool orientationVision) : Ennemi(vitesse, parent, x, y, l, h, vision, orientationVision)
{
    //insertion de l'image du majordhomme ici

}

void Majordhomme::seDeplacer(int direction) {
    switch(direction)
    {
    case 1 :
        Personnage::setX(Personnage::getX() + Personnage::getVitesseDeplacement()); // deplacement du heros à droite

        break;
    case 2 :
        Personnage::setX(Personnage::getX() - Personnage::getVitesseDeplacement()); // deplacement du heros à gauche

        break;
    }
}
