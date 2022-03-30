#ifndef HORAIRE_H
#define HORAIRE_H
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include<QTime>

class Horaire
{
int ID;
QString HEUREO;
QString HEUREF;
public:
Horaire();
Horaire(int,QString,QString);

void setID(int Id){this->ID=Id;}
void setHEUREO(QString Heureo){this->HEUREO=Heureo;}
void setHEUREF(QString Heuref){this->HEUREF=Heuref;}

int getID(){return ID;}
QString getHEUREO(){return HEUREO;}
QString getHEUREF(){return HEUREF;}

bool ajouter();
QSqlQueryModel *afficher();
bool modifier(int);
bool supprimer(int);
};


#endif // HORAIRE_H
