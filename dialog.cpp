#include "dialog.h"
#include "ui_dialog.h"
#include "client.h"
#include "historique.h"
#include <QMessageBox>
#include <QDate>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->affichageClient->setModel(Etmp.afficher());
     combo();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ajouterClient_4_clicked()
{
        int res=ui->ajouter_cin_4->text().toInt();
        QString nom=ui->ajouter_nom_4->text();
        QString prenom=ui->ajouter_prenom_4->text();
        QString adresse=ui->ajouter_adresse_4->text();
        QString adresse_mail=ui->ajouter_adresseMail_4->text();
        QString date_naissance=ui->ajouter_dateN_4->text();


        Clients c(res,nom, prenom, adresse, adresse_mail, date_naissance);

        bool test=c.ajouter();

        if(test)
        {
            ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
        }
}



void Dialog::on_supprimerClient_4_clicked()
{
    int cin =ui->cinClient_8->text().toInt();
    bool test=Etmp.supprimer(cin);

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"), QObject::tr("Suppression effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Suppression non effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);
    }
}



void Dialog::on_modifierClient_4_clicked()
{
    int res=ui->cinClient_8->text().toInt();
    QString nom=ui->modifier_nom_4->text();
    QString prenom=ui->modifier_prenom_4->text();
    QString adresse=ui->modifier_adresse_4->text();
    QString adresse_mail=ui->modifier_adresseMail_4->text();
    QString date_naissance=ui->modifier_dateN_4->text();


    Clients c(res,nom, prenom, adresse, adresse_mail, date_naissance);

    bool test=c.modifier();

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }

}

void Dialog:: combo()
{
    QSqlQueryModel *m=new QSqlQueryModel();
              QSqlQuery *querry=new QSqlQuery();
              querry->prepare("SELECT cin FROM client");
              querry->exec();
              m->setQuery(*querry);
              ui->cin_client->setModel(m);
}

void Dialog::on_ajouterProduit_clicked()
{
    int cin= ui->cin_client->currentText().toInt();
    QString nom_produit= ui->nom_produit->text();
    QString date_achat= ui->date_achat->text();

    historique h(cin,nom_produit,date_achat);

    bool test=h.ajouterP();

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }
}

void Dialog::on_supprimerAchat_clicked()
{
    int id = ui->id_Achat->text().toInt();
    bool test=Etmp_h.supprimerP(id);

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Suppression non effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);
    }
}
