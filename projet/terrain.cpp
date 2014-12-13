#include "terrain.h"
#include <QApplication>
#include <vector>
#include <typeinfo>
#include <sstream>
#include "mur.h"
#include "menu.h"

using namespace std;

Terrain::Terrain() : QWidget()
{

    //Première initialisation
    this->setUpdatesEnabled(true);
    labFond = new QLabel(this); //QLabel représentant le contenur de l'image de fond du stage
    this->setFixedSize(960,720);
    this->setWindowTitle("Infiltrate Love");
    //this->setWindowIcon(QIcon("D:/Users/Alexandre/Pictures/iconJeu.png"));


    heros = new Heros(5,this,200,575,23,42,true,false,false,true);

    ennemis = new vector<Ennemi*>; // liste d'ennemis
    decors = new vector<Decor*>; //liste de décors

    listeRepere = new vector<Ennemi*>; // liste des ennemis ayant repere le heros

    niveauEnCours = 0;
    init(); // implemente le niveau

    //Initialisation et configuration des timers
    //-------------------------------------------

    timer = new QTimer(this); // timer de colission
    timer->setInterval(50); // permet de gérer l'intervalle entre chaque répétitions



    dureeSensDeplacement = new QTimer(this); //  timer pour la ronde des ennemis
    dureeSensDeplacement->setInterval(50);

    //Liaisons signaux et slots
    //--------------------------

    QObject::connect( timer,                SIGNAL( timeout() ),                this, SLOT(  testCollision() ) ) ; // test les collisions faites par les ennemis
    QObject::connect( dureeSensDeplacement, SIGNAL( timeout() ),                this, SLOT(  deplacementEnnemis() ) ) ;
    QObject::connect(this,                  SIGNAL(comportementDecor(Decor*)),  this, SLOT(comportementDecorAction(Decor*)));
    QObject::connect(this,                  SIGNAL(toucheParEnnemi()),          this, SLOT(resetNiveau()));

    //Démarrage des timers
    //---------------------

    timer->start();

    dureeSensDeplacement->start();

    //Configuration des boutons
    //--------------------------
    activeKeyE = false;



}
Terrain::~Terrain()
{
    delete heros;

    for (unsigned i(0); i < ennemis->size(); i++)
        delete (*ennemis)[i];

    for (unsigned i(0); i < decors->size(); i++)
        delete (*decors)[i];

    delete ennemis;
    delete listeRepere;
    delete decors;
}

void Terrain::testCollision()
{
    int sens = 0;
    bool dejaDedans = false;
    for (unsigned i = 0 ; i < ennemis->size() ; i++ )
    {

        if ((*ennemis)[i]->isOrientationVision() == false) // orientation == false => gauche
        {
            sens = -1; // l'ennemis regarde vers la gauche
        }
        else
        {
            sens = 1; // l'ennemis regarde vers la droite
        }
        if (heros->isVisible()) {
            if (
               ( (heros->getX() + heros->getL() ) < (*ennemis)[i]->getX() + (sens * (*ennemis)[i]->getVision() ) ) || // si le heros se trouve tout à gauche de l'ennemis
               (  heros->getX() > ( (*ennemis)[i]->getX() + (*ennemis)[i]->getL() + (sens * (*ennemis)[i]->getVision() ) ) ) || // si le heros se trouve tout à droite de l'ennemis
               ( ( heros->getY() + heros->getH() ) < (*ennemis)[i]->getY() ) || // si le heros se trouve au-dessus de l'ennemis
               (  heros->getY() > ( (*ennemis)[i]->getY() + (*ennemis)[i]->getH() ) ) // si le heros se trouve en-dessous de l'ennemis
               )
            {

            }
            else
            {
                //-----------------------
                //-------ATTENTION------- Ici je considère comme être touché par un ennemi !!!
                //-----------------------

                emit toucheParEnnemi();
                heros->setRepere();
                //listeRepere->push_back((*ennemis)[i]); // rajout d'un ennemis parmis ceux ayant repere le heros
                for ( unsigned j = 0 ; j < listeRepere->size() ; j++ )
                {
                    if ( (*(*listeRepere)[j]->getId()) == (*(*ennemis)[i]->getId()) ) // teste les ennemis des 2 listes par rapport à leur id
                    {
                        dejaDedans = true; // si l'ennemis fait déjà partie des ennemis ayant repéré le heros
                    }
                }
                if ( dejaDedans == false ) // si pas encore dedans
                    ajouterEnnemisRepere((*ennemis)[i]);  // on passe par la méthode qui le rajoute
            }
        }





    }


    if ( heros->isRepere() == true )
    {
        //messageUtilisateur(); // message déclenché si le heros est dectecté
    }
}




