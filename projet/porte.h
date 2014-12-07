#ifndef PORTE_H
#define PORTE_H

#include "decor.h"

class Porte : public Decor
{
public:
    Porte(std::string, QWidget*, int, int);
    virtual int getLargeur()const;
    virtual int getHauteur()const;
    void abstract();
};

#endif // PORTE_H
