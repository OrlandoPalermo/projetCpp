#include "decor.h"

using std::string;

Decor::Decor(string nom, QWidget *parent, int x, int y) : Objet(nom, parent, x, y)
{
    coordonnees = new QPoint;
    coordonnees->setX(x);
    //On se sert de la coordonnée de l'objet dans la map pour placer le QLabel invisible pour faire un test de collision

    coordonnees->setY(y);
    this->move(*coordonnees);

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

void Decor::setHeight(int haut)
{
    setFixedHeight(haut);
}
void Decor::setWidth(int larg)
{
    setFixedWidth(larg);
}
