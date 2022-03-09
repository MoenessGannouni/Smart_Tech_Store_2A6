#ifndef BLOCNOTE_H
#define BLOCNOTE_H
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QDialog>

namespace Ui {
class blocnote;
}

class blocnote : public QDialog
{
    Q_OBJECT

public:
    explicit blocnote(QWidget *parent = nullptr);
    ~blocnote();


private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_saveas_clicked();

    void on_pushButton_print_clicked();

    void on_pushButton_copy_clicked();

    void on_pushButton_cut_clicked();

    void on_pushButton_paste_clicked();

    void on_pushButton_undo_clicked();

    void on_pushButton_redo_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::blocnote *ui;
    QString currentFile = "";
};

#endif // BLOCNOTE_H
