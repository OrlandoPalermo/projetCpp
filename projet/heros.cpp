#include "heros.h"

Heros::Heros(int vitesse, QWidget* parent, int x, int y, bool repere, bool visible) : Personnage(vitesse, parent, x , y)
{
    //insertion de l'image du héros ici

    this->repere  = repere;
    this->visible = visible;
}

Heros::Heros(const Heros &h) : Personnage(h) {
    visible = h.visible;
    repere  = h.repere;
}

Heros::~Heros() {

}

Heros& Heros::operator=(const Heros& h) {
    if (&h != this) {
        visible = h.visible;
        repere = h.repere;
    }

    return *this;
}

void Heros::seDeplacer() {
    //A compléter
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
