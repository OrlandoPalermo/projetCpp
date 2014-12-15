#include "history.h"
#include "menu.h"

History::History(QWidget *parent) :
    QWidget(parent)
{
    vBox = new QVBoxLayout(this);
   // bodyLayout = new QVBoxLayout(vBox);

    title = new QLabel(this);
    QString titleH = "<h1>History</h1>";
    title->setStyleSheet("color: LawnGreen; text-decoration: underline;background-color:Darkblue;");
    title->setText(titleH);
    title->setAlignment(Qt::AlignHCenter);

    corps = new QLabel(this);
    QString content = "<p>Your girlfriend has been grounded by her father.</p><p> You nevertheless decide to meet her as you do not want to miss this rendezvous.</p><p> You get to her place to pick her up.</p><p id='test'> Your mission, should you choose to accept it, is... to infiltrate her home and free her.</p> <p><b>Be careful, it might not be so easy !</b></p>";
    corps->setStyleSheet("color:LawnGreen; background-color: Darkblue;");
    corps->setText(content);
    corps->setAlignment(Qt::AlignHCenter);

    retourMenu = new QPushButton(this);
    retourMenu->setStyleSheet("background-color: Gainsboro; color: darkblue;");
    retourMenu->setText("Return to main menu");

    playGame = new QPushButton(this);
    playGame->setStyleSheet("background-color: Gainsboro; color: darkblue;");
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

    this->resize(150,350);
    this->setWindowTitle("Infiltrate Love - History");
    this->setWindowIcon(QIcon("Images/iconJeu.png"));
    this->setStyleSheet("background-color: DarkBlue;font-size: 16px;");

}

History::~History(){

}

void History::afficherMenu(){
    this->close();
    Menu::getMenu()->show();
}

void History::lancerJeu(){
    this->close();
    terrain->show();

}
