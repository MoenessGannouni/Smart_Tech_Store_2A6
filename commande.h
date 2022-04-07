#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class commande
{
    public:
        commande();
        commande(int,int,QString);
        QString get_type();


        int get_nbcommande();
        int get_quantite();

    bool ajouter();
        QSqlQueryModel * afficher();
    bool supprimer(int);
     QSqlQueryModel * cherch_com(QString);
    bool modifier(int , QString  );
        QSqlQueryModel * afficher_tri_nb();
        QSqlQueryModel * afficher_tri_type();

private:

    int nbcommande;
    int quantite;
    QString type;

};
#endif // SERVICE_H
