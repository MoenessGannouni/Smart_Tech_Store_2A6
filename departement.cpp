#include "departement.h"

departement::departement()
{
     id='0';
     Nom="";


}
departement::departement(int id,QString Nom)
{
    this-> id=id;
    this-> Nom=Nom;

}
bool departement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  departement  (id,nom) VALUES (:id,:Nom)");
    query.bindValue(":id",id);
    query.bindValue(":Nom",Nom);
    return query.exec();
}
QSqlQueryModel * departement::afficher()
{
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM departement");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));


        return model;
    }

}
bool departement::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from departement where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}

bool  departement:: modifier(int ID)
{
    QSqlQuery query;
    QString idD=QString::number(ID);
    query.prepare("update departement set id = :id ,  nom= :Nom   where id = :id ");
    query.bindValue(":id",idD);
    query.bindValue(":Nom",Nom);

    return query.exec();
}
QSqlQueryModel *departement::trier() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM departement order by nom ASC");
           q->exec();
           model->setQuery(*q);
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));


           return model;
     //ml kbir l sghir
          /* QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM permisconstruction order by codepostale ASC");
                  q->exec();
                  model->setQuery(*q);
                  return model;*/
}
QSqlQueryModel *departement::recherche(QString id)
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from departement where nom LIKE '"+id+"%' ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));


return model;
}
