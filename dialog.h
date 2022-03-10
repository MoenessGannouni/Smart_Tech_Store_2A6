#ifndef DIALOG_H
#define DIALOG_H
#include "client.h"
#include "historique.h"

#include <QDialog>

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
    void on_ajouterClient_4_clicked();

    void on_supprimerClient_4_clicked();

    void on_modifierClient_4_clicked();


    void combo();

    void on_ajouterProduit_clicked();

    void on_supprimerAchat_clicked();

private:
    Ui::Dialog *ui;
    Clients Etmp;
    historique Etmp_h;
};

#endif // DIALOG_H
