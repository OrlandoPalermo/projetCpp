#ifndef ECHELLE_H
#define ECHELLE_H

#include "decor.h"

class Echelle : public Decor
{
private:
    virtual void abstract();
public:
    Echelle(std::string, QWidget*, int x, int y);
    virtual int getLargeur()const;
    virtual int getHauteur()const;
};

#endif // ECHELLE_H
