#ifndef REVENUE_H
#define REVENUE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class revenue
{
int id ,quantite,montant;
QString datee,produit;
public:
//constructeur
revenue();
revenue(int,int,QString,int,QString);
//getters
QString getproduit(){return produit; }
int getmontant(){return montant; }
QString getdate(){return datee; }
int getid(){return id; }
int getquantite(){return quantite; }
//setters
void setproduit(QString produit){this->produit=produit;}
void setid(int id){this->id=id;}
void setmontant(int montant){this->montant=montant;}
void setpquantite(int quantite){this->quantite=quantite;}
void setdate(QString datee){this->datee=datee;}
//fonctionalite de class revenue
bool ajouter();
QSqlQueryModel* afficher();
bool supprimer ( int id);
bool modifier();
QSqlQueryModel* tri_montant();
QSqlQueryModel* tri_date();
QSqlQueryModel* recherche_id(QString produit );
};

#endif // REVENUE_H
