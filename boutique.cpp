#include "boutique.h"
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
#include<QPdfWriter>
Boutique::Boutique()
{

}
Boutique::Boutique(int Id,QString Nom,QString Adresse){
    ID=Id;
    NOM=Nom;
    ADRESSE=Adresse;

}
bool Boutique::ajouter(){
    QSqlQuery query;
    QString res=QString::number(ID);
    query.prepare("INSERT INTO BOUTIQUE(ID,NOM,ADRESSE)""VALUES(:Id,:Nom,:Adresse)");
    query.bindValue(":Id",res);
    query.bindValue(":Nom",NOM);
    query.bindValue(":Adresse",ADRESSE);

    return query.exec();
}
QSqlQueryModel *Boutique::afficher(){
     QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery("select * FROM BOUTIQUE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
         return model;
}
bool Boutique::supprimer(int ID){
    QSqlQuery query;
     QString res=QString::number(ID);
     query.prepare("DELETE FROM BOUTIQUE WHERE ID=:Id");
     query.bindValue(":Id",res);
     return query.exec();
}
bool Boutique::modifier(int ID){
    QSqlQuery query;
     QString res=QString::number(ID);
     query.prepare("UPDATE BOUTIQUE SET NOM=:NOM,ADRESSE=:ADRESSE WHERE ID=:ID");
     query.bindValue(":ID",res);
     query.bindValue(":NOM",NOM);
     query.bindValue(":ADRESSE",ADRESSE);
     return query.exec();
}
QSqlQueryModel* Boutique::recherche(int ID)
{
    QSqlQueryModel *model=new QSqlQueryModel();
                QString res=QString ::number(ID);
            model->setQuery("select * from BOUTIQUE where ID='"+res+"'");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
   return model;

}
QSqlQueryModel* Boutique::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from BOUTIQUE order by ID");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));

   return model;

}
void  Boutique::genererPDF(){


                     QPdfWriter pdf("C:/Users/21621/Desktop/nour.pdf");
                     QPainter painter(&pdf);

                    int i = 4000;
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"Liste Des Boutiques");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                        // painter.drawText(1100,2000,afficheDC);


                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);


                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"ID");
                         painter.drawText(1300,3300,"NOM");
                         painter.drawText(2100,3300,"ADRESSE");

                         QSqlQuery query;
                         query.prepare("select * from BOUTIQUE");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());

                            i = i + 500;
                         }
}
