#include "majordhomme.h"
#include<QThread>
Majordhomme::Majordhomme(int vitesse, QWidget* parent, int x, int y, int l, int h, int vision, bool orientationVision,int posXMin,int posXMax) : Ennemi(vitesse, parent, x, y, l, h, vision, orientationVision,posXMin,posXMax)
{
    //insertion de l'image du majordhomme ici
    setPixmap(QPixmap("Majors/major_1.png"));
    this->setFixedSize(l,h);

    this->setNumImage(0);
}
Majordhomme::Majordhomme(const Majordhomme &m):Ennemi(m)
{
    setPixmap(QPixmap("Majors/major_1.png"));
    this->setFixedSize(m.Ennemi::getL(),m.Ennemi::getH());
    this->setNumImage(0);
}

void Majordhomme::seDeplacer(int direction) {
    switch(direction)
    {
    case 1 :
        if ( this->Ennemi::getPosXMax() < this->Ennemi::getX() + this->Ennemi::getL() )
        {
            this->Ennemi::setOrientationVision(false);
        }
        else
        {
        Personnage::setX(Personnage::getX() + Personnage::getVitesseDeplacement()); // deplacement du heros à droite
        if(this->getNumImage()==15 || this->getNumImage()<=7)
            /*Si le sprite atteind le chiffre 15 pendant la ronde et que le timer de ronde n'est pas finie alors
             * il revient à sa position initiale pour créer un déplacement fluide et constant et s'il est <= 7 alors
             * ça signifie qu'on était en mouvement de gauche et qu'on a changé de isOrientationVision()*/

        {
            this->setNumImage(8);
        }
        this->animer();
        }
        break;
    case 2 :
        if ( this->Ennemi::getPosXMin() > this->Ennemi::getX() )
        {
            this->Ennemi::setOrientationVision(true);
        }
        else
        {
        Personnage::setX(Personnage::getX() - Personnage::getVitesseDeplacement()); // deplacement du heros à gauche
        if(this->getNumImage()>=8 || this->getNumImage()==7)
            /*Si le sprite atteind le chiffre 7 pendant la ronde et que le timer de ronde n'est pas finie alors
             * il revient à sa position initiale pour créer un déplacement fluide et constant et s'il est >=8 alors
             * ça signifie qu'on était en mouvement de gauche et qu'on a changé de isOrientationVision()*/
         {
             this->setNumImage(0);
         }
        this->animer();
        }
        break;
    }
}

void Majordhomme::remplacerSprite(int numPhoto)
{
    switch(numPhoto)
    {
    //Les images de 0 à 7 correspondent au déplacement vers la gauche
    case 0 : this->setPixmap(*(new QPixmap("Majors/major_1.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 1 : this->setPixmap(*(new QPixmap("Majors/major_2.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 2 : this->setPixmap(*(new QPixmap("Majors/major_3.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 3: this->setPixmap(*(new QPixmap("Majors/major_4.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 4: this->setPixmap(*(new QPixmap("Majors/major_5.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 5: this->setPixmap(*(new QPixmap("Majors/major_6.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 6: this->setPixmap(*(new QPixmap("Majors/major_7.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;
    case 7 : this->setPixmap(*(new QPixmap("Majors/major_8.png")));this->pixmap()->scaled(QSize(100,60),Qt::IgnoreAspectRatio,Qt::FastTransformation); break;

    //Les images de 8 à 15 correspondent au déplacement vers la droite
    case 8 : this->setPixmap(*(new QPixmap("Majors/major_gDroiteReverse.png"))); break;
    case 9 : this->setPixmap(*(new QPixmap("Majors/major_gDroitePlieeReverse.png"))); break;
    case 10 : this->setPixmap(*(new QPixmap("Majors/major_gGauchePlieeReverse.png"))); break;
    case 11 : this->setPixmap(*(new QPixmap("Majors/major_gGaucheSemiPlieeReverse.png"))); break;
    case 12 : this->setPixmap(*(new QPixmap("Majors/major_gGaucheTendueReverse.png"))); break;
    case 13 : this->setPixmap(*(new QPixmap("Majors/major_gGauchePlieeArriereReverse.png"))); break;
    case 14 : this->setPixmap(*(new QPixmap("Majors/major_gDroiteLeveeReverse.png"))); break;
    case 15 : this->setPixmap(*(new QPixmap("Majors/major_gPrepareRetourReverse.png"))); break;

    //default : this->setStyleSheet("QLabel {background-color : blue;}");

        /*case 8 : this->setPixmap(*(new QPixmap("Majors/Gosse1.png"))); break;
        case 9 : this->setPixmap(*(new QPixmap("Majors/Gosse2.png"))); break;
        case 10 : this->setPixmap(*(new QPixmap("Majors/Gosse3.png"))); break;
        case 11: this->setPixmap(*(new QPixmap("Majors/Gosse4.png"))); break;
        case 12: this->setPixmap(*(new QPixmap("Majors/Gosse5.png"))); break;
        case 13: this->setPixmap(*(new QPixmap("Majors/Gosse6.png"))); break;
        case 14: this->setPixmap(*(new QPixmap("Majors/Gosse7.png"))); break;
        case 15 : this->setPixmap(*(new QPixmap("Majors/Gosse8.png"))); break;*/

        //Les images de 8 à 15 correspondent au déplacement vers la droite
       /* case 8 : this->setPixmap(*(new QPixmap("Majors/major_gDroiteReverse.png"))); break;
        case 9 : this->setPixmap(*(new QPixmap("Majors/major_gDroitePlieeReverse.png"))); break;
        case 10 : this->setPixmap(*(new QPixmap("Majors/major_gGauchePlieeReverse.png"))); break;
        case 11 : this->setPixmap(*(new QPixmap("Majors/major_gGaucheSemiPlieeReverse.png"))); break;
        case 12 : this->setPixmap(*(new QPixmap("Majors/major_gGaucheTendueReverse.png"))); break;
        case 13 : this->setPixmap(*(new QPixmap("Majors/major_gGauchePlieeArriereReverse.png"))); break;
        case 14 : this->setPixmap(*(new QPixmap("Majors/major_gDroiteLeveeReverse.png"))); break;
        case 15 : this->setPixmap(*(new QPixmap("Majors/major_gPrepareRetourReverse.png"))); break;*/
    }
}

void Majordhomme::animer()// méthode qui gère l'animation des sprites en remplaçant leurs images
{
    if(this->getNumImage()==0)
    {

        this->setNumImage(1);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==1)
    {

        this->setNumImage(2);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==2)
    {

        this->setNumImage(3);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==3)
    {

        this->setNumImage(4);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==4)
    {

        this->setNumImage(5);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==5)
    {

        this->setNumImage(6);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==6)
    {

        this->setNumImage(7);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==7)
    {
        this->setNumImage(8);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==8)
    {

        this->setNumImage(9);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==9)
    {

        this->setNumImage(10);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==10)
    {

        this->setNumImage(11);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==11)
    {

        this->setNumImage(12);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==12)
    {

        this->setNumImage(13);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==13)
    {

        this->setNumImage(14);
        this->remplacerSprite(this->getNumImage());
    }
    else if(this->getNumImage()==14)
    {

        this->setNumImage(15);
        this->remplacerSprite(this->getNumImage());
    }
}
