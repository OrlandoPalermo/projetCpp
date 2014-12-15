#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class Credit : public QWidget
{
    Q_OBJECT
public:
    explicit Credit(QWidget *parent = 0);
    ~Credit();

signals:

public slots:
    void afficherMenu();

private:

    QLabel *corps;
    QPushButton *retourMenu;
    QVBoxLayout *vBox;

};

#endif // CREDIT_H
