#include "statistique.h"
#include "ui_statistique.h"
#include<QPainter>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include <QObject>
#include <QLinearGradient>
 #include<QtPrintSupport/QPrinterInfo>
#include <QEvent>
#include <QWidget>
#include "produit.h"
#include "stock.h"

statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{

    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}

void statistique::on_retour_clicked()
{

    stock w;
    hide();
    w.exec();
}


void statistique::on_view_stat_clicked()
{
    ui->graphicsView->setScene(tmpproduit.StatPromo_Product_type());
}

