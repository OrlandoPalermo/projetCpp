#ifndef TERRAIN_H
#define TERRAIN_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "vector"
#include "majordhomme.h"
#include "heros.h"
#include "echelle.h"
#include "armoire.h"

class Terrain : public QWidget
{
private:
    Heros *heros;
    std::vector<Ennemi*> ennemis;
    std::vector<Decor*> decors;
public:
    Terrain();
};

#endif // TERRAIN_H
