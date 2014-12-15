#include "menu.h"
#include <QPixmap>

Menu* Menu::instance = NULL;
Menu::Menu(QWidget *parent) :
    QWidget(parent)
{

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("Images/bck.png")));


    this->setPalette(palette);

    hBox = new QHBoxLayout(this);
    hBox->setAlignment(Qt::AlignBottom);
    hBox->setContentsMargins(40, 20, 10, 5);

    bPlay = new QLabel(this);
    bPlay->setPixmap(QPixmap("Images/boutons/bPlay.png"));
    bPlay->move(0, 150);
    bPlay->setCursor(Qt::PointingHandCursor);

    bCredit = new QLabel(this);
    bCredit->setPixmap(QPixmap("Images/boutons/bCredits.png"));
    bCredit->setCursor(Qt::PointingHandCursor);

    bRules = new QLabel(this);
    bRules->setPixmap(QPixmap("Images/boutons/bRules.png"));
    bRules->setCursor(Qt::PointingHandCursor);

    bExit = new QLabel(this);
    bExit->setPixmap(QPixmap("Images/boutons/bExit.png"));
    bExit->setCursor(Qt::PointingHandCursor);



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

    this->setWindowIcon(QIcon("Images/iconJeu.png"));
    instance = this;

    //On installe un filtre sur chacun des boutons
    bPlay->installEventFilter(this);
    bRules->installEventFilter(this);
    bCredit->installEventFilter(this);
    bExit->installEventFilter(this);

    QObject::connect(this, SIGNAL(pressButton(int)), this, SLOT(actionButton(int)));

}
Menu::~Menu()
{

    delete pageRegles;
    delete pageCredit;
    delete pageHistory;
}

//Méthode qui envoie un signal quand on clique sur les labels
bool Menu::eventFilter(QObject *object, QEvent *e) {
    if (e->type() == QEvent::MouseButtonPress) {

        if (object == bPlay) {
            emit pressButton(0);
            return true;
        }
        else if (object == bCredit) {
            emit pressButton(1);
            return true;
        }

        else if (object == bRules) {
            emit pressButton(2);
            return true;
        }
        else if (object == bExit) {
            emit pressButton(3);
            return true;
        }
    }

    return QObject::eventFilter(object, e);
}

//Permet de décritre les actions des boutons
void Menu::actionButton(int idButton) {
    switch(idButton) {
    case 0: QSound::play("ClicBouton.wav"); this->close(); getPageHistory()->show(); break;
    case 1: QSound::play("ClicBouton.wav");this->close(); getPageCredit()->show();  break;
    case 2: QSound::play("ClicBouton.wav");this->hide();  getPageRegles()->show();  break;
    case 3: QSound::play("ClicBouton.wav");this->close();                           break;
    }
}

