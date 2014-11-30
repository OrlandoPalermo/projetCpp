#ifndef HEROS_H
#define HEROS_H

#include "personnage.h"

class Heros : public Personnage
{
private:
    bool repere, visible;
public:
    Heros(int, QWidget*, int=0, int=0, bool=false, bool=true);
    ~Heros();
    Heros(const Heros&);
    Heros& operator=(const Heros&);
    void seCacher();
    virtual void seDeplacer();
    bool isVisible() const;
    bool isRepere() const;

};

#endif // HEROS_H
