#include "client.h"

Clients::Clients(int cin, QString nom, QString prenom, QString adresse, QString adresse_mail, QString date_naissance)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->adresse_mail=adresse_mail;
    this->date_naissance=date_naissance;
}

bool Clients::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    query.prepare("insert into client(cin,nom,prenom,adresse,adresse_mail,date_naissance)" "values(:cin,:nom,:prenom,:adresse,:adresse_mail,:date_naissance)");

    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":adresse_mail",adresse_mail);
    query.bindValue(":date_naissance",date_naissance);

    return query.exec();
}

QSqlQueryModel * Clients::afficher()
{
    QSqlQueryModel  * model=new QSqlQueryModel();
    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date naissance"));

    return model;
}

bool Clients::supprimer(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);

    query.prepare("delete from client where cin= :cin");
    query.bindValue(":cin",res);

    return query.exec();
}

bool Clients::modifier()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    query.prepare("UPDATE client SET nom=:nom, prenom=:prenom, adresse=:adresse, adresse_mail=:adresse_mail, date_naissance=:date_naissance WHERE cin=:cin" );

    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":adresse_mail",adresse_mail);
    query.bindValue(":date_naissance",date_naissance);

    return query.exec();
}


// Metiers

QSqlQueryModel * Clients::rechercherNom(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client where nom like '" +nom+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date naissance"));

    return model;
}

QSqlQueryModel * Clients::triNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client order by nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date naissance"));

    return model;
}

