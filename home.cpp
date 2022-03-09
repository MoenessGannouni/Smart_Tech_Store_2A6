#include "home.h"
#include "ui_home.h"
#include"finance.h"

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




void home::on_pushButton_finance_clicked()
{


    finance w;
    hide();
    w.exec();

}