void Terrain::keyPressEvent(QKeyEvent *event)
{

    int choix  = 0;
    bool retourPageAccueil = false;

    switch(event->key())
    {
    case Qt::Key_Escape:
        bloquerLeJeux();
        retourPageAccueil = miseEnPause();
        if ( retourPageAccueil )
        {
            retournerPageAccueil();
        }
        else
        {
            debloquerLeJeux();
        }
        break;
    case Qt::Key_E:
        if (activeKeyE) {
            if (heros->isVisible()) {
                heros->setVisible(false);
                heros->setVisibleClasse(false);
            } else {
                heros->setVisible(true);
                heros->setVisibleClasse(true);
            }
        }
        break;
    case Qt::Key_Right :
        choix = 1;

        break;
    case Qt::Key_Left :
        choix = 2;

        break;
    case Qt::Key_Down :
        choix= 4;

        break;
    case Qt::Key_Up :
        choix = 3;

        break;


    }

    if ( choix >= 1 && choix <= 4 )
    {
        if ( choix == 1 || choix == 2)
        {
                for ( unsigned i = 0 ; i < decors->size() ; i++ )
                        {
                            if ((*decors)[i] != dynamic_cast<Mur*>((*decors)[i]))
                            {
                                if (
                                    ( ( heros->getX() + heros->getL() ) < (*decors)[i]->getX() ) || // si le heros se trouve tout à gauche de l'objet
                                    (  heros->getX() > ( (*decors)[i]->getX() + (*decors)[i]->getLargeur() ) ) || // si le heros se trouve tout à droite de l'objet
                                    ( ( heros->getY() + heros->getH() ) < (*decors)[i]->getY() ) || // si le heros se trouve au-dessus de l'objet
                                    (  heros->getY() > ( (*decors)[i]->getY() + (*decors)[i]->getHauteur() ) ) // si le heros se trouve en-dessous de l'objet
                                    )
                                {
                                    //Remise à zéro de tous les paramètres des comportements
                                    heros->setAxeY(false);
                                    heros->setVisible(true);
                                    activeKeyE = false;
                                }
                                else
                                {
                                    emit comportementDecor((*decors)[i]);

                                    //On casse la boucle car on ne peut rentrer en collision qu'avec un seul décort à la fois
                                    break;
                                }

                            }
                             else
                            {
                                if ( choix == 1)
                                {
                                if (
                                    ( ( heros->getX() + heros->getL() ) < (*decors)[i]->getX() - (heros->Personnage::getVitesseDeplacement()+1) ) || // si le heros se trouve tout à gauche de l'objet ps:choix du getVitesseDeplacement + 1 car ainsi un coup d'avance sur le deplacement du personnage
                                    (  heros->getX() > ( (*decors)[i]->getX() + (*decors)[i]->getLargeur() ) ) || // si le heros se trouve tout à droite de l'objet
                                    ( ( heros->getY() + heros->getH() ) < (*decors)[i]->getY() ) || // si le heros se trouve au-dessus de l'objet
                                    (  heros->getY() > ( (*decors)[i]->getY() + (*decors)[i]->getHauteur() ) ) // si le heros se trouve en-dessous de l'objet
                                    )
                                {
                                    //Remise à zéro de tous les paramètres des comportements
                                    heros->setAxeY(false);
                                    heros->setVisible(true);
                                    activeKeyE = false;
                                }
                                else
                                {
                                    //emit comportementDecor((*decors)[i]);
                                    choix = 0;
                                    //On casse la boucle car on ne peut rentrer en collision qu'avec un seul décort à la fois
                                    break;
                                }
                                }
                                else if ( choix == 2)
                                {
                                    if (
                                        ( ( heros->getX() + heros->getL() ) < (*decors)[i]->getX() ) || // si le heros se trouve tout à gauche de l'objet
                                        (  heros->getX() > ( (*decors)[i]->getX() + (*decors)[i]->getLargeur() + (heros->Personnage::getVitesseDeplacement()+1) ) ) || // si le heros se trouve tout à droite de l'objet ps:choix du getVitesseDeplacement + 1 car ainsi un coup d'avance sur le deplacement du personnage
                                        ( ( heros->getY() + heros->getH() ) < (*decors)[i]->getY() ) || // si le heros se trouve au-dessus de l'objet
                                        (  heros->getY() > ( (*decors)[i]->getY() + (*decors)[i]->getHauteur() ) ) // si le heros se trouve en-dessous de l'objet
                                        )
                                    {
                                        //Remise à zéro de tous les paramètres des comportements
                                        heros->setAxeY(false);
                                        heros->setVisible(true);
                                        activeKeyE = false;
                                    }
                                    else
                                    {
                                        //emit comportementDecor((*decors)[i]);
                                        choix = 0;
                                        //On casse la boucle car on ne peut rentrer en collision qu'avec un seul décort à la fois
                                        break;
                                    }
                                }
                            }
                        }

        }
        else if ( choix == 4 )
        {
            for ( unsigned i = 0 ; i < decors->size() ; i++ )
                    {
                        if (
                           ( ( heros->getX() + heros->getL() ) < (*decors)[i]->getX() ) || // si le heros se trouve tout à gauche de l'objet
                           (  heros->getX() > ( (*decors)[i]->getX() + (*decors)[i]->getLargeur() ) ) || // si le heros se trouve tout à droite de l'objet
                           ( ( heros->getY() + heros->getH() ) < (*decors)[i]->getY() - (2 * heros->Personnage::getVitesseDeplacement() ) ) || // si le heros se trouve au-dessus de l'objet le 2 * getVitesse est la pour la meme raison que celui du dessus
                           (  heros->getY() > ( (*decors)[i]->getY() + (*decors)[i]->getHauteur()  ) ) // si le heros se trouve en-dessous de l'objet
                           )
                        {
                            //Remise à zéro de tous les paramètres des comportements
                            heros->setAxeY(false);
                            heros->setVisible(true);
                            activeKeyE = false;
                        }
                        else
                        {
                            emit comportementDecor((*decors)[i]);

                            //On casse la boucle car on ne peut rentrer en collision qu'avec un seul décort à la fois
                            break;
                        }
                    }
        }
        else if ( choix == 3 )
        {
            for ( unsigned i = 0 ; i < decors->size() ; i++ )
                    {
                        if (
                           ( ( heros->getX() + heros->getL() ) < (*decors)[i]->getX() ) || // si le heros se trouve tout à gauche de l'objet
                           (  heros->getX() > ( (*decors)[i]->getX() + (*decors)[i]->getLargeur() ) ) || // si le heros se trouve tout à droite de l'objet
                           ( ( heros->getY() + heros->getH() ) < (*decors)[i]->getY() ) || // si le heros se trouve au-dessus de l'objet
                           (  heros->getY() > ( (*decors)[i]->getY() + (*decors)[i]->getHauteur() + (2 * heros->Personnage::getVitesseDeplacement() ) ) ) // si le heros se trouve en-dessous de l'objet le 2 * getVitesse est la pour la meme raison que celui du dessus
                           )
                        {
                            //Remise à zéro de tous les paramètres des comportements
                            heros->setAxeY(false);
                            heros->setVisible(true);
                            activeKeyE = false;
                        }
                        else
                        {
                            emit comportementDecor((*decors)[i]);

                            //On casse la boucle car on ne peut rentrer en collision qu'avec un seul décort à la fois
                            break;
                        }
                    }
        }

        if ( choix >= 1 && choix <= 4 )
            heros->seDeplacer(choix);

        debloquerLeJeux(); // permet de debloquer le jeux ( apres le second retour au menu )
    }



}

