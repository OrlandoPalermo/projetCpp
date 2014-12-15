#include "personnage.h"
int Personnage::nbPersonnage = 0;
Personnage::Personnage(int vDepl, QWidget *parent, int x, int y, int l, int h) : QLabel(parent)
{
    coordonnees = new QPoint(x, y);
    coordonneesMaj();
    this->l = l;
    this->h = h;
    numImage = 0;
    id = new int;
    *id = nbPersonnage++;

    setVitesseDeplacement(vDepl);

    QObject::connect(this, SIGNAL(coordonneesChanged()), this, SLOT(coordonneesMaj()));


}

Personnage::~Personnage() {
    delete id;
    delete coordonnees;
}

Personnage::Personnage(const Personnage &p) : QLabel(p.parentWidget()) {
    vitesseDeplacement = p.vitesseDeplacement;
    coordonnees = new QPoint(p.getX(),p.getY());
    l = p.getL();
    h = p.getH();
    numImage = 0;
    id = new int;
    *id = *(p.getId());
}

Personnage& Personnage::operator=(const Personnage& p) {
    if (&p != this) {
        vitesseDeplacement = p.vitesseDeplacement;
        coordonnees = new QPoint(p.getX(),p.getY());
        l = p.getL();
        h = p.getH();
        numImage = 0;
        id = new int;
        *id = *(p.getId());
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

int Personnage::getL() const {
    return this->l;
}

int Personnage::getH() const {
    return this->h;
}

int* Personnage::getId()const {
    return this->id;
}

int Personnage::getNumImage()const
{
    return numImage;
}

void Personnage::setNumImage(int num)
{
    numImage = num;
}


