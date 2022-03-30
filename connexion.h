#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{ QSqlDatabase db;
public:
    connexion();
    bool createconnect();
    void closeconnect();
};

#endif // CONNEXION_H
