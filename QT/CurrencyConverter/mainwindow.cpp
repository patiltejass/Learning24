#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(true){
        ui->textEdit->setPlaceholderText("Enter Amount in USD");

    }
}


void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(true){
            ui->textEdit->setPlaceholderText("Enter Amount in INR");
    }
}

double INRtoUSD(double INR){
    return INR/83;
}
double USDtoINR(double USD){
    return USD *83;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    currency = new double(text.toDouble());

    if(ui->radioButton->isChecked()){
        ans = new double (USDtoINR(*currency));
        QString stringValue = QString::number(*ans);
        ui->textEdit_2->setPlainText(stringValue);
    }
    else if(ui->radioButton_2->isChecked()){
        ans = new double (INRtoUSD(*currency));
        QString stringValue = QString::number(*ans);
        ui->textEdit_2->setPlainText(stringValue);
    }
}


