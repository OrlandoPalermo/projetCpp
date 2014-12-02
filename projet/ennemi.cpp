#include "ennemi.h"

Ennemi::Ennemi(int vitesse, QWidget* parent, int x, int y, int l, int h, int vision, bool orientationVision) : Personnage(vitesse, parent, x, y, l, h)
{
    setVision(vision);
    this->orientationVision = orientationVision;
}

Ennemi::~Ennemi() {}

/*Ennemi::Ennemi(const Ennemi &e) : Personnage(e) {
    vision = e.vision;
}*/

/*Ennemi& Ennemi::operator=(const Ennemi& e) {
    if (&e != this) {
        vision = e.vision;
    }
    return *this;
}*/

void Ennemi::setVision(int vi) {
    if (vi >= 0)
        vision = vi;
}

int Ennemi::getVision() const {
    return vision;
}

void Ennemi::setOrientationVision()
{
    this->orientationVision = !orientationVision;
}
bool Ennemi::isOrientationVision()const
{
    return this->orientationVision;
}
