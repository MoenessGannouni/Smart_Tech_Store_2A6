#include "revenue.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
revenue::revenue()
{
    id=0;
    montant=0;
    quantite=0;
    produit="";
    datee="";
}
revenue::revenue(int id ,int montant,QString produit ,int quantite,QString datee)
{
        this->id=id;
        this->montant=montant;
        this->quantite=quantite;
        this->produit=produit;
        this->datee=datee;
}

bool revenue::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO revenue (id,montant,produit,quantite,datee) VALUES (:id,:montant,:produit,:quantite,:datee)");
    query.bindValue(":id",id);
    query.bindValue(":montant",montant);
    query.bindValue(":produit",produit);
    query.bindValue(":quantite",quantite);
    query.bindValue(":datee",datee);

    return query.exec();
}

QSqlQueryModel* revenue::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM revenue ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("produit"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

    return model;
}

bool revenue::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE revenue SET montant=:montant,produit=:produit,quantite=:quantite,datee=:datee WHERE id = :id");
     query.bindValue(":id",id);
     query.bindValue(":montant",montant);
     query.bindValue(":produit",produit);
     query.bindValue(":quantite",quantite);
     query.bindValue(":datee",datee);
    return query.exec();
}

bool revenue::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from revenue where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}


QSqlQueryModel* revenue::tri_montant()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM revenue order by montant  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("produit"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

    return model;
}

QSqlQueryModel* revenue::tri_date()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM revenue order by datee  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("produit"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

    return model;
}

QSqlQueryModel* revenue::recherche_id(QString produit )
{


    QSqlQueryModel * model= new QSqlQueryModel();
        QString qry="select * from revenue where produit like '%"+produit+"%' ";
        qDebug()<<qry;
        model->setQuery(qry);
        return model;



}
