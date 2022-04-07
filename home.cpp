#include "home.h"
#include "ui_home.h"
#include"stock.h"
home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{

ui->setupUi(this);

}

home::~home()
{
    delete ui;
}




void home::on_pushButton_stock_clicked()
{


    stock w;
    hide();
    w.exec();

}
