#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("Rezgui");//inserer nom de l'utilisateur
db.setPassword("rezgui");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;


    return  test;
}
void Connection::closeConnection(){db.close();}
