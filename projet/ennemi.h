#ifndef ENNEMI_H
#define ENNEMI_H

#include "personnage.h"

class Ennemi : public Personnage
{
private:
    int vision;
public:
    Ennemi(int, QWidget*, int, int, int);
    ~Ennemi();
    Ennemi(const Ennemi&);
    Ennemi& operator=(const Ennemi&);
    void setVision(int);
    int getVision() const;
    virtual void seDeplacer() = 0;
};

#endif // ENNEMI_H
