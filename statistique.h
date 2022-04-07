#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#include "produit.h"
namespace Ui {
class statistique ;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();
    //void setdata_statistics1();

private:
    Ui::statistique *ui;
    produit tmpproduit;


    //ev tmpevent;
    //double qvValues[3];
    //QColor qvColors[3];

protected:
//void paintEvent(QPaintEvent *);
private slots:
void on_view_stat_clicked();
void on_retour_clicked();

};
#endif // STATISITQUE_H
