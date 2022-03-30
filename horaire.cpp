#include "horaire.h"
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>

Horaire::Horaire()
{

}
Horaire::Horaire(int Id,QString Heureo,QString Heuref){
    ID=Id;
    HEUREO=Heureo;
    HEUREF=Heuref;
}
bool Horaire::ajouter(){
    QSqlQuery query;
    QString res=QString::number(ID);
    query.prepare("INSERT INTO HORAIRE(ID,HEUREOUVERTURE,HEUREFERMETURE)""VALUES(:Id,:Heureo,:Heuref)");
    query.bindValue(":Id",res);
    query.bindValue(":Heureo",HEUREO);
    query.bindValue(":Heuref",HEUREF);
    return query.exec();
}
QSqlQueryModel *Horaire::afficher(){
     QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery("select * FROM HORAIRE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREOUVERTURE"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREFERMETURE"));
         return model;
}
bool Horaire::supprimer(int ID){
    QSqlQuery query;
     QString res=QString::number(ID);
     query.prepare("DELETE FROM HORAIRE WHERE ID=:Id");
     query.bindValue(":Id",res);
     return query.exec();
}
bool Horaire::modifier(int ID){
    QSqlQuery query;
     QString res=QString::number(ID);
     query.prepare("UPDATE HORAIRE SET HEUREOUVERTURE=:HEUREO,HEUREFERMETURE=:HEUREF WHERE ID=:ID");
     query.bindValue(":ID",res);
     query.bindValue(":HEUREO",HEUREO);
     query.bindValue(":HEUREF",HEUREF);
     return query.exec();
}
