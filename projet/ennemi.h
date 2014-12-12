#ifndef ENNEMI_H
#define ENNEMI_H

#include "personnage.h"

class Ennemi : public Personnage
{
private:
    int vision;
    bool orientationVision;

    // test
    int posXMin;
    int posXMax;
    // fin test
public:
    Ennemi(int, QWidget*, int=0, int=0, int=0, int=0, int=0, bool=false,int=0,int=0);
    ~Ennemi();
    //Ennemi(const Ennemi&);
    //Ennemi& operator=(const Ennemi&);
    void setVision(int);
    virtual void remplacerSprite(int)= 0;
    int getVision() const;
    bool isOrientationVision()const;
    //void setOrientationVision();
    void setOrientationVision(bool);
    virtual void seDeplacer(int) = 0;

    int getPosXMin()const;
    int getPosXMax()const;
    void setPosXMin(int);
    void setPosXMax(int);
};

#endif // ENNEMI_H
