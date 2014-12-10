#include "torche.h"

using std::string;

Torche::Torche(string nom, QWidget* parent, int x, int y) : Decor(nom, parent, x, y)
{
    timer = new QTimer(parent);
    timer->setInterval(120);
    numeroImage = 1;
    setPixmap(QPixmap("Torches/Torche_1.png"));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(changerImage()));
    timer->start();
}

int Torche::getLargeur()const
{
    return this->width();
}
int Torche::getHauteur()const
{
    return this->height();
}

void Torche::changerImage() {
    switch(numeroImage) {
    case 1: setPixmap(QPixmap("Torches/Torche_1.png")); numeroImage++; break;
    case 2: setPixmap(QPixmap("Torches/Torche_2.png")); numeroImage++; break;
    case 3: setPixmap(QPixmap("Torches/Torche_3.png")); numeroImage = 1; break;
    }
}


