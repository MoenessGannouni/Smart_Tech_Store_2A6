#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QtWidgets>
#include "smtp.h"
#include <QString>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
  son=new QSound("C:/Users/OneDrive/Desktop/gestion fournisseur - Copie/nada.wav");


     ui->tabfournisseur->setModel(tmpfournisseur.afficher());
     ui->tabcommande->setModel(tmpcommande.afficher());



}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_vehicule_clicked()
{
    int num = ui->num_four->text().toInt();

     QString nom= ui->nom_four->text();
     QString mail= ui->mail_four->text();
     QString type= ui->type_four->text();
     QString adresse= ui->adresse_four->text();

  fournisseur f(num,nom ,mail,type,adresse);
  bool test=f.ajouter();
    if(test)
{
      ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                       notifyIcon->show();
                       notifyIcon->setIcon(QIcon("icone.png"));
                       notifyIcon->showMessage("GESTION FOURNISSEUR ","Fournisseur Ajouté",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
        QObject::tr("fournisseur ajouté.\n"
                     "Click Cancel to exit."), QMessageBox::Ok);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
      QObject::tr("Erreur !.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_vehicule_2_clicked()
{
    int num = ui->num_fours->text().toInt();
        bool test=tmpfournisseur.supprimer(num);
         if(test)
         {
            ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                             notifyIcon->show();
                             notifyIcon->setIcon(QIcon("icone.png"));
                             notifyIcon->showMessage("GESTION FOURNISSEUR ","Fournisseur supprimé",QSystemTrayIcon::Information,15000);


            QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
            QObject::tr("fournisseur supprimé.\n"
                        "Click Cancel to exit."), QMessageBox::Ok);
          }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_ajouter_vehicule_2_clicked()
{
    int nbcommande = ui->nb_com->text().toInt();
    int quantite= ui->quantite_com->text().toInt();
    QString type= ui->type_com->text();
  commande c (nbcommande,quantite ,type);
  bool test=c.ajouter();
    if(test)
{
      ui->tabcommande->setModel(tmpcommande.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                       notifyIcon->show();
                       notifyIcon->setIcon(QIcon("icone.png"));
                       notifyIcon->showMessage("GESTION COMMANDE ","Commande Ajouté",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
        QObject::tr("commande ajouté.\n"
                    "Click Cancel to exit."), QMessageBox::Ok);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
      QObject::tr("Erreur !.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_panne_clicked()
{
    long nbcommande=ui->nb_com_sup->text().toLong();
    bool test=tmpcommande.supprimer(nbcommande);
     if(test)
     {
        ui->tabcommande->setModel(tmpcommande.afficher());//refresh
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                         notifyIcon->show();
                         notifyIcon->setIcon(QIcon("icone.png"));
                         notifyIcon->showMessage("GESTION COMMANDE ","Commande supprimé",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
        QObject::tr("Commande supprimé.\n"
                    "Click Cancel to exit."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
        QObject::tr("Erreur !.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_ajouter_vehicule_3_clicked()
{
    {
       int nbcommande = ui->nbmodif->text().toInt();
       QString type = ui->typemodif->text();

          bool test=tmpcommande.modifier(nbcommande,type);
                if(test)
            {
                ui->tabcommande->setModel(tmpcommande.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("modifier une commande"),
                QObject::tr("commande modifier.\n"
                            "Click Cancel to exit."), QMessageBox::Ok);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("modifier une commande"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
       }
}


void MainWindow::on_cherchercom_clicked()
{
    QString nbcommande = ui->cher2->text();
    ui->tabpanne_3->setModel(tmpcommande.cherch_com(nbcommande));
}
void MainWindow::on_chercherfour_clicked()
{
    QString nom = ui->cher1->text();
    ui->tabpanne_2->setModel(tmpfournisseur.cherch_four(nom));
}

void MainWindow::on_modiffour_clicked()
{
    {
        int num = ui->numfm->text().toInt();
        QString nom = ui->nomfm->text();



            bool test=tmpfournisseur.modifier(num,nom);
            if(test)
            {
                ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                QObject::tr("fournisseur modifier.\n"
                            "Click Cancel to exit."), QMessageBox::Ok);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_imprimer_clicked()
{


        QPrinter printer;
            printer.setPrinterName("Imprimer");
            QPrintDialog dialog(&printer,this);
            dialog.exec();
    }




void MainWindow::on_trie1_clicked()
{
    ui->tabtrier->setModel(tmpcommande.afficher_tri_nb());
}

void MainWindow::on_trie2_clicked()
{
    ui->tabtrier->setModel(tmpcommande.afficher_tri_type());
}

void MainWindow::on_play_clicked()
{
    son->play();

}

void MainWindow::on_stop_clicked()
{
    son->stop();
}

void MainWindow::on_pushButton_clicked()
    {
         ui->label_9->setText("supplier number");
         ui->label_10->setText("supplier name") ;
         ui->label_11->setText("supplier mail") ;
         ui->label_21->setText("supplier type") ;
         ui->label_22->setText("supplier address") ;
         ui->ajouter_vehicule->setText("add") ;

         ui->supprimer_vehicule->setText("delete") ;
         ui->label_5->setText("supplier number") ;
         ui->modiffour->setText("edit") ;

         ui->label_19->setText("supplier num") ;
         ui->label_20->setText("supplier name") ;
         ui->label_12->setText("supplier name") ;
         ui-> chercherfour->setText("search") ;


         ui-> label_37->setText("order number") ;
         ui-> cherchercom->setText("search") ;

         ui-> label_2->setText("address") ;
         ui-> label_3->setText("subject") ;
         ui-> label_4->setText("text") ;
         ui-> pushButton_send_mail->setText("send") ;

         ui->imprimer->setText("print") ;
         ui->label_13->setText("number of ordered items") ;
         ui->label_15->setText("quantity") ;
         ui->label_16->setText("type") ;
         ui->supprimer_panne->setText("delete") ;

         ui->label_14->setText("number of ordered items") ;
         ui->ajouter_vehicule_3->setText("edit") ;

         ui->label_17->setText("number of ordered items") ;
         ui->label_18->setText("type of ordered items") ;

         ui->trie1->setText("sort ordered item's number") ;
         ui->trie2->setText("sort the type of order") ;
         ui->ajouter_vehicule_2->setText("add") ;

    }

    void MainWindow::on_traduire_2_clicked()
    {      ui->label_9->setText("número de proveedor");
           ui->label_10->setText("nombre de proveedor") ;
           ui->label_11->setText("mail de proveedor") ;
           ui->label_21->setText("tipo de proveedor") ;
           ui->label_22->setText("dirección del proveedor") ;

           ui->ajouter_vehicule->setText("añadir") ;
           ui->supprimer_vehicule->setText("Eliminar") ;
           ui->label_5->setText("número de proveedor") ;
           ui->modiffour->setText("editar") ;
           ui->label_19->setText("número de proveedor") ;
           ui->label_20->setText("nombre de proveedor") ;
           ui->label_12->setText("nombre de proveedor") ;

           ui-> label_37->setText("nùmero de orden") ;
           ui-> cherchercom->setText("bùsqueda") ;

           ui-> label_2->setText("dirección") ;
           ui-> label_3->setText("tema") ;
           ui-> label_4->setText("texto") ;
           ui-> pushButton_send_mail->setText("enviar") ;

           ui-> chercherfour->setText("buscar") ;
           ui->imprimer->setText("imprimir") ;
           ui->label_13->setText("número de artículos pedidos") ;
           ui->label_15->setText("cantidad") ;
           ui->label_16->setText("tipo") ;
           ui->supprimer_panne->setText("eliminar") ;
           ui->label_14->setText("número de artículos pedidos") ;
           ui->ajouter_vehicule_3->setText("editar") ;
           ui->label_17->setText("número de artículos pedidos") ;
           ui->label_18->setText("tipo de artículos pedidos") ;

           ui->trie1->setText("ordenar el número de artículos ordenados") ;
           ui->trie2->setText("ordenar el tipo  de artículos ordenados") ;
           ui->ajouter_vehicule_2->setText("añadir") ;


}

    void MainWindow::on_pushButton_send_mail_clicked()
    {
        smtp = new Smtp("Techfournisseur@gmail.com" , "nada 1999", "smtp.gmail.com",465);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        msg=ui->message_mail->toPlainText();

       smtp->sendMail("departement fournisseurs",ui->a_mail->text(),ui->objet_mail->text(),msg);

        QMessageBox::information(nullptr, QObject::tr("SENT"),
                                 QObject::tr("Email Sent Successfully.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
