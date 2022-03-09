#include "dialog.h"
#include "ui_dialog.h"
#include"employes.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->affichageemp->setModel(tmpemployes.afficher());
     ui->affichage_dep->setModel(tmpdepartement.afficher());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ajouteremp_clicked()

    {
                int CIN=ui->CIN->text().toInt();
                QString Nom=ui->Nomemp->text();
                QString Prenom=ui->Prenomemp->text();
                QString Adresse=ui->Adresseemp->text();
                QString Adressemail=ui->Adresse_mailemp->text();
                QString Date_naissance =ui->Datedenaissanceemp->text();
                QString Departement=ui->Departementemp->text();
                QString Date_dembauche=ui->dateembaucheemp->text();

                Employes tmpemployes(CIN, Nom, Prenom, Adresse, Adressemail, Date_naissance, Departement, Date_dembauche);

                bool test=tmpemployes.ajouter();
                if(test){
                    ui->affichageemp->setModel(tmpemployes.afficher());
                    QMessageBox::information(nullptr,"Ajout Employes","Employe ajouté avec succés");

                }
                else
                        QMessageBox::warning(nullptr,"Error","Employe non ajouté");

    }



void Dialog::on_supprimeremp_clicked()
{
    int CIN =ui->CINemp_afficher->text().toInt();
    bool test=tmpemployes.supprimer(CIN);
    if(test)
       {ui->affichageemp->setModel(tmpemployes.afficher());
   }
}





void Dialog::on_modifieremp_clicked()
{
    int CIN =ui->CINemp_afficher->text().toInt();
    QString Nom=ui->Nomemp_afficher->text();
    QString Prenom=ui->Prenomemp_afficher->text();
    QString Adresse=ui->Adresseemp_afficher->text();
    QString Adressemail=ui->Adressemailemp_afficher->text();
    QString Date_naissance =ui->Datedenaissanceemp_afficher->text();
    QString Departement=ui->Departementemp_afficher->text();
    QString Date_dembauche=ui->dateembaucheemp_afficher->text();

    Employes tmpemployes(CIN, Nom, Prenom, Adresse, Adressemail, Date_naissance, Departement, Date_dembauche);

    bool test=tmpemployes.modifier(CIN);
    if(test){
        ui->affichageemp->setModel(tmpemployes.afficher());
        QMessageBox::information(nullptr,"Modifier Employes","Employe modifié avec succés");

    }
    else
            QMessageBox::warning(nullptr,"Error","Employe non modifié");

}

void Dialog::on_affichageemp_activated(const QModelIndex &index)
{
    QString SELECT=ui->affichageemp->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from employés where CIN LIKE '"+SELECT+"%' or nom LIKE '"+SELECT+"%' or prénom LIKE '"+SELECT+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->CINemp_afficher->setText(query.value(0).toString());
                ui->Nomemp_afficher->setText(query.value(1).toString());
                ui->Prenomemp_afficher->setText(query.value(2).toString());
                ui->Adresseemp_afficher->setText(query.value(3).toString());
                ui->Adressemailemp_afficher->setText(query.value(4).toString());
                ui->Datedenaissanceemp_afficher->setText(query.value(5).toString());
                ui->Departementemp_afficher->setText(query.value(6).toString());
                ui->dateembaucheemp_afficher->setDate(query.value(7).toDate());


            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void Dialog::on_imprimer_emp_clicked()
{
    QPrinter rd;
            QPrintDialog d(&rd,this);
            d.setWindowTitle("Print Liste Employés");
            d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
            if (d.exec() != QDialog::Accepted)
                return ;
}







void Dialog::on_pdf_em_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A3);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM employés ");
    q.exec();
    QString pdf="<br> <h1  style='color:red'>LISTE EMPLOYES  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th> PRENOM </th><th> ADRESSE </th> <th>EMAIL </th><th>DATE DE NAISSANCE </th><th>DEPARTEMENT </th><th>DATE EMBAUCHE </th></tr>" ;


    while ( q.next()) {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td>" +q.value(1).toString() +"</td> <td>" +q.value(2).toString() +"</td><td>" +q.value(3).toString() +"</td> <td>" +q.value(4).toString() +"</td><td>" +q.value(5).toString() +"</td><td>" +q.value(6).toString() +"</td><td>" +q.value(7).toString() +"</td></td>" ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void Dialog::on_tri_emp_clicked()
{
    ui->affichageemp->setModel(tmpemployes.trier());

}

void Dialog::on_rechercheemp_clicked()
{
    QString id =ui->id_rechercheemp->text();
    ui->affichageemp->setModel(tmpemployes.recherche(id));

}

void Dialog::on_ajouterdep_clicked()
{
    int id=ui->iddep->text().toInt();
    QString Nom=ui->nomdep->text();


    departement tmpdepartement(id, Nom);

    bool test=tmpdepartement.ajouter();
    if(test){
        ui->affichage_dep->setModel(tmpdepartement.afficher());
        QMessageBox::information(nullptr,"Ajout Departement","Departement ajouté avec succés");

    }
    else
            QMessageBox::warning(nullptr,"Error","Departement non ajouté");
}

void Dialog::on_modifier_dep_clicked()
{
    int id=ui->id_affichage_dep->text().toInt();
    QString Nom=ui->Nom_affichage_dep->text();



    departement tmpdepartement(id, Nom);

    bool test=tmpdepartement.modifier(id);
    if(test){
        ui->affichage_dep->setModel(tmpdepartement.afficher());
        QMessageBox::information(nullptr,"Modifier Departement","Departement modifié avec succés");

    }
    else
            QMessageBox::warning(nullptr,"Error","Departement non modifié");
}

void Dialog::on_affichage_dep_activated(const QModelIndex &index)
{
    QString SELECT=ui->affichage_dep->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from departement where nom LIKE '"+SELECT+"%' or id LIKE '"+SELECT+"%' ");
          if(query.exec())
          {
            while(query.next())
            {
                ui->id_affichage_dep->setText(query.value(0).toString());
                ui->Nom_affichage_dep->setText(query.value(1).toString());



            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void Dialog::on_supprimer_dep_clicked()
{
    int id =ui->id_affichage_dep->text().toInt();
    bool test=tmpdepartement.supprimer(id);
    if(test)
       {
        ui->affichage_dep->setModel(tmpdepartement.afficher());
   }
}

void Dialog::on_recherche_dep_clicked()
{
    QString id =ui->id_recherche_dep->text();
    ui->affichage_dep->setModel(tmpdepartement.recherche(id));
}

void Dialog::on_tri_dep_clicked()
{
    ui->affichage_dep->setModel(tmpdepartement.trier());

}
