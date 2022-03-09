#ifndef DEPENDANCE_H
#define DEPENDANCE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class dependance
{
    int id ,montant;
    QString datee,type;
    public:
    //constructeur
    dependance();
    dependance(int,int,QString,QString);
    //getters
    QString getdate(){return datee; }
    int getmontant(){return montant; }
    QString gettype(){return type; }
    int getid(){return id; }

    //setters
    void settype(QString type){this->type=type;}
    void setid(int id){this->id=id;}
    void setmontant(int montant){this->montant=montant;}
    void setdate(QString datee){this->datee=datee;}
    //fonctionalite de class revenue
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer ( int id);
    bool modifier();
    QSqlQueryModel* tri_montant();
    QSqlQueryModel* tri_date();
    QSqlQueryModel* recherche_id(QString type );

};

#endif // DEPENDANCE_H
