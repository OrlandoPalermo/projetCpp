#ifndef DECOR_H
#define DECOR_H

#include "objet.h"
#include <QLabel>
#include <QPoint>

class Decor : public Objet
{
private:
    virtual void abstract() = 0;
public:
    Decor(std::string, QWidget *, int, int);

    void setHeight(int);
    void setWidth(int);

    virtual int getLargeur()const = 0;
    virtual int getHauteur()const = 0;

};

#endif // DECOR_H
