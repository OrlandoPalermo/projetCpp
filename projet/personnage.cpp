#include "personnage.h"
int Personnage::nbPersonnage = 0;
Personnage::Personnage(int vDepl, QWidget *parent, int x, int y, int l, int h) : QLabel(parent)
{
    coordonnees = new QPoint(x, y);
    coordonneesMaj();
    this->l = l;
    this->h = h;

    id = new int;
    *id = nbPersonnage++;

    setVitesseDeplacement(vDepl);

    QObject::connect(this, SIGNAL(coordonneesChanged()), this, SLOT(coordonneesMaj()));

    this->setStyleSheet("background-color:skyblue;");
    this->setMinimumSize(this->l,this->h);
    this->setMaximumSize(this->l,this->h);

}

Personnage::~Personnage() {
    delete id;
}

/*Personnage::Personnage(const Personnage &p) : QLabel(p.parentWidget()) {
    vitesseDeplacement = p.vitesseDeplacement;
}*/

/*Personnage& Personnage::operator=(const Personnage& p) {
    if (&p != this) {
        vitesseDeplacement = p.vitesseDeplacement;
    }

    return *this;
}*/


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

int Personnage::getL() const {
    return this->l;
}

int Personnage::getH() const {
    return this->h;
}

int* Personnage::getId()const {
    return this->id;
}