void Terrain::messageUtilisateur()
{
    QMessageBox::information ( this , "Ca marche ca touche " , "Il y a collision !");
}


void Terrain::deplacementEnnemis()
{
    int dep = 0;
    for (unsigned i = 0 ; i < ennemis->size() ; i++ )
    {
        if ( (*ennemis)[i]->Ennemi::isOrientationVision() == false ) // ennemis regardant à gauche = false
        {
            dep = 2;
        }
        else
        {
            dep = 1;
        }
        (*ennemis)[i]->seDeplacer(dep);
    }
}



void Terrain::ajouterEnnemisRepere(Ennemi* e)
{
    listeRepere->push_back(e);
    //messageUtilisateur(); // petit test pour voir si il etait ajoute plusieurs fois et c'est ok
    // ps : pas faire attention au message
}

void Terrain::keyReleaseEvent(QKeyEvent *event)
{
    //Utilisation de event->ignore() pour éviter que les sprites ne se bloquent si l'utilisateur reste appuyé

    if(event->isAutoRepeat())
    {

        event->ignore();
    }

    //Si l'utilisateur relâche le KeyEvent pour de bon alors Mario revient à son sprite statique de départ

    else
    {

           if(event->key()==Qt::Key_Left)
           {
             heros->setNumImage(3);
             heros->remplacerSprite(heros->getNumImage());
           }

           else
           {
           heros->spriteReset();
           }
    }

          //heros->spriteReset();


}

