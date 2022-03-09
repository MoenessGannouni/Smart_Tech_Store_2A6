#include "dependance.h"

#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
dependance::dependance()
{
    id=0;
    montant=0;

    type="";
    datee="";
}
dependance::dependance(int id ,int montant,QString type,QString datee)
{
        this->id=id;
        this->montant=montant;
        this->type=type;
        this->datee=datee;
}

bool dependance::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO dependance (id,montant,type,datee) VALUES (:id,:montant,:type,:datee)");
    query.bindValue(":id",id);
    query.bindValue(":montant",montant);
    query.bindValue(":type",type);
    query.bindValue(":datee",datee);

    return query.exec();
}

QSqlQueryModel* dependance::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM dependance");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));

    return model;
}


bool dependance::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from dependance where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}

bool dependance::modifier()
{


    QSqlQuery query;

    query.prepare("UPDATE dependance SET montant=:montant,type=:type,datee=:datee WHERE id = :id");
     query.bindValue(":id",id);
     query.bindValue(":montant",montant);
     query.bindValue(":type",type);
    query.bindValue(":datee",datee);
    return query.exec();
}


QSqlQueryModel* dependance::tri_montant()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM dependance order by montant  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));

    return model;
}

QSqlQueryModel* dependance::tri_date()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM dependance order by datee  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));

    return model;
}



QSqlQueryModel* dependance::recherche_id(QString type )
{


    QSqlQueryModel * model= new QSqlQueryModel();
        QString qry="select * from dependance where type like '%"+type+"%' ";
        qDebug()<<qry;
        model->setQuery(qry);
        return model;



}
