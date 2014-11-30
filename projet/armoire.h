#ifndef ARMOIRE_H
#define ARMOIRE_H

#include "decor.h"

class Armoire : public Decor
{
private:
    void abstract();
public:
    Armoire(std::string, QWidget*, int=0, int=0);
};

#endif // ARMOIRE_H
