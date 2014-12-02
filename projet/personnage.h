#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QPixmap>

class Personnage : public QLabel
{
    Q_OBJECT

private:
    int vitesseDeplacement;
    QPoint *coordonnees;
    int l;
    int h;
    int* id;

    static int nbPersonnage;

public:
    //x et y valent 0 au départ
    Personnage(int, QWidget*, int=0, int=0, int=0, int=0);
    ~Personnage();
    //Personnage(const Personnage&);
    //Personnage& operator=(const Personnage&);
    virtual void seDeplacer(int) = 0; // mettre un parametre chiffre pour le sens si heros keypressed si ennemis orientationVision
    void setVitesseDeplacement(int);
    int getVitesseDeplacement() const;
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);

    int getL() const;
    int getH() const;

    int* getId()const;


    static int getNbPersonnage(){return nbPersonnage;}


signals:
    void coordonneesChanged();
public slots:
    void coordonneesMaj();
};

#endif // PERSONNAGE_H
