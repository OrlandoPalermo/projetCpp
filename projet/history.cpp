#include "history.h"
#include "menu.h"

History::History(QWidget *parent) :
    QWidget(parent)
{
    vBox = new QVBoxLayout(this);
   // bodyLayout = new QVBoxLayout(vBox);

    title = new QLabel(this);
    title->setText("History");
    title->setAlignment(Qt::AlignHCenter);

    corps = new QLabel(this);
    corps->setText("Your girlfriend has been grounded by her father.\n You nevertheless decide to meet her as you do not want to miss this rendezvous. \n You get to her place to pick her up. \n Your mission, should you choose to accept it, is... to infiltrate her home and free her. \n Be careful, it might not be so easy !");
    corps->setAlignment(Qt::AlignHCenter);

    retourMenu = new QPushButton(this);
    retourMenu->setText("Return to main menu");

    playGame = new QPushButton(this);
    playGame->setText("Play");

    vBox->addWidget(title);
    vBox->addWidget(corps);

    hBox = new QHBoxLayout;

    hBox->addWidget(retourMenu);
    hBox->addWidget(playGame);

    vBox->addLayout(hBox);

    terrain = new Terrain();


    QObject::connect(retourMenu,SIGNAL(clicked()),this,SLOT(afficherMenu()));
    QObject::connect(playGame,SIGNAL(clicked()),this,SLOT(lancerJeu()));

    this->setWindowTitle("Infiltrate Love - History");
    this->setWindowIcon(QIcon("Images/iconJeu.png"));

}

History::~History(){
    delete retourMenu;
    delete playGame;


    delete corps;
    delete title;

}

void History::afficherMenu(){
    this->close();
    Menu::getMenu()->show();
}

void History::lancerJeu(){
    this->close();
    terrain->show();

}
