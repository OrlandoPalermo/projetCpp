#ifndef OBJET_H
#define OBJET_H

#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <string>
#include <QPixmap>

class Objet : public QLabel
{
    Q_OBJECT

private:
    QPoint *coordonnees;
    std::string nom;
    virtual void abstract() = 0;
public:
    Objet(std::string, QWidget *, int, int);
    ~Objet();
    Objet(const Objet&);
    Objet& operator=(const Objet&);
    void setNom(std::string);
    std::string getNom() const;
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);

signals:
    void coordonneesChanged();
public slots:
    void coordonneesMaj();

};

#endif // OBJET_H
