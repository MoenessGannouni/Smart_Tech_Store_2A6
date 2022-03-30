#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"boutique.h"
#include"horaire.h"
#include "exportexcelobject.h"
#include <QFileDialog>
#include<QDesktopServices>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Stmp.afficher());
    ui->tableView_2->setModel(Htmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
int ID=ui->lineEditID->text().toInt();
QString NOM=ui->lineEdit_NOM->text();
QString ADRESSE=ui->lineEditADRESSE->text();
Boutique B(ID,NOM,ADRESSE);
bool test=B.ajouter();
    if (test){
      ui->tableView->setModel(Stmp.afficher());
        QMessageBox::information(nullptr , QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                     QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pushButton_supprimer_clicked()
{
    int ID=ui->lineEdit_10->text().toInt();
    bool test=Stmp.supprimer(ID);
        if (test){
             ui->tableView->setModel(Stmp.afficher());
            QMessageBox::information(nullptr , QObject::tr("OK"),
                                     QObject::tr("Suppression effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                         QObject::tr("Suppression non effectuée\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}


/*void MainWindow::on_pushButton_2_clicked()
{
    int ID=ui->lineEdit_4->text().toInt();
    bool test=Stmp.modifier(ID);
        if (test){
             ui->tableView->setModel(Stmp.afficher());
            QMessageBox::information(nullptr , QObject::tr("OK"),
                                     QObject::tr("Modification effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

}
}*/


void MainWindow::on_pushButton_clicked()
{
    int ID=ui->lineEdit_4->text().toInt();
    QString NOM=ui->lineEdit_5->text();
    QString ADRESSE=ui->lineEdit_6->text();
    Boutique B(ID,NOM,ADRESSE);
    bool test=B.modifier(ID);
        if (test){
          ui->tableView->setModel(Stmp.afficher());
            QMessageBox::information(nullptr , QObject::tr("OK"),
                                     QObject::tr("Modification effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                         QObject::tr("Modification non effectué\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    QString HEUREO=ui->timeEdit_5->time().toString("hh:mm:ss");
    QString HEUREF=ui->timeEdit_6->time().toString("hh:mm:ss");

    Horaire H(ID,HEUREO,HEUREF);
    bool test=H.ajouter();
        if (test){
          ui->tableView_2->setModel(Htmp.afficher());
            QMessageBox::information(nullptr , QObject::tr("OK"),
                                     QObject::tr("Ajout effectué\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                         QObject::tr("Ajout non effectué\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }


void MainWindow::on_pushButton_3_clicked()
{
    int ID=ui->lineEdit_2->text().toInt();
    bool test=Htmp.supprimer(ID);
        if (test){
             ui->tableView_2->setModel(Htmp.afficher());
            QMessageBox::information(nullptr , QObject::tr("OK"),
                                     QObject::tr("Suppression effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                         QObject::tr("Suppression non effectuée\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    int ID=ui->lineEdit_3->text().toInt();
    QString HEUREO=ui->timeEdit_7->time().toString("hh:mm:ss");
    QString HEUREF=ui->timeEdit_8->time().toString("hh:mm:ss");
    Horaire H(ID,HEUREO,HEUREF);
    bool test=H.modifier(ID);
        if (test){
          ui->tableView_2->setModel(Htmp.afficher());
            QMessageBox::information(nullptr , QObject::tr("OK"),
                                     QObject::tr("Modification effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                         QObject::tr("Modification non effectué\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
            ui->tableView->setModel(Stmp.tri());
}

void MainWindow::on_pushButton_6_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    if (id==NULL) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a Number."));
        return;
    } else {
    ui->tableView->setModel(Stmp.recherche(id));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                       tr("Excel Files (*.xls)"));
            QString sheetName="test";
    ExportExcelObject obj(fileName, sheetName, ui->tableView);
    qInfo() << fileName;
    obj.addField(0, tr("ID"), "int");
    obj.addField(1, tr("NOM"), "char(20)");
    obj.addField(2, tr("ADRESSE"), "char(50)");
 obj.export2Excel();

}

void MainWindow::on_pdf_clicked()
{
    Stmp.genererPDF();
    QString link="C:/Users/21621/Desktop";
    QDesktopServices::openUrl(QUrl(link));
}
