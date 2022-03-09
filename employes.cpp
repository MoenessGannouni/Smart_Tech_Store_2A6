#include "employes.h"

Employes::Employes()
{
     CIN='0';
     Nom="";
     Prenom= "" ;
     Adresse= "";
     Adressemail= "";
     Date_naissance="";
     Departement="";
     Date_embauche="";

}
Employes::Employes(int CIN,QString Nom,QString Prenom,QString Adresse,QString Adressemail,QString Date_naissance,QString Departement,QString Date_embauche)
{
    this-> CIN=CIN;
    this-> Nom=Nom;
    this-> Prenom= Prenom ;
    this-> Adresse= Adresse;
    this-> Adressemail= Adressemail;
    this-> Date_naissance=Date_naissance;
    this-> Departement=Departement;
    this-> Date_embauche=Date_embauche;

}
bool Employes::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO  employés  (CIN,nom, prénom,adresse,adresse_mail,date_de_naissance,département,date_dembauche) VALUES (:CIN,:Nom, :Prenom, :Adresse, :Adressemail, :Date_naissance, :Departement, :Date_embauche)");
    query.bindValue(":CIN",CIN);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Adresse",Adresse);
    query.bindValue(":Adressemail",Adressemail);
    query.bindValue(":Date_naissance",Date_naissance);
    query.bindValue(":Departement",Departement);
    query.bindValue(":Date_embauche",Date_embauche);
    return query.exec();
}
QSqlQueryModel * Employes::afficher()
{
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM employés");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_mail"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_naissance"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("département"));
              model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_dembauche"));

        return model;
    }

}
bool Employes::supprimer(int CIN)
{
    QSqlQuery query;
    query.prepare("delete from employés where CIN = :CIN") ;

    query.bindValue(":CIN",CIN);

    return query.exec();
}

bool  Employes:: modifier(int ID)
{
    QSqlQuery query;
    QString cinE=QString::number(ID);
    query.prepare("update employés set CIN = :CIN ,  nom= :Nom , prénom = :Prenom , adresse = :Adresse , adresse_mail = :Adressemail , date_de_naissance = :Date_naissance , département = :Departement , date_dembauche = :Date_embauche  where CIN = :CIN ");
    query.bindValue(":CIN",cinE);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Adresse",Adresse);
    query.bindValue(":Adressemail",Adressemail);
    query.bindValue(":Date_naissance",Date_naissance);
    query.bindValue(":Departement",Departement);
    query.bindValue(":Date_embauche",Date_embauche);
    return query.exec();
}
QSqlQueryModel *Employes::trier() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM employés order by nom ASC");
           q->exec();
           model->setQuery(*q);
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_mail"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_naissance"));
           model->setHeaderData(6, Qt::Horizontal, QObject::tr("département"));
           model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_dembauche"));

           return model;
     //ml kbir l sghir
          /* QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM permisconstruction order by codepostale ASC");
                  q->exec();
                  model->setQuery(*q);
                  return model;*/
}
QSqlQueryModel *Employes::recherche(QString id)
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employés where CIN LIKE '"+id+"%' or nom LIKE '"+id+"%' or prénom LIKE '"+id+"%' or département LIKE '"+id+"%'");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("département"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_dembauche"));

return model;
}
