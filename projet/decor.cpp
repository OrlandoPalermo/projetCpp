#include "decor.h"

using std::string;

Decor::Decor(QWidget *parent, int xBasGauche, int xBasDroite, int yHautGauche, int yBasGauche) : QLabel(parent)
{
    pixelsMontee = xBasGauche - yHautGauche;

    coordonnees = new QPoint;
    coordonnees->setX(xBasGauche);
    //On se sert de la coordonnée de l'objet dans la map pour placer le QLabel invisible pour faire un test de collision

    coordonnees->setY(yHautGauche);
    this->move(*coordonnees);
    this->setFixedWidth(xBasDroite-xBasGauche);
    this->setFixedHeight(yBasGauche-yHautGauche);
   // this->setStyleSheet("QLabel {background-color : red;}");
   // this->setText("APPARAIT!");
}

Decor::~Decor()
{
    delete coordonnees;
}

int Decor::getX()
{
    return coordonnees->x();
}

int Decor::getY()
{
    return coordonnees->y();
}
