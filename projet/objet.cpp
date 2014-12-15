#include "objet.h"
#include <iostream>
using std::string;

Objet::Objet(string nom, QWidget *parent, int x, int y) : QLabel(parent)
{
    this->nom = nom;
    coordonnees = new QPoint(x, y);

    coordonneesMaj();

    QObject::connect(this, SIGNAL(coordonneesChanged()), this, SLOT(coordonneesMaj()));
}

Objet::~Objet() {
    std::cout << "ok suppr !" << std::endl;
    delete coordonnees;
}

Objet::Objet(const Objet &o) : QLabel(o.parentWidget()) {
    nom = o.nom;
    coordonnees = new QPoint(o.coordonnees->x(), o.coordonnees->y());
}

Objet& Objet::operator=(const Objet& o) {
    if (&o != this) {
        delete coordonnees;
        nom = o.nom;
        coordonnees = new QPoint(o.coordonnees->x(), o.coordonnees->y());
    }

    return *this;
}

int Objet::getX() const {
    return coordonnees->x();
}

int Objet::getY() const {
    return coordonnees->y();
}

void Objet::setX(int x) {
    coordonnees->setX(x);
    emit coordonneesChanged();
}

void Objet::setY(int y) {
    coordonnees->setY(y);
    emit coordonneesChanged();
}

void Objet::coordonneesMaj() {
    move(getX(), getY());
}
