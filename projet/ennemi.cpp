#include "ennemi.h"

Ennemi::Ennemi(int vitesse, QWidget* parent, int x, int y, int l, int h, int vision, bool orientationVision,int posXMin,int posXMax) : Personnage(vitesse, parent, x, y, l, h)
{
    setVision(vision);
    this->orientationVision = orientationVision;

    this->posXMin = posXMin;
    this->posXMax = posXMax;
}

Ennemi::~Ennemi() {}

Ennemi::Ennemi(const Ennemi &e) : Personnage(e) {
    vision = e.isVisible();
    orientationVision = e.isOrientationVision();
    posXMin = e.getPosXMin();
    posXMax = e.getPosXMax();
}

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

void Ennemi::setOrientationVision(bool v)
{
    this->orientationVision = v;
}

bool Ennemi::isOrientationVision()const
{
    return this->orientationVision;
}

int Ennemi::getPosXMin()const
{
    return posXMin;
}
int Ennemi::getPosXMax()const
{
    return posXMax;
}
void Ennemi::setPosXMin(int p)
{
    posXMin = p;
}

void Ennemi::setPosXMax(int p)
{
    posXMax = p;
}
