#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QDialog>

namespace Ui {
class calculatrice;
}

class calculatrice : public QDialog
{
    Q_OBJECT

public:
    explicit calculatrice(QWidget *parent = nullptr);
    ~calculatrice();

private:
    Ui::calculatrice *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
    void on_clear_clicked();
};

#endif // CALCULATRICE_H
