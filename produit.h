#ifndef REVENUE_H
#define REVENUE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include<QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include<QSqlRecord>
#include <QTableView>

class produit
{
int id ,quantite,prix;
QString nom, datee,categorie;
public:
//constructeur
produit();
produit(QString,int,int,int,QString,QString);
//getters
QString getnom(){return nom ;}
int getid(){return id; }

int getprix(){return prix; }
int getquantite(){return quantite; }
QString getcategorie(){return categorie; }
QString getdate(){return datee; }


//setters
void setnom(QString nom){this->nom=nom;}
void setid(int id){this->id=id;}

void setprix(int prix){this->prix=prix;}
void setpquantite(int quantite){this->quantite=quantite;}
void setcategorie(QString categorie){this->categorie=categorie;}
void setdate(QString datee){this->datee=datee;}
//fonctionalite de class stock
bool ajouter();
QSqlQueryModel* afficher();
bool supprimer ( int id);
bool modifier(int id);
QSqlQueryModel* tri_id();
QSqlQueryModel* tri_prix();
QSqlQueryModel* recherche_id(QString categorie );
QSqlQueryModel *Product_type_pro_list();
QGraphicsScene *StatPromo_Product_type();
};

#endif // REVENUE_H
