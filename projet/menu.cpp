#include "menu.h"
#include <QPixmap>

Menu* Menu::instance = NULL;
Menu::Menu(QWidget *parent) :
    QWidget(parent)
{


    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/bck.png")));


    this->setPalette(palette);


    //vBox = new QVBoxLayout(this);
    //vBox->setAlignment(this,Qt::AlignBottom);
    hBox = new QHBoxLayout(this);
    hBox->setAlignment(Qt::AlignBottom);


    bPlay = new QPushButton(this);
    bPlay->setIcon(QIcon("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/boutons/bPlay.png"));
    bPlay->setIconSize(QSize(62,40));

    bCredit = new QPushButton(this);
    bCredit->setIcon(QIcon("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/boutons/bCredits.png"));
    bCredit->setIconSize(QSize(62,40));

    bRules = new QPushButton(this);
    bRules->resize(62,40);
    bRules->setIcon(QIcon("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/boutons/bRules.png"));
    bRules->setIconSize(QSize(62,40));

    bExit = new QPushButton(this);

    bExit->resize(62,40);
    bExit->setIcon(QPixmap("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/boutons/bExit.png"));
    bExit->setIconSize(QSize(62,40));


   // vBox->addLayout(hBox);
    hBox->addWidget(bPlay);
    hBox->addWidget(bCredit);
    hBox->addWidget(bRules);
    hBox->addWidget(bExit);

    setLayout(hBox);


    pageRegles = new Rules();
    pageCredit = new Credit();
    pageHistory = new History();

    this->setFixedSize(700,400);
    this->setWindowTitle("Infiltrated love 1- Menu");
    this->setWindowIcon(QIcon("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/iconJeu.png"));


    instance = this;

    //this->setStyleSheet("background-color:red");

    QObject::connect(bRules,SIGNAL(clicked()),this,SLOT(showRules()));
    QObject::connect(bCredit,SIGNAL(clicked()),this,SLOT(showCredit()));
    QObject::connect(bPlay,SIGNAL(clicked()),this,SLOT(showHistory()));
    QObject::connect(bExit,SIGNAL(clicked()),this,SLOT(close()));
}
Menu::~Menu()
{
    delete bPlay;
    delete bCredit;
    delete bRules;
    delete hBox;
    //delete vBox;

    delete pageRegles;
    delete pageCredit;
    delete pageHistory;

    delete instance;
}

void Menu::showRules()
{
    //instance = this;
    this->hide();
    getPageRegles()->show();
}

void Menu::showCredit(){
    this->close();
    getPageCredit()->show();
}

void Menu::showHistory(){
    this->close();
    getPageHistory()->show();
}

