#ifndef BOUTIQUE_H
#define BOUTIQUE_H
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
#include<QPainter>
class Boutique
{
int ID;
QString NOM;
QString ADRESSE;
public:
Boutique();
Boutique(int,QString,QString);

void setID(int Id){this->ID=Id;}
void setNOM(QString Nom){this->NOM=Nom;}
void setADRESSE(QString Adresse){this->ADRESSE=Adresse;}


int getID(){return ID;}
QString getNOM(){return NOM;}
QString getADRESSE(){return ADRESSE;}


bool ajouter();
QSqlQueryModel *afficher();
bool modifier(int);
bool supprimer(int);
QSqlQueryModel *recherche(int);
QSqlQueryModel *tri();
void  genererPDF();
};

#endif // BOUTIQUE_H
