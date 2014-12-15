#include "credit.h"
#include "menu.h"

Credit::Credit(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Infiltrate Love - Credits");
    this->setWindowIcon(QIcon("Images/iconJeu.png"));
    this->setFixedSize(320,400);

    vBox = new QVBoxLayout(this);

   /* title = new QLabel(this);
    title->setText("Credits:");
    title->setStyleSheet("font-style : italic;");
    title->setAlignment(Qt::AlignHCenter);*/

    corps = new QLabel(this);
    corps->setText("Created by :\n************* \n\n\n*** PALERMO Orlando ***\n\n\n*** FRAIPONT Anthony *** \n\n\n*** BONNET Leandro ***  \n\n\n*** BROSTEAU Alexandre *** \n\n\n 3IC  2014-2015");
    corps->setStyleSheet("font-weight:bold; background-color : darkblue;  color : lightgreen; font-size: 15px;");
    corps->setAlignment(Qt::AlignHCenter);

    retourMenu = new QPushButton(this);
    retourMenu->setText("Return to main menu");

   // vBox->addWidget(title);
    vBox->addWidget(corps);
    vBox->addWidget(retourMenu);

    this->setLayout(vBox);

    QObject::connect(retourMenu,SIGNAL(clicked()),this,SLOT(afficherMenu()));
}

Credit::~Credit(){

}

void Credit::afficherMenu(){
    this->close();
    Menu::getMenu()->show();
}

