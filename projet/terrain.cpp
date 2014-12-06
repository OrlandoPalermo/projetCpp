#include "terrain.h"
#include <QApplication>
#include <vector>

using namespace std;
Terrain::Terrain() : QWidget()
{
    labFond = new QLabel(this); //QLabel représentant le contenur de l'image de fond du stage
    this->setFixedSize(960,720);

    fond = new QPixmap("Terrain_1Ref.png"); //QPixmap représentante l'image de fond en elle-même
    /*Note aux programmeurs : pour pouvoir mettre une image en chemin relatif, il est absolument impératif
     * de placer les images dans le dossier "build" du projet et non dans le dossier "projet" lui-même */

    labFond->setPixmap(*fond);

    heros = new Heros(5,this,108,575,23,42,true,false,false,true); // arg1 : vitesse , arg2 : parent => terrain , arg3 et arg4 coordonnées x et y , arg5 : repéré , arg6 : visible

    ennemis = new vector<Ennemi*>; // liste d'ennemis
    ennemis->push_back(new Majordhomme(2,this,700,375,53,73,10,false));
    ennemis->push_back(new Majordhomme(2,this,870,540,53,73,10,false));

    decors = new vector<Decor*>;
    /*decors->push_back(new Decor(this,672,728,530,610));
    decors->push_back(new Decor(this,772,803,473,610));
    decors->push_back(new Decor(this,870,957,393,446));*/
    decors->push_back(new Armoire("Armoire", this, 672, 530));
    decors->push_back(new Echelle("Echelle", this, 772, 473));
    //decors->push_back(new Porte(this, 870, 393));

    listeRepere = new vector<Ennemi*>; // liste des ennemis ayant repere le heros

    //Initialisation et configuration des timers
    //-------------------------------------------

    timer = new QTimer(this); // timer de colission
    timer->setInterval(50); // permet de gérer l'intervalle entre chaque répétitions

    sensTimerRonde = new QTimer(this); // timer pour le changement de direction des ennemis
    sensTimerRonde->setInterval(5000);

    dureeSensDeplacement = new QTimer(this); //  timer pour la ronde des ennemis
    dureeSensDeplacement->setInterval(50);

    //Liaisons signaux et slots
    //--------------------------

    QObject::connect( timer, SIGNAL( timeout() ), this, SLOT(  testColission() ) ) ;
    QObject::connect( sensTimerRonde, SIGNAL( timeout() ), this, SLOT(  changeSensDeplacementEnnemis() ) ) ;
    QObject::connect( dureeSensDeplacement, SIGNAL( timeout() ), this, SLOT(  deplacementEnnemis() ) ) ;

    //Démarrage des timers
    //---------------------

    timer->start();
    sensTimerRonde->start();
    dureeSensDeplacement->start();

}
Terrain::~Terrain()
{
    delete heros;

    for (int i(0); i < ennemis->size(); i++)
        delete (*ennemis)[i];

    for (int i(0); i < decors->size(); i++)
        delete (*decors)[i];

    delete ennemis;
    delete listeRepere;
    delete decors;
}

void Terrain::testColission()
{
    int sens = 0;
    bool dejaDedans = false;
    for (int i = 0 ; i < ennemis->size() ; i++ )
    {

        if ((*ennemis)[i]->isOrientationVision() == false) // orientation == false => gauche
        {
            sens = -1; // l'ennemis regarde vers la gauche
        }
        else
        {
            sens = 1; // l'ennemis regarde vers la droite
        }

        if (
           ( ( heros->getX() + heros->getL() ) < (*ennemis)[i]->getX() + (sens * (*ennemis)[i]->getVision() ) ) || // si le heros se trouve tout à gauche de l'ennemis
           (  heros->getX() > ( (*ennemis)[i]->getX() + (*ennemis)[i]->getL() + (sens * (*ennemis)[i]->getVision() ) ) ) || // si le heros se trouve tout à droite de l'ennemis
           ( ( heros->getY() + heros->getH() ) < (*ennemis)[i]->getY() ) || // si le heros se trouve au-dessus de l'ennemis
           (  heros->getY() > ( (*ennemis)[i]->getY() + (*ennemis)[i]->getH() ) ) // si le heros se trouve en-dessous de l'ennemis
           )
        {

        }
        else
        {
            heros->setRepere();
            //listeRepere->push_back((*ennemis)[i]); // rajout d'un ennemis parmis ceux ayant repere le heros
            for ( int j = 0 ; j < listeRepere->size() ; j++ )
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


    if ( heros->isRepere() == true )
    {
        //messageUtilisateur(); // message déclenché si le heros est dectecté
    }
}




void Terrain::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
    case Qt::Key_Right :

         heros->seDeplacer(1);break;



    case Qt::Key_Left :
        heros->seDeplacer(2);

        break;
    case Qt::Key_Down :
        heros->seDeplacer(4);

        break;
    case Qt::Key_Up :
        if(heros->getX()>= (*decors)[1]->getX())
        {
            heros->setAxeY();
        }
        heros->seDeplacer(3);


        break;
    }



}

void Terrain::messageUtilisateur()
{
    QMessageBox::information ( this , "Ca marche ca touche " , "Il y a colission !");
}

void Terrain::changeSensDeplacementEnnemis()
{
    for (int i = 0 ; i < ennemis->size() ; i++ )
    {
        (*ennemis)[i]->Ennemi::setOrientationVision(); // change le sens de la ronde ennemis
    }
}


void Terrain::deplacementEnnemis()
{
    int dep = 0;
    for (int i = 0 ; i < ennemis->size() ; i++ )
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
      heros->spriteReset();
    }

          //heros->spriteReset();


}

/*void Terrain::retirerEnnemisRepere()
{

}*/

