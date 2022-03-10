#include "dialog.h"
#include "connection.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    connection c;
    bool test=c.createConnection();
    Dialog d;

    if(test)
    {
        d.show();

        QMessageBox::information(nullptr, QObject::tr("Database is open"), QObject::tr("connection succesful. \n" "Click cancel to exit"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"), QObject::tr("connection failed. \n" "Click cancel to exit"), QMessageBox::Cancel);
    }

    return a.exec();
}
