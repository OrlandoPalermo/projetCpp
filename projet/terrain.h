#ifndef TERRAIN_H
#define TERRAIN_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "vector"
#include "majordhomme.h"
#include "heros.h"
//#include "echelle.h"
//#include "armoire.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include "decor.h"

class Terrain : public QWidget
{
    Q_OBJECT
private:
    Heros *heros;
    std::vector<Ennemi*>* ennemis;
    std::vector<Ennemi*>* listeRepere;
    std::vector<Decor*>* decors;

    QTimer* timer;
    QTimer* sensTimerRonde;
    QTimer* dureeSensDeplacement;
    QTimer *animation;
    QPixmap *fond;
    QPixmap *mario;
    QLabel *labFond;
public:
    Terrain();
    ~Terrain();

    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);
    //virtual void keyReleaseEvent(QKeyEvent *);
    void messageUtilisateur();

    void ajouterEnnemisRepere(Ennemi *);
    //void retirerEnnemisRepere();

public slots:
    void testColission();
    void changeSensDeplacementEnnemis();
    void deplacementEnnemis();
};

#endif // TERRAIN_H
