#ifndef TORCHE_H
#define TORCHE_H

#include "decor.h"
#include <QTimer>

class Torche : public Decor
{
    Q_OBJECT
private:
    QTimer *timer;
    int numeroImage;
    void abstract() {}
public slots:
    void changerImage();

public:
    Torche(std::string, QWidget*, int x, int y);
    virtual int getLargeur()const;
    virtual int getHauteur()const;
};

#endif // TORCHE_H
