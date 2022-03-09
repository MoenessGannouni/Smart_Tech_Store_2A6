#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class departement
{
    QString Nom ;
    int id ;

public: public:
    //constructeur
   departement();
   departement(int,QString);
    //getters
    int getid(){return id ; }
    QString getNom(){return Nom; }



    //setters
    void setid(int id){this-> id=id; }
    void setNom(QString Nom){this-> Nom=Nom; }


    //fonctionalite de class revenue
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * trier();
    QSqlQueryModel* recherche(QString);

    bool supprimer ( int id);
    bool modifier(int id);

};

#endif // EMPLOYES_H