/*void Terrain::retirerEnnemisRepere()
{

}*/

void Terrain::comportementDecorAction(Decor *decor) {
    if (decor == dynamic_cast<Echelle*>(decor)) {
        heros->setAxeY(true);
    } else if (decor == dynamic_cast<Armoire*>(decor)) {
        activeKeyE = true;
    } else if (decor == dynamic_cast<Porte*>(decor)) {
        niveauSuivant();
    }
}

void Terrain::init(int numeroNiveau) {

    switch(numeroNiveau) {
    case 0:
        coordDepartHerosX = 200;
        coordDepartHerosY = 575;

        labFond->setPixmap(QPixmap("Terrain_1Ref.png"));

        ennemis->push_back(new Majordhomme(2,this,700,400,51,50,10,false,610,750));
        ennemis->push_back(new Majordhomme(2,this,870,565,51,50,10,false,770,920));


        decors->push_back(new Armoire("Armoire", this, 672, 530));
        decors->push_back(new Echelle("Echelle", this, 778, 453));//anciennement 772-473
        decors->push_back(new Porte("Porte", this, 870, 396));

        break;
    case 1:
        rafraichirStage(numeroNiveau);
        break;
    default:
        init();
        break;
    }
}

void Terrain::niveauSuivant() {
    init(++niveauEnCours);
}

void Terrain::resetNiveau() {
    heros->setX(coordDepartHerosX);
    heros->setY(coordDepartHerosY);
    heros->setAxeY(false);
}

