#ifndef DECOR_H
#define DECOR_H

#include "objet.h"
#include <QLabel>
#include <QPoint>

class Decor : public Objet
{
private:
    virtual void abstract() = 0;
    QPoint *coordonnees;
public:
    Decor(std::string, QWidget *, int, int);
    ~Decor();

    int getX();
    int getY();

    virtual int getLargeur()const = 0;
    virtual int getHauteur()const = 0;

};

#endif // DECOR_H
