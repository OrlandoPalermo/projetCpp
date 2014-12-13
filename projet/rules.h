#ifndef RULES_H
#define RULES_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class Rules : public QWidget
{
    Q_OBJECT
public:
    explicit Rules(QWidget *parent = 0);
    ~Rules();



signals:


public slots:
    void afficherMenu();

private:
    QVBoxLayout* vBox;
    QLabel *rules;
    QPushButton *retourMenuGeneral;
    QLabel *corpsRules;

};

#endif // RULES_H
