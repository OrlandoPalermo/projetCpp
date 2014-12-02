#ifndef ENNEMI_H
#define ENNEMI_H

#include "personnage.h"

class Ennemi : public Personnage
{
private:
    int vision;
    bool orientationVision;
public:
    Ennemi(int, QWidget*, int=0, int=0, int=0, int=0, int=0, bool=false);
    ~Ennemi();
    //Ennemi(const Ennemi&);
    //Ennemi& operator=(const Ennemi&);
    void setVision(int);
    int getVision() const;
    bool isOrientationVision()const;
    void setOrientationVision();
    virtual void seDeplacer(int) = 0;
};

#endif // ENNEMI_H
