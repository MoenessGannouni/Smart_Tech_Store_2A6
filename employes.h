#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Employes
{
    QString Nom, Prenom,Adresse,Adressemail,Date_naissance,Departement,Date_embauche ;
    int CIN ;

public: public:
    //constructeur
   Employes();
   Employes(int,QString,QString,QString,QString,QString,QString,QString);
    //getters
    int getCIN(){return CIN ; }
    QString getNom(){return Nom; }
    QString getPrenom(){return Prenom ; }
    QString getAddresse(){return Adresse; }
    QString getAdressemail(){return Adressemail; }
    QString getDate_naissance(){return Date_naissance; }
    QString getDepartement(){return Departement; }
    QString getDate_embauche(){return Date_embauche; }


    //setters
    void setCIN(int CIN){this-> CIN=CIN; }
    void setNom(QString Nom){this-> Nom=Nom; }
    void setPrenom(QString Prenom){this-> Prenom= Prenom ; }
    void setAdresse(QString Adresse){this-> Adresse= Adresse; }
    void setAdressemail(QString Adressemail){this-> Adressemail= Adressemail; }
    void setDate_naissance(QString Date_naissance){this-> Date_naissance=Date_naissance; }
    void setDepartement(QString Departement){this-> Departement=Departement; }
    void setDate_embauche(QString Date_embauche){this-> Date_embauche=Date_embauche; }


    //fonctionalite de class revenue
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * trier();
    QSqlQueryModel* recherche(QString);

    bool supprimer ( int id);
    bool modifier(int id);

};

#endif // EMPLOYES_H
