#include "historique.h"

historique::historique(int cin_client, QString nom_produit ,QString date_achat)
{
    this->cin_client=cin_client;
    this->nom_produit=nom_produit;
    this->date_achat=date_achat;
}

bool historique::ajouterP()
{
    QSqlQuery query;
    QString res = QString::number(cin_client);

    query.prepare("insert into historique(cin_client, nom_produit, date_achat)" "values(:cin_client, :nom_produit, :date_achat)");

    query.bindValue(":cin_client",res);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":date_achat",date_achat);

    return query.exec();

}

QSqlQueryModel * historique::afficherP()
{

}

bool historique::supprimerP(int id_achat)
{
    QSqlQuery query;
    QString res= QString::number(id_achat);

    query.prepare("delete from historique where id_achat= :id_achat");
    query.bindValue(":id_achat",res);

    return query.exec();
}


