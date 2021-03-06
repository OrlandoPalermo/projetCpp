#ifndef MAJORDHOMME_H
#define MAJORDHOMME_H

#include "ennemi.h"
#include "QLabel"

class Majordhomme : public Ennemi
{
private:

public:
    //Vision de 50 pixel par défaut
    Majordhomme(int,  QWidget*, int=0, int=0,int=0,int=0,int=50,bool=false,int=0,int=0);
    Majordhomme(const Majordhomme&);
    void seDeplacer(int);
    virtual void remplacerSprite(int);
    void animer();
};

#endif // MAJORDHOMME_H
