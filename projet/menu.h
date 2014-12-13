#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>

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



    static Menu* getMenu(){return instance;}

signals:

public slots:
    void showRules();
    void showCredit();
    void showHistory();

private:

    static Menu* instance;

    QVBoxLayout* vBox;
    QHBoxLayout* hBox;

    // Run game button
    QPushButton *bPlay;

    //Credit's button
    QPushButton *bCredit;

    //Rules button
    QPushButton *bRules;

    Rules* pageRegles;
    Credit* pageCredit;
    History* pageHistory;


};

#endif // MENU_H
