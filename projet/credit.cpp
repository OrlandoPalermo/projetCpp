#include "credit.h"
#include "menu.h"

Credit::Credit(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Infiltrate Love - Credits");
    this->setWindowIcon(QIcon("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/iconJeu.png"));
    this->setFixedSize(320,400);

    vBox = new QVBoxLayout(this);

    title = new QLabel(this);
    title->setText("Credits:");
    title->setAlignment(Qt::AlignHCenter);

    corps = new QLabel(this);
    corps->setText("Created by: \n PALERMO Orlando \n FRAIPONT Anthony \n BONNET Leandro \n BROSTEAU Alexandre");
    corps->setAlignment(Qt::AlignHCenter);

    retourMenu = new QPushButton(this);
    retourMenu->setText("Return menu");

    vBox->addWidget(title);
    vBox->addWidget(corps);
    vBox->addWidget(retourMenu);

    this->setLayout(vBox);

    QObject::connect(retourMenu,SIGNAL(clicked()),this,SLOT(afficherMenu()));
}

Credit::~Credit(){
    delete title;
    delete corps;
    delete retourMenu;
    delete vBox;
}

void Credit::afficherMenu(){
    this->close();
    Menu::getMenu()->show();
}

