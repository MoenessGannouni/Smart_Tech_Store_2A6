#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Clients
{
private:
    //Attributs
    int cin;
    QString nom,prenom,adresse,adresse_mail,date_naissance;
    QDate date_ajout;

public:
    //Constructeurs
    Clients(){};
    Clients(int, QString, QString, QString, QString, QString);

    //Getters
    int getCin(){return cin;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getAdresse(){return adresse;}
    QString getAdresseMail(){return adresse_mail;}
    QString getDateNaissance(){return date_naissance;}
    QDate getDateAjout(){return date_ajout;}

    //Setters
    void setCin(int cin){this->cin=cin;}
    void setNom(QString nom){this->nom=nom;}
    void setPrenom(QString prenom){this->prenom=prenom;}
    void setAdresse(QString adresse){this->adresse=adresse;}
    void setAdresseMail(QString adresse_mail){this->adresse_mail=adresse_mail;}
    void setDateNaissance(QString date_naissance){this->date_naissance=date_naissance;}
    void setDateAjout(QDate date_ajout){this->date_ajout=date_ajout;}

    //Methodes
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();




};

#endif // CLIENT_H
