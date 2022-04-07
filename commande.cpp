#include "commande.h"
#include <QDebug>
#include <QString>
#include<QMessageBox>


commande::commande()
{
    nbcommande=0;
    quantite=0;
    type="";
}

commande::commande(int nbcommande, int quantite  ,QString type )
{
  this->nbcommande=nbcommande;
  this->quantite=quantite;
  this->type=type;
}

    QString commande::get_type(){return  type;}

    int commande::get_nbcommande(){return  nbcommande;}

    int commande::get_quantite(){return  quantite;}

    bool commande::ajouter()

{
    QSqlQuery query;
    QString res11= QString::number(nbcommande);
    QString res22= QString::number(quantite);

    query.prepare("INSERT INTO commande (NB_COMMANDE, QUANTITE ,TYPE) "
                        "VALUES (:nbcommande,  :quantite, :type )");
    query.bindValue(":nbcommande", res11);
    query.bindValue(":quantite", res22);
    query.bindValue(":type", type);
    return    query.exec();
}

bool commande::supprimer(int nbcommande)
{
      QSqlQuery query;
      QString res= QString::number(nbcommande);
      query.prepare("Delete from COMMANDE where NB_COMMANDE = :nbcommande ");
      query.bindValue(":nbcommande", res);
   return query.exec();
}

    QSqlQueryModel * commande::afficher(){
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from commande");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NB_COMMANDE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
     return model;
}
    QSqlQueryModel *commande::cherch_com(QString nbcommande)
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select NB_COMMANDE, QUANTITE,  TYPE from COMMANDE where NB_COMMANDE='"+nbcommande+"'");
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbcommande"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("type"));
    return model;
    }
bool commande::modifier(int nbcommande ,QString type)
{
    QSqlQuery query;
    QString res= QString::number(nbcommande);
    query.prepare("update commande set nb_commande = :c where type = :i");
    query.bindValue(":i", type);
    query.bindValue(":c", res);
    return query.exec();
}

QSqlQueryModel * commande::afficher_tri_nb()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from commande order by NB_COMMANDE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NB_COMMANDE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE   "));
    return model;
}

QSqlQueryModel * commande::afficher_tri_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from commande order by TYPE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NB_COMMANDE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
    return model;
}



