#ifndef TERRAIN_H
#define TERRAIN_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "vector"
#include "majordhomme.h"
#include "heros.h"
#include "porte.h"
#include "torche.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

#include "echelle.h"
#include "armoire.h"


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
    QLabel *labFond;
    bool activeKeyE;
    int coordDepartHerosX;
    int coordDepartHerosY;

    /*int tempsTimer1;
    int tempsTimer2;
    int tempsTimer3;*/

    int niveauEnCours;
public:
    Terrain();
    ~Terrain();

    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);
    //virtual void keyReleaseEvent(QKeyEvent *);
    void messageUtilisateur();

    void ajouterEnnemisRepere(Ennemi *);
    void init(int=0);
    void niveauSuivant();
    void rafraichirStage(int);
    //void retirerEnnemisRepere();
    bool miseEnPause();
    void bloquerLeJeux();
    void debloquerLeJeux();
    void retournerPageAccueil();

signals:
    void comportementDecor(Decor*);
    void toucheParEnnemi();


public slots:
    void testColission();
    void changeSensDeplacementEnnemis();
    void deplacementEnnemis();
    void comportementDecorAction(Decor*);
    void resetNiveau();
};

#endif // TERRAIN_H
