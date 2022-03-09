#include "finance.h"
#include "ui_finance.h"
#include <QPixmap>
#include"calculatrice.h"
#include"blocnote.h"
#include"revenue.h"
#include"dependance.h"
#include <QPrinter>
#include <QPrintDialog>
finance::finance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finance)
{

   ui->setupUi(this);

//animation

   QPixmap pix("C:/Users/ncib/Desktop/fedincib_tacheqt/0.png");
       int w=ui->label_pic3->width();
       int h=ui->label_pic3->height()+800;

   ui->label_pic3->setPixmap(pix.scaled(w,h));
   QPropertyAnimation *animation = new QPropertyAnimation(ui->label_pic3, "geometry");
   animation->setDuration(10000);
   animation->setStartValue(ui->label_pic3->geometry());
   animation->setEndValue(QRect(1500, 90,291 ,81));

   QEasingCurve curve;
   curve.setType(QEasingCurve::OutBounce);
   animation->setEasingCurve(curve);

   connect(animation, SIGNAL(finished()), animation, SLOT(deleteLater()));

   animation->start();

   timer= new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
   timer->start(10000);

//fin animation


    //affichage

    ui->affichage_revenue->setModel( tmprevenue.afficher());
    ui->affichage_dependance->setModel( tmpdependance.afficher());

    //fin affichage



}

finance::~finance()
{
    delete ui;
}

void finance::on_pushButton_calcul_clicked()
{
    calculatrice w;

    w.exec();
}

void finance::on_pushButton_blocnote_clicked()
{
    blocnote w;

    w.exec();
}

void finance::on_ajouter_revenue_clicked()
{
            int id=ui->idajout_revenue->text().toInt();
            int montant=ui->montant_ajout_revenue->text().toInt();
            int quantite=ui->quantite_ajout_revenue->text().toInt();
            QString produit=ui->produit_ajout_revenue->text();
            QString datee=ui->date_ajout_revenue->text();
            if( (id == 0) || (montant == 0) || (quantite == 0) || (produit == "")  || (datee == ""))
                        {
                         QMessageBox::information(nullptr,QObject::tr("Champ vide"),
                                                    QObject::tr("l'un des champs est vide!\n"
                                                                "click Cancel to exit"),QMessageBox::Cancel);
                       }
            else {
            revenue tmprevenue(id,montant,produit,quantite,datee);

            bool test=tmprevenue.ajouter();

            if(test){
                ui->affichage_revenue->setModel(tmprevenue.afficher());
                QMessageBox::information(nullptr,"Ajout revenue","revenue ajouté avec succés");

            }
            else
                    QMessageBox::warning(nullptr,"Error","revenue non ajouté");
            }

}

void finance::on_supprimer_revenue_clicked()
{
    int id =ui->id_afficher_revenue->text().toInt();
    bool test=tmprevenue.supprimer(id);
    if(test)
       {ui->affichage_revenue->setModel(tmprevenue.afficher());
    //QMessageBox::information(nullptr,"suppression revnue","revnue supprimer avec succés");
    }

    else
            QMessageBox::warning(nullptr,"Error","Revenue non supprimer");


}



void finance::on_ajout_dependance_clicked()
{
    int id=ui->id_ajout_dependance->text().toInt();
    int montant=ui->montant_ajout_dependance->text().toInt();

    QString type=ui->type_ajout_dependance->text();
    QString datee=ui->date_ajout_dependance->text();
    if( (id == 0) || (montant == 0) ||  (type == "")  || (datee == ""))
                {
                 QMessageBox::information(nullptr,QObject::tr("Champ vide"),
                                            QObject::tr("l'un des champs est vide!\n"
                                                        "click Cancel to exit"),QMessageBox::Cancel);
               }
else {
    dependance tmpdependance(id,montant,type,datee);

    bool test=tmpdependance.ajouter();
    if(test){
        ui->affichage_dependance->setModel(tmpdependance.afficher());
        QMessageBox::information(nullptr,"Ajout dependance","dependance ajouté avec succés");

    }
    else
            QMessageBox::warning(nullptr,"Error","dependance non ajouté");
}
}

