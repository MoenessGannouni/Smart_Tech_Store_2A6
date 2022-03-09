#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"employes.h"
#include"departement.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_ajouteremp_clicked();

    void on_supprimeremp_clicked();

    void on_modifieremp_clicked();

    void on_affichageemp_activated(const QModelIndex &index);

    void on_imprimer_emp_clicked();



   void on_pdf_em_clicked();

    void on_tri_emp_clicked();

    void on_rechercheemp_clicked();

    void on_ajouterdep_clicked();

    void on_modifier_dep_clicked();

    void on_affichage_dep_activated(const QModelIndex &index);

    void on_supprimer_dep_clicked();

    void on_recherche_dep_clicked();

    void on_tri_dep_clicked();

private:
    Ui::Dialog *ui;
    Employes tmpemployes;
    departement tmpdepartement;

};

#endif // DIALOG_H
