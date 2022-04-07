#include "fournisseur.h"
#include <QDebug>
#include <QString>
fournisseur::fournisseur()
{
    num=0;
    nom="";
    mail="";
    type="";
    adresse="";
}

fournisseur::fournisseur(int num, QString nom, QString mail, QString type,QString adresse)
{
    this->num=num;
    this->nom=nom;
    this->mail=mail;
    this->type=type;
    this->adresse=adresse;
}

int fournisseur::get_num(){return  num;}
QString fournisseur::get_nom(){return  nom;}
QString fournisseur::get_mail(){return  mail;}
QString fournisseur::get_type(){return  type;}
QString fournisseur::get_adresse(){return  adresse;}

bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString res1= QString::number(num);

        query.prepare("INSERT INTO fournisseur (TELEPHONE, NOM, MAIL,TYPE,ADRESSE) "
                            "VALUES (:num, :nom, :mail, :type, :adresse)");
        query.bindValue(":num", res1);
        query.bindValue(":nom", nom);
        query.bindValue(":mail", mail);
        query.bindValue(":type", type);
        query.bindValue(":adresse", adresse);
return query.exec();
}

bool fournisseur::supprimer(int num)
{
    QSqlQuery query;
    QString res1= QString::number(num);
    query.prepare("Delete from fournisseur where TELEPHONE = :num ");
    query.bindValue(":num", res1);
return    query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from fournisseur");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TELEPHONE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
return model;
}

QSqlQueryModel *fournisseur::cherch_four(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select TELEPHONE, NOM,  MAIL from FOURNISSEUR where NOM='"+nom+"'");
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
return model;
}
bool fournisseur::modifier(int num ,QString nom)
{
    QSqlQuery query;
    QString res= QString::number(num);
    query.prepare("update fournisseur set TELEPHONE=:num  where NOM= :nom");
    query.bindValue(":nom", nom);
    query.bindValue(":num", res);
return query.exec();
}










