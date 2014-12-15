#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QSound>

#include "rules.h"
#include "credit.h"
#include "history.h"


class Menu : public QWidget
{
    Q_OBJECT
public:
     explicit Menu(QWidget *parent = 0);
    ~Menu();

    Rules* getPageRegles()const{return pageRegles;}
    Credit* getPageCredit()const{return pageCredit;}
    History* getPageHistory()const{return pageHistory;}
    bool eventFilter(QObject *, QEvent *);


    static Menu* getMenu(){return instance;}

signals:
    void pressButton(int);
public slots:
    void actionButton(int);

private:

    static Menu* instance;

    //QVBoxLayout* vBox;
    QHBoxLayout* hBox;

    // Run game button
    QLabel *bPlay;

    //Credit's button
    QLabel *bCredit;

    //Rules button
    QLabel *bRules;

    //Exit button
    QLabel *bExit;

    Rules* pageRegles;
    Credit* pageCredit;
    History* pageHistory;


};

#endif // MENU_H
