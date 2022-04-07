#ifndef FINANCE_H
#define FINANCE_H
#include<QPropertyAnimation>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include<QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include<QSqlRecord>
#include <QTableView>
#include <QDialog>
#include"produit.h"
#include <QTimer>
#include"reclamation.h"
namespace Ui {
class stock;
}

class stock : public QDialog
{
    Q_OBJECT

public:
    explicit stock(QWidget *parent = nullptr);
    ~stock();

private slots:

/***************Produit**************/

    void on_ajouter_produit_clicked();
    void on_supprimer_produit_clicked();
    void on_modifier_produit_clicked();
    void on_tri_prix_produit_clicked();
    void on_tri_id_produit_clicked();
    void on_recherche_produit_clicked();
    void myfunction();
    /***************excel**************/
void on_EXCEL_clicked();
    /***************stat**************/
void on_stat_clicked();
/***************reclamation**************/
void on_pushButton_AjoutR_clicked();

void on_pushButton_ModifierR_clicked();

void on_pushButton_SupprimerM_clicked();

void on_comboBox_10M_activated(const QString &arg1);

void on_pushButton_afficherR_clicked();

void on_liste_reclamation_activated(const QModelIndex &index);

void on_lineEdit_recherM_textChanged(const QString &arg1);

private:

    Ui::stock *ui;
    QTimer *timer;
    QPropertyAnimation *animation;
 produit tmpproduit;
 reclamation tmpreclamations;

};

#endif // FINANCE_H
