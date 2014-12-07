#include "heros.h"

Heros::Heros(int vitesse, QWidget* parent, int x, int y, int l, int h, bool axeX, bool axeY, bool repere, bool visible) : Personnage(vitesse, parent, x , y , l , h )
{
    //insertion de l'image du héros ici

    this->repere  = repere;
    this->visible = visible;
    this->axeX = axeX;
    this->axeY = axeY;
    this->setFixedSize(l,h);
    setPixmap(QPixmap("Marios/mario_inactif.png"));
}

/*Heros::Heros(const Heros &h) : Personnage(h) {
    visible = h.visible;
    repere  = h.repere;
}*/

Heros::~Heros() {

}

/*Heros& Heros::operator=(const Heros& h) {
    if (&h != this) {
        visible = h.visible;
        repere = h.repere;
    }

    return *this;
}*/

void Heros::seDeplacer(int direction) {
    switch(direction)
    {
    case 1 : if ( this->isAxeX() == true )
        {
        Personnage::setX(Personnage::getX() + Personnage::getVitesseDeplacement()); // deplacement du heros à droite
        this->animer();
        }
        break;
    case 2 : if ( this->isAxeX() == true )
        {
        Personnage::setX(Personnage::getX() - Personnage::getVitesseDeplacement()); // deplacement du heros à gauche
        }
        break;
    case 3 : if ( this->isAxeY() == true )
        {
        Personnage::setY(Personnage::getY() - Personnage::getVitesseDeplacement()); // deplacement vers le haut
        }
        break;
    case 4 : if ( this->isAxeY() == true )
        {
        Personnage::setY(Personnage::getY() + Personnage::getVitesseDeplacement()); // depalcement vers le bas
        }
        break;
    }
}

void Heros::seCacher() {
    visible = false;
}

bool Heros::isRepere() const {
    return repere;
}

bool Heros::isVisible() const {
    return visible;
}

void Heros::setVisibleClasse(bool v) {
    visible = v;
}

void Heros::setRepere()
{
    repere = true;
}


bool Heros::isAxeX() const {
    return this->axeX;
}
bool Heros::isAxeY() const {
    return this->axeY;
}

void Heros::setAxeX()
{
    this->axeX = !axeX;
}
void Heros::setAxeY(bool axe)
{
    this->axeY = axe;
}

void Heros::remplacerSprite(int numPhoto)
{
    switch(numPhoto)
    {
        case 1 : this->setPixmap(*(new QPixmap("Marios/mario_droite.png"))); break;
        case 2 : this->setPixmap(*(new QPixmap("Marios/mario_gauche.png"))); break;
    }
}

void Heros::animer()
{
    if(this->getNumImage()==0)
    {
        this->setNumImage(1);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==1)
    {
        this->setNumImage(2);
        this->remplacerSprite(this->getNumImage());
    }
    else
    {
        this->setNumImage(1);
        this->remplacerSprite(this->getNumImage());
    }

}

/*Appel de cette méthode pour arrêter Mario lorsque l'utilisateur relâche la touche*/
void Heros::spriteReset()
{
    this->setNumImage(0);
    this->setPixmap(*(new QPixmap("Marios/mario_inactif.png")));
}
