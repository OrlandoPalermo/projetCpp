#include "personnage.h"

Personnage::Personnage(int vDepl, QWidget *parent, int x, int y) : QLabel(parent)
{
    coordonnees = new QPoint(x, y);
    coordonneesMaj();

    setVitesseDeplacement(vDepl);

    QObject::connect(this, SIGNAL(coordonneesChanged()), this, SLOT(coordonneesMaj()));
}

Personnage::~Personnage() {}

Personnage::Personnage(const Personnage &p) : QLabel(p.parentWidget()) {
    vitesseDeplacement = p.vitesseDeplacement;
}

Personnage& Personnage::operator=(const Personnage& p) {
    if (&p != this) {
        vitesseDeplacement = p.vitesseDeplacement;
    }

    return *this;
}

void Personnage::setVitesseDeplacement(int v) {
    if (v > 0)
        vitesseDeplacement = v;
}

int Personnage::getVitesseDeplacement() const {
    return vitesseDeplacement;
}

int Personnage::getX() const {
    return coordonnees->x();
}

int Personnage::getY() const {
    return coordonnees->y();
}

void Personnage::setX(int x) {
    coordonnees->setX(x);
    emit coordonneesChanged();
}

void Personnage::setY(int y) {
    coordonnees->setY(y);
    emit coordonneesChanged();
}

void Personnage::coordonneesMaj() {
    move(getX(), getY());
}
