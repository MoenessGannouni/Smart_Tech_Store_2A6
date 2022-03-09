#ifndef FINANCE_H
#define FINANCE_H
#include<QPropertyAnimation>
#include"dependance.h"
#include <QDialog>
#include"revenue.h"
#include <QTimer>

#include <QDebug>
namespace Ui {
class finance;
}

class finance : public QDialog
{
    Q_OBJECT

public:
    explicit finance(QWidget *parent = nullptr);
    ~finance();

private slots:
    void on_pushButton_calcul_clicked();

    void on_pushButton_blocnote_clicked();

    void on_ajouter_revenue_clicked();

    void on_supprimer_revenue_clicked();

    void on_ajout_dependance_clicked();

    void on_tri_prix_revenue_clicked();

    void on_recherche_revenue_clicked();
    void myfunction();

    void on_supprimer_dependance_clicked();

    void on_recherche_dependance_clicked();

    void on_tri_prix_dependance_clicked();

    void on_modifier_revnue_clicked();

    void on_modifier_dependance_clicked();

    void on_tri_date_revenue_clicked();

    void on_tri_date_dependance_clicked();

    void on_imprimer_revenue_clicked();

    void on_imprimer_dependance_clicked();





private:
    Ui::finance *ui;
    QTimer *timer;
    QPropertyAnimation *animation;
    revenue tmprevenue;
    dependance tmpdependance;

};

#endif // FINANCE_H