void Terrain::rafraichirStage(int numStage)
{
    switch(numStage)
    {
    case 1 :
        coordDepartHerosX = 50; coordDepartHerosY = 420; // Remise à zéro des coordonnées de départ du héros
        heros->setX(50);  heros->setY(425);// Placement du héros dans le deuxième stage

        labFond->setPixmap(QPixmap("Terrain_2Ref.png")); // Changement du fond de l'image du stage

        (*ennemis)[0]->setX(650);  (*ennemis)[0]->setY(415); //Placement de l'ennemi bas gauche
        (*ennemis)[1]->setX(900);  (*ennemis)[1]->setY(635); //Placement de l'ennemi bas droite

        (*ennemis)[0]->setPosXMin(650);  (*ennemis)[0]->setPosXMax(750); // modifie les rondes
        (*ennemis)[1]->setPosXMin(800);  (*ennemis)[1]->setPosXMax(920); // modifie les rondes


        ennemis->push_back(new Majordhomme(2,this,220,635,51,50,10,false,120,270)); // Création d'un nouvel ennemi ajouté sur la map
        (*ennemis)[2]->setVisible(true);
        ennemis->push_back(new Majordhomme(2,this,653,170,51,50,10,false,580,680));// Création d'un nouvel ennemi ajouté sur la map
        (*ennemis)[3]->setVisible(true);

        //(*ennemis)[2] -> modifier ses rondes
        //(*ennemis)[3] -> modifier ses rondes

        //Nettoyage des vecteurs contenant les décors
        for (unsigned i(0); i < decors->size(); i++)
            delete (*decors)[i];
        decors->clear();


        /*Création des nouveaux décors */
        decors->push_back(new Echelle("Echelle", this, 200, 470));
        (*decors)[0]->setVisible(true); (*decors)[0]->Decor::setHeight(170);(*decors)[0]->Decor::setWidth(32);

        decors->push_back(new Echelle("Echelle", this, 853, 470));
        (*decors)[1]->setVisible(true); (*decors)[1]->Decor::setHeight(170);  (*decors)[1]->Decor::setWidth(32);

        decors->push_back(new Armoire("Armoire", this, 459, 592));
        (*decors)[2]->setVisible(true);

        decors->push_back(new Armoire("Armoire", this, 722, 131));//anciennement 772-473
        (*decors)[3]->setVisible(true);

        decors->push_back(new Echelle("Echelle", this, 576, 225));//anciennement 772-473
        (*decors)[4]->setVisible(true);  (*decors)[4]->Decor::setHeight(200);        (*decors)[4]->Decor::setWidth(32);

        decors->push_back(new Porte("Porte", this, 101, 161));
        (*decors)[5]->setVisible(true);

        decors->push_back(new Torche("Torche", this, 158, 370));
        (*decors)[6]->setVisible(true);

        decors->push_back(new Torche("Torche", this, 225, 370));
        (*decors)[7]->setVisible(true);

        decors->push_back(new Torche("Torche", this, 511, 370));
        (*decors)[8]->setVisible(true);

        decors->push_back(new Torche("Torche", this, 627, 588));
        (*decors)[9]->setVisible(true);

        decors->push_back(new Torche("Torche", this, 190, 125));
        (*decors)[10]->setVisible(true);

        decors->push_back(new Torche("Torche", this, 45, 125));
        (*decors)[11]->setVisible(true);

        decors->push_back(new Mur("Mur",this,450,425,80,100));
        (*decors)[12]->setVisible(true);

        break;


    }
}

bool Terrain::miseEnPause()
{
    int reponseJoueur = QMessageBox::question(this, "Pause", "Voulez-vous quitter le jeu  ?", QMessageBox::Yes | QMessageBox::No);

    if ( reponseJoueur == QMessageBox::Yes )
    {
        reponseJoueur = true;
    }
    else
    {
        reponseJoueur = false;
    }

    return reponseJoueur;

}

void Terrain::bloquerLeJeux()
{
    // bloque tous les timers ( car obligation pour la pause )
    timer->blockSignals(true);

    dureeSensDeplacement->blockSignals(true);

}

void Terrain::debloquerLeJeux()
{
    // debloque tous les timers
    timer->blockSignals(false);

    dureeSensDeplacement->blockSignals(false);

}

void Terrain::retournerPageAccueil()// permet de revenir a notre page de menu
{
    this->close();
    Menu::getMenu()->show();

}