void finance::on_tri_prix_revenue_clicked()
{
    ui->affichage_revenue->setModel( tmprevenue.tri_montant());
}

void finance::on_recherche_revenue_clicked()
{
     ui->affichage_revenue->setModel( tmprevenue.recherche_id(ui->id_recherche_revenue->text()));
}


//animation
void finance::myfunction()
{
    QPixmap pix1("C:/Users/ncib/Desktop/fedincib_tacheqt/1.png");
        int g=ui->label_pic4->width();
        int f=ui->label_pic4->height()+800;

        ui->label_pic4->setPixmap(pix1.scaled(g,f));
   timer->stop();
}
//animation


void finance::on_supprimer_dependance_clicked()
{
    int id =ui->id_affichage_dependance->text().toInt();
    bool test=tmpdependance.supprimer(id);
    if(test)
       {ui->affichage_dependance->setModel(tmpdependance.afficher());
   // QMessageBox::information(nullptr,"suppression dependance","dependance supprimer avec succés");
    }

    else
            QMessageBox::warning(nullptr,"Error","dependance non supprimer");

}

void finance::on_recherche_dependance_clicked()
{
     ui->affichage_dependance->setModel( tmpdependance.recherche_id(ui->id_recherche_dependance->text()));
}

void finance::on_tri_prix_dependance_clicked()
{
    ui->affichage_dependance->setModel( tmpdependance.tri_montant());
}

void finance::on_modifier_revnue_clicked()
{
    int id=ui->id_afficher_revenue->text().toInt();
    int montant=ui->montant_afficher_revenue->text().toInt();
    int quantite=ui->quantite_afficher_revenue->text().toInt();
    QString produit=ui->produit_afficher_revenue->text();
    QString datee=ui->date_afficher_revenue->text();

    revenue tmprevenue(id,montant,produit,quantite,datee);

    bool test=tmprevenue.modifier();
    if(test){
        ui->affichage_revenue->setModel(tmprevenue.afficher());
       // QMessageBox::information(nullptr,"revenue modifie","revenue modifie avec succés");

    }
    else
            QMessageBox::warning(nullptr,"Error","revenue non modifie");

}

void finance::on_modifier_dependance_clicked()
{
    int id=ui->id_affichage_dependance->text().toInt();
    int montant=ui->montant_affichage_dependance->text().toInt();
    QString type=ui->type_affichage_dependance->text();
    QString datee=ui->date_affichage_dependance->text();

    dependance tmpdependance(id,montant,type,datee);

    bool test=tmpdependance.modifier();
    if(test){
        ui->affichage_dependance->setModel(tmpdependance.afficher());
      //  QMessageBox::information(nullptr,"dependance modifie","dependance modifie avec succés");

    }
    else
            QMessageBox::warning(nullptr,"Error","dependance non modifie");
}

void finance::on_tri_date_revenue_clicked()
{
     ui->affichage_revenue->setModel( tmprevenue.tri_date());
}

void finance::on_tri_date_dependance_clicked()
{
    ui->affichage_dependance->setModel( tmpdependance.tri_date());
}

void finance::on_imprimer_revenue_clicked()
{
    // Allows for interacting with printer
        QPrinter printer;

        // You'll put your printer name here
        printer.setPrinterName("Printer Name");

        // Create the print dialog and pass the name and parent
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }

        // Send the text to the printer
        ui->affichage_revenue->render(&printer);
}

void finance::on_imprimer_dependance_clicked()
{

    // Allows for interacting with printer
        QPrinter printer;

        // You'll put your printer name here
        printer.setPrinterName("Printer Name");

        // Create the print dialog and pass the name and parent
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }

        // Send the text to the printer
        ui->affichage_dependance->render(&printer);
}



