#ifndef HOME_H
#define HOME_H
#include<QPropertyAnimation>
#include <QMainWindow>


namespace Ui {
class home;
}

class home : public QMainWindow
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:


    void on_pushButton_stock_clicked();

private:
    Ui::home *ui;
 QPropertyAnimation *animation;
};

#endif // HOME_H
