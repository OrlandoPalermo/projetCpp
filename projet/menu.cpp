#include "menu.h"
#include <QPixmap>

Menu* Menu::instance = NULL;
Menu::Menu(QWidget *parent) :
    QWidget(parent)
{
    QPixmap("D:/Users/Alexandre/Pictures/menuBck.png");


    vBox = new QVBoxLayout(this);
    hBox = new QHBoxLayout(this);

    bPlay = new QPushButton(this);
    bPlay->setText("Play");

    bCredit = new QPushButton(this);
    bCredit->setText("Credits");

    bRules = new QPushButton(this);
    bRules->setText("Rules");

    vBox->addWidget(bPlay);
    vBox->addWidget(bCredit);
    vBox->addWidget(bRules);

    setLayout(vBox);


    pageRegles = new Rules();
    pageCredit = new Credit();
    pageHistory = new History();

    this->setFixedSize(700,400);
    this->setWindowTitle("Infiltrate Love - Menu");
    this->setWindowIcon(QIcon("D:/Users/Alexandre/Pictures/iconJeu.png"));


    instance = this;

    //this->setStyleSheet("background-color:red");

    QObject::connect(bRules,SIGNAL(clicked()),this,SLOT(showRules()));
    QObject::connect(bCredit,SIGNAL(clicked()),this,SLOT(showCredit()));
    QObject::connect(bPlay,SIGNAL(clicked()),this,SLOT(showHistory()));
}
Menu::~Menu()
{
    delete bPlay;
    delete bCredit;
    delete bRules;
    delete vBox;

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

