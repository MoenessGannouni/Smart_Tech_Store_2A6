#ifndef RECLAMATION_H
#define RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery> //sécurité (injection)
#include <QSqlQueryModel>
#include <QDate>
#include<QTableView>
#include<QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include<QSqlRecord>

class reclamation
{int id;
    QString nom,mail,type,typerec,descr;
public:
           reclamation();
           reclamation(int,QString,QString,QString,QString,QString);
//getters
          int get_id(){return id;}
          QString get_nom(){return nom;}
          QString get_mail(){return mail;}

          QString get_type(){return type;}
          QString get_typerec(){return typerec;}
          QString get_descr(){return descr;}

//setters
          void setid(int id){this->id=id;}
          void setnom(QString nom ){this->nom=nom;}
          void setmail(QString mail ){this->mail=mail;}

          void settype(QString type ){this->type=type;}
          void settyperec(QString typerec ){this->typerec=typerec;}
          void setdescr(QString descr ){this->descr=descr;}

  //fucntions
          bool ajouter();
           QSqlQueryModel * afficher();
           bool supprimer(int);
            bool  recherche(int);
           bool modifier();
            QSqlQueryModel *tri_reclm();
            QSqlQueryModel * tri2();
            QSqlQueryModel * tri3();


            void clearTable(QTableView*);
            void searchRegexp(QTableView*,int);



       };

#endif // RECLAMATION_H
