#include "blocnote.h"
#include "ui_blocnote.h"
#include<blocnote.h>
blocnote::blocnote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blocnote)
{
    ui->setupUi(this);

}

blocnote::~blocnote()
{
    delete ui;
}

void blocnote::on_pushButton_new_clicked()
{
    // Global referencing the current file that we are clearing
        currentFile.clear();

        // Clear the textEdit widget buffer
        ui->textEdit->setText(QString());
}

void blocnote::on_pushButton_open_clicked()
{
    // Opens a dialog that allows you to select a file to open
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

        // An object for reading and writing files
        QFile file(fileName);

        // Store the currentFile name
        currentFile = fileName;

        // Try to open the file as a read only file if possible or display a
        // warning dialog box
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Interface for reading text
        QTextStream in(&file);

        // Copy text in the string
        QString text = in.readAll();

        // Put the text in the textEdit widget
        ui->textEdit->setText(text);

        // Close the file
        file.close();
}

void blocnote::on_pushButton_saveas_clicked()
{
    // Opens a dialog for saving a file
        QString fileName = QFileDialog::getSaveFileName(this, "Save as");

        // An object for reading and writing files
        QFile file(fileName);

        // Try to open a file with write only options
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }

        // Store the currentFile name
        currentFile = fileName;

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Interface for writing text
        QTextStream out(&file);

        // Copy text in the textEdit widget and convert to plain text
        QString text = ui->textEdit->toPlainText();

        // Output to file
        out << text;

        // Close the file
        file.close();
}

void blocnote::on_pushButton_print_clicked()
{
    // Allows for interacting with printer
        QPrinter printer;

        // You'll put your printer name here
        printer.setPrinterName("Printer Name");

        // Create the print dialog and pass the name and parent
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }

        // Send the text to the printer
        ui->textEdit->print(&printer);
}

void blocnote::on_pushButton_copy_clicked()
{
 ui->textEdit->copy();
}

void blocnote::on_pushButton_cut_clicked()
{
ui->textEdit->cut();
}

void blocnote::on_pushButton_paste_clicked()
{
ui->textEdit->paste();
}

void blocnote::on_pushButton_undo_clicked()
{

    ui->textEdit->undo();
}

void blocnote::on_pushButton_redo_clicked()
{
ui->textEdit->redo();
}

void blocnote::on_pushButton_exit_clicked()
{
 QApplication::quit();
}
