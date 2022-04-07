#ifndef DIALOG_H
#define DIALOG_H
#include "client.h"
#include "historique.h"
#include "histo.h"

#include <QFileDialog>

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

    void on_modifierProduit_3_clicked();

    void on_rechercherClient_4_clicked();

    void on_tri_nom_clicked();

    void on_QRCode_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();

    void on_browse_clicked();

    void on_envoyer_clicked();

    void on_pdf_6_clicked();

    void on_afficherHisto_clicked();

private:
    Ui::Dialog *ui;
    Clients Etmp;
    historique Etmp_h;
    QStringList files;

    histo histor;
    histo histor1;
    histo histor2;
};

#endif // DIALOG_H
