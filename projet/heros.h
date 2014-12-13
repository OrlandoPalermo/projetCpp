#ifndef HEROS_H
#define HEROS_H

#include "personnage.h"

class Heros : public Personnage
{
private:
    bool repere, visible;
    bool axeX;
    bool axeY;
public:
    Heros(int, QWidget*, int=0, int=0, int=0, int=0, bool=true, bool=false, bool=false, bool=true);
    ~Heros();
    Heros(const Heros&);
    //Heros& operator=(const Heros&);
    void seCacher();

    void seDeplacer(int);


    bool isVisible() const;
    bool isRepere() const;
    void setVisibleClasse(bool);
    void setRepere();

    bool isAxeX() const;
    bool isAxeY() const;

    void setAxeX(bool);
    void setAxeY(bool);

    virtual void remplacerSprite(int);
    void animer();
    void spriteReset();

};

#endif // HEROS_H
