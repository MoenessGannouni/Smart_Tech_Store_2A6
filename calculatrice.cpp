#include "calculatrice.h"
#include "ui_calculatrice.h"


// Holds current value of calculation
double calcVal = 0.0;

// Will define if this was the last math button clicked
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

calculatrice::calculatrice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculatrice)
{
    ui->setupUi(this);
    // Put 0.0 in Display
        ui->display->setText(QString::number(calcVal));

        // Will hold references to all the number buttons
        QPushButton *numButtons[10];

        // Cycle through locating the buttons
        for(int i = 0; i < 10; ++i){
            QString butName = "Button" + QString::number(i);

            // Get the buttons by name and add to array
            numButtons[i] = calculatrice::findChild<QPushButton *>(butName);

            // When the button is released call num_pressed()
            connect(numButtons[i], SIGNAL(released()), this,
                    SLOT(NumPressed()));
        }

        // Connect signals and slots for math buttons
        connect(ui->add, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->minus, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->multiplay, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
        connect(ui->divide, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));

        // Connect equals button
        connect(ui->equal, SIGNAL(released()), this,
                SLOT(EqualButtonPressed()));

        // Connect change sign
        connect(ui->changesign, SIGNAL(released()), this,
                SLOT(ChangeNumberSign()));


    }



calculatrice::~calculatrice()
{
    delete ui;
}

void calculatrice::NumPressed(){

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get number on button
    QString butVal = button->text();

    // Get the value in the display
    QString displayVal = ui->display->text();

    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){

        // calcVal = butVal.toDouble();
        ui->display->setText(butVal);

    } else {
        // Put the new number to the right of whats there
        QString newVal = displayVal + butVal;

        // Double version of number
        double dblNewVal = newVal.toDouble();


        ui->display->setText(QString::number(dblNewVal, 'g', 16));

    }
}

void calculatrice::MathButtonPressed(){

    // Cancel out previous math button clicks
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    // Store current value in Display
    QString displayVal = ui->display->text();
    calcVal = displayVal.toDouble();

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else {
        subTrigger = true;
    }

    // Clear display
    ui->display->setText("");

}

void calculatrice:: EqualButtonPressed(){

    // Holds new calculation
    double solution = 0.0;

    // Get value in display
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();

    // Make sure a math button was pressed
    if(addTrigger || subTrigger || multTrigger || divTrigger ){
        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        } else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        } else {
            solution = calcVal / dblDisplayVal;
        }
    }

    // Put solution in display
    ui->display->setText(QString::number(solution));

}

void calculatrice::ChangeNumberSign(){

    // Get the value in the display
    QString displayVal = ui->display->text();

    // Regular expression checks if it is a number
    // plus sign
    QRegExp reg("[-+]?[0-9.]*");

    // If it is a number change the sign
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;

        // Put solution in display
        ui->display->setText(QString::number(dblDisplayValSign));
    }

}

void calculatrice::on_clear_clicked()
{
 ui->display->setText(QString());
}
