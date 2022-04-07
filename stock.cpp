#include "stock.h"
#include "excel.h"
#include "ui_stock.h"
#include <QPixmap>
#include <QtWidgets>
#include"excel.h"
#include"statistique.h"
#include"ui_statistique.h"
#include"produit.h"
#include"reclamation.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>




stock::stock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stock)
{

   ui->setupUi(this);

   QPixmap pix("C:/Users/user/Desktop/stockcrud/0.png");
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


    //affichage

    ui->affichage_produit->setModel( tmpproduit.afficher());

    //fin affichage



}

stock::~stock()
{
    delete ui;
}


void stock::on_ajouter_produit_clicked()
{


            QString nom=ui->nomajout_produit->text();
            int id=ui->idajout_produit->text().toInt();
            int prix=ui->prix_ajout_produit->text().toInt();
            int quantite=ui->quantite_ajout_produit->text().toInt();
            QString categorie=ui->categorie_ajout_produit->text();
            QString datee=ui->date_ajout_produit->text();

            produit tmpproduit(nom,id,prix,quantite,categorie,datee);

            bool test=tmpproduit.ajouter();
            if(test){
                ui->affichage_produit->setModel(tmpproduit.afficher());
                QMessageBox::information(nullptr,"Ajout produit","produit ajouté avec succés");

            }
            else
                    QMessageBox::warning(nullptr,"Error","produit non ajouté");

}

void stock::on_modifier_produit_clicked()
{
    {

        QString nom=ui->nom_afficher_produit->text();
        int id=ui->id_afficher_produit->text().toInt();
        int prix=ui->prix_afficher_produit->text().toInt();
        int quantite=ui->quantite_afficher_produit->text().toInt();
        QString categorie=ui->categorie_afficher_produit->text();
        QString datee=ui->date_afficher_produit->text();
        produit tmpproduit(nom,id,prix,quantite,categorie,datee);
         bool test=tmpproduit.modifier(id);
         if(test)
       {

             ui->affichage_produit->setModel(tmpproduit.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                         QObject::tr("produit modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier un produit"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
}
void stock::on_supprimer_produit_clicked()
{
    int id =ui->id_afficher_produit->text().toInt();
    bool test=tmpproduit.supprimer(id);
    if(test)
       {ui->affichage_produit->setModel(tmpproduit.afficher());
    QMessageBox::information(nullptr,"suppression produit","produit supprimer avec succés");}

    else
            QMessageBox::warning(nullptr,"Error","produit non supprimer");


}

void stock::on_tri_prix_produit_clicked()
{
    ui->affichage_produit->setModel( tmpproduit.tri_prix());
}
void stock::on_tri_id_produit_clicked()
{
    ui->affichage_produit->setModel( tmpproduit.tri_id());
}

void stock::on_recherche_produit_clicked()
{
     ui->affichage_produit->setModel( tmpproduit.recherche_id(ui->id_recherche_produit->text()));
}


void stock::on_EXCEL_clicked()
{

   QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->affichage_produit);

    //colums to export
    obj.addField(0, "ID", "char(20)");
    obj.addField(1, "NOM", "char(20)");
    obj.addField(2, "PRIX", "char(20)");
    obj.addField(3, "QUANTITE", "char(20)");
    obj.addField(4, "CATEGORIE", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
     }
}

void stock::myfunction()
{
    QPixmap pix1("C:/Users/user/Desktop/stockcrud/1.png");
        int g=ui->label_pic4->width();
        int f=ui->label_pic4->height()+800;

        ui->label_pic4->setPixmap(pix1.scaled(g,f));
   timer->stop();
}

void stock::on_stat_clicked()
{
    statistique s;
   hide();
    s.exec();

}
/*******************************************************reclamation******************************************/
void stock::on_pushButton_AjoutR_clicked()
{
    int id= ui->lineEdit_iddM->text().toInt();
    QString nom =ui->lineEdit_nommM->text();
    QString mail =ui->lineEdit_mailM->text();
     QString type=ui->comboBox_M->currentText();
      QString typerec =ui->lineEdit_recl->text();


     QString descr =ui->lineEdit_treclm->text();



     reclamation tmpreclamations(id,nom,mail,type,typerec,descr);

         bool test=tmpreclamations.ajouter();

          if(test)
        { ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
             QMessageBox::information(nullptr,"Ajout reclmation","reclamation ajouté avec succés");
             }
                  else
                  {
                   QMessageBox::warning(nullptr,"Error","reclamation non ajouté");
                  }

}


void stock::on_pushButton_ModifierR_clicked()
{
    int id= ui->lineEdit_iddM->text().toInt();
    QString nom =ui->lineEdit_nommM->text();
    QString mail =ui->lineEdit_mailM->text();
    QString type=ui->comboBox_M->currentText();
    QString typerec =ui->lineEdit_recl->text();
    QString descr =ui->lineEdit_treclm->text();

     reclamation tmpreclamations(id,nom,mail,type,typerec,descr);
     if (tmpreclamations.recherche(id))
     {
          bool test= tmpreclamations.modifier();

          if(test)
          {
             ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh

             QMessageBox::information(nullptr, QObject::tr("Modifier une reclamation"),
                               QObject::tr("Reclamation modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
                 else
                 {
                  QMessageBox::information(nullptr, QObject::tr("Modifier une reclamation"),
                                    QObject::tr("erreur.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                 }
}
     ui->lineEdit_iddM->clear();
     ui->lineEdit_recl->clear();
     ui->lineEdit_nommM->clear();
     ui->lineEdit_mailM->clear();
     ui->lineEdit_treclm->clear();
}

void stock::on_pushButton_SupprimerM_clicked()
{
    int id = ui->lineEdit_idd2M->text().toInt();
    bool test=tmpreclamations.supprimer(id);
    if (test)

        {ui->affichage_produit->setModel(tmpproduit.afficher());
     QMessageBox::information(nullptr,"suppression produit","produit supprimer avec succés");}

     else
             QMessageBox::warning(nullptr,"Error","produit non supprimer");



     ui->lineEdit_idd2M->clear();
}


void stock::on_comboBox_10M_activated(const QString &arg1)
{
    if(arg1== "Trie croissante")
        ui->liste_reclamation->setModel(tmpreclamations.tri_reclm());
    else if(arg1 == "Trie décroissante")
        ui->liste_reclamation->setModel(tmpreclamations.tri2());

     else if(arg1 == "Trie A..Z")
        ui->liste_reclamation->setModel(tmpreclamations.tri3());
}

void stock::on_pushButton_afficherR_clicked()
{
    ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
}

void stock::on_liste_reclamation_activated(const QModelIndex &index)
{
    QString val= ui->liste_reclamation->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from reclamation where id= '"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_iddM->setText(query.value(0).toString());
            ui->comboBox_M->setCurrentText(query.value(1).toString());
            ui->lineEdit_recl->setText(query.value(2).toString());
            ui->lineEdit_nommM->setText(query.value(3).toString());
            ui->lineEdit_mailM->setText(query.value(4).toString());
            ui->lineEdit_idd2M->setText(query.value(0).toString());
        }
    }
}

void stock::on_lineEdit_recherM_textChanged(const QString &arg1)
{
    reclamation c;
        c.clearTable(ui->liste_reclamation);
        int mat=ui->lineEdit_recherM->text().toInt();
        c.searchRegexp(ui->liste_reclamation,mat);
}


