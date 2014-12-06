#ifndef DECOR_H
#define DECOR_H

//#include <objet.h>
#include <QLabel>
#include <QPoint>
class Decor : public QLabel
{
private:
    //virtual void abstract() = 0;
    int pixelsMontee;
    QPoint *coordonnees;
public:
    Decor(QWidget *, int, int, int, int );
    ~Decor();

    int getX();
    int getY();

};

#endif // DECOR_H
