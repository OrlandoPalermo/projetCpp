#include "rules.h"
#include "menu.h"
Rules::Rules(QWidget *parent) :
    QWidget(parent)
{

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/bck.png")));

    this->setPalette(palette);


    vBox = new QVBoxLayout(this);

    rules = new QLabel(this);
    rules->setStyleSheet("color: red;");

    QString ru = "<b>Rules</b>";
    rules->setText(ru);
    rules->setAlignment(Qt::AlignHCenter);

    corpsRules = new QLabel(this);
    corpsRules->setText("1:\t Save your girlfriend !\n2:\t Do not get caught\n3:\tYou can hide you with the decors, press key 'E'\n");
    corpsRules->setAlignment(Qt::AlignHCenter);

    retourMenuGeneral = new QPushButton(this);
    retourMenuGeneral->setText("Return menu");

    vBox->addWidget(rules);
    vBox->addWidget(corpsRules);
    vBox->addWidget(retourMenuGeneral);


    setLayout(vBox);

    this->setFixedSize(700,400);
    this->setWindowTitle("Infiltrate Love - Rules");
    this->setWindowIcon(QIcon("D:/Users/Alexandre/Documents/GitHub/projetC++/projetCpp/projet/Images/iconJeu.png"));

    QObject::connect(retourMenuGeneral,SIGNAL(clicked()),this,SLOT(afficherMenu()));
}

Rules::~Rules()
{
    delete rules;
    delete retourMenuGeneral;
    delete vBox;
}
void Rules::afficherMenu()
{
    this->close();
    Menu::getMenu()->show();
}

