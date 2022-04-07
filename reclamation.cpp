#include "reclamation.h"
#include <QDebug>
#include <QMessageBox>
#include<QDate>
#include <QSqlQuery>
#include<QTableView>
#include<QString>
#include <QVariant>
#include <QGraphicsScene>
#include <QSqlRecord>
#include <QVariant>
reclamation::reclamation()
{
id=0;
nom="";
mail="";
type="";
typerec="";
descr="";

}

reclamation::reclamation(int id,QString nom,QString mail,QString type ,QString typerec,QString descr)
{
    this->id=id;
    this->nom=nom;
    this->mail=mail;
    this->type=type;
    this->typerec=typerec;


    this->descr=descr;

}


bool reclamation::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO reclamation (ID,NOM,MAIL,DESCR,TYPE,TYPEREC) VALUES (:id, :nom, :mail, :descr, :type , :typerec )");

query.bindValue(":id",id);
query.bindValue("nom:",nom);
query.bindValue(":mail",mail);
query.bindValue(":type", type);
query.bindValue(":typrec", typerec);
query.bindValue(":descr", descr);


return    query.exec();
}

QSqlQueryModel * reclamation::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

model->setQuery("select * from reclamation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("En tant que"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("type de reclamation"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("descreption"));



    return model;
}

bool reclamation::supprimer(int id)
{
QSqlQuery query;

query.prepare("Delete from reclamation where ID = :id ");
query.bindValue(":id", id);
return    query.exec();
}

bool reclamation:: recherche(int id)
{
    QSqlQuery query;
      QString res=QString::number(id);
    query.prepare("select * from reclamation where id=:id");
    query.bindValue(":id",id);
    return query.exec() ;
}

bool reclamation::modifier()
  {  QSqlQuery query;

     query.bindValue(":id",id);
     query.bindValue("nom:",nom);
     query.bindValue(":mail",mail);
     query.bindValue(":type", type);
     query.bindValue(":typrec", typerec);
     query.bindValue(":descr", descr);

    query.prepare("update reclamation set nom=:nom, mail=:mail , descr=:descr, type=:type ,typerec=:typerec  where id = :id");

    return query.exec();
}


QSqlQueryModel * reclamation::tri_reclm()
{
    QSqlQuery * q1 = new  QSqlQuery ();
        QSqlQueryModel * model = new  QSqlQueryModel ();
        q1->prepare("SELECT * FROM reclamation ORDER BY ID ");
        q1->exec();
        model->setQuery(*q1);
        return model;
}

QSqlQueryModel * reclamation::tri2()
{
    QSqlQuery * q1 = new  QSqlQuery ();
        QSqlQueryModel * model = new  QSqlQueryModel ();
        q1->prepare("SELECT * FROM reclamation ORDER BY ID desc");
        q1->exec();
        model->setQuery(*q1);
        return model;
}

QSqlQueryModel * reclamation::tri3()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM reclamation ORDER BY NOM");
    q->exec();
    model->setQuery(*q);
    return model;
}



void reclamation::clearTable(QTableView *table){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);}

void reclamation::searchRegexp(QTableView *table, int x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from reclamation where regexp_like(id,:id);");
   query->bindValue(":id",x);

   if(x==0){qDebug("tawa 0");

   query->prepare("select * from reclamtion;");   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();

}



