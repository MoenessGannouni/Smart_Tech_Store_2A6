#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>


class historique
{
private:
    //Atrributs
    int id_achat,cin_client;
    QString nom_produit,date_achat;

public:
    //Constructeurs
    historique(){};
    historique(int,QString,QString);

    //Getters
    int getCin() {return cin_client;}
    int getId() {return id_achat;}
    QString getNomProduit() {return nom_produit;}
    QString getDateAchat() {return date_achat;}

    //Setters
    void setNomProduit(QString nom) {nom_produit=nom;}
    void setDateAchat(QString dateA) {date_achat=dateA;}

    //Methodes
    bool ajouterP();
    QSqlQueryModel * afficherP();
    bool supprimerP(int);
    bool modifierP();

};

#endif // HISTORIQUE_H
