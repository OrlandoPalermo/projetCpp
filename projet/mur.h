#ifndef MUR_H
#define MUR_H

#include "decor.h"

class Mur : public Decor
{
private:
    int largeur;
    int hauteur;
    virtual void abstract();
public:
    Mur(std::string, QWidget *, int, int, int, int);
    void setHauteur(int);
    void setLargeur(int);
    int getHauteur() const;
    int getLargeur() const;
};

#endif // MUR_H
