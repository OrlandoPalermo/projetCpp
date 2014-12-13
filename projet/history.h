#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "terrain.h"
class History : public QWidget
{
    Q_OBJECT
public:
    explicit History(QWidget *parent = 0);
    ~History();

signals:

public slots:
    void afficherMenu();
    void lancerJeu();

private:
    QVBoxLayout *vBox;
    QHBoxLayout *hBox;

    QLabel *title;
    QLabel *corps;

    QPushButton *retourMenu;
    QPushButton *playGame;

    Terrain *terrain;


};

#endif // HISTORY_H
