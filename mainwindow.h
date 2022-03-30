#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"horaire.h"
#include <QMainWindow>
#include"boutique.h"


namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Boutique Stmp;
    Horaire Htmp;
    
};
#endif // MAINWINDOW_H
