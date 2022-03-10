#include "connection.h"

connection::connection(){}

bool connection::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("azerty12345");

    if (db.open()) test=true;
    return test;
}

void connection::closeConnection()
{
    db.close();
}
