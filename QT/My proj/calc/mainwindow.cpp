#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox msgBox;
    msgBox.setText("Welcome to project Alpha");
    msgBox.exec();

    // After displaying the message box, center it on its parent window
    msgBox.move(this->pos() + QPoint((this->width() - msgBox.width()) / 2,(this->height() - msgBox.height()) / 2));
    //numberbuttons
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(text1()));//1
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(text2()));//2
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(text3()));//3
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(text4()));//4
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(text5()));//5
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(text6()));//6
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(text7()));//7
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(text8()));//8
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(text9()));//9
    connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(text00()));//00
    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(text0()));//0
    connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(text_()));//.
}

//Number Buttons
//button for 1
void MainWindow::text1(){
    ui->textEdit->insertPlainText("1");
}
//button for 2
void MainWindow::text2(){
    ui->textEdit->insertPlainText("2");
}
//button for 3
void MainWindow::text3(){
    ui->textEdit->insertPlainText("3");
}
//button for 4
void MainWindow::text4(){
    ui->textEdit->insertPlainText("4");
}
//button for 5
void MainWindow::text5(){
    ui->textEdit->insertPlainText("5");
}
//button for 6
void MainWindow::text6(){
    ui->textEdit->insertPlainText("6");
}
//button for 7
void MainWindow::text7(){
    ui->textEdit->insertPlainText("7");
}
//button for 8
void MainWindow::text8(){
    ui->textEdit->insertPlainText("8");
}
//button for 9
void MainWindow::text9(){
    ui->textEdit->insertPlainText("9");
}
//button for 00
void MainWindow::text00(){
    ui->textEdit->insertPlainText("00");
}
//button for 0
void MainWindow::text0(){
    ui->textEdit->insertPlainText("0");
}
//button for .
void MainWindow::text_(){
    ui->textEdit->insertPlainText(".");
}
//operand functions
//Addition Button
void MainWindow::on_pushButton_9_clicked()
{
    QString text = ui->textEdit->toPlainText();
    number1 = new double(text.toDouble());
    sign = new int(1);
    ui->textEdit->clear();
}
//Substraction Button
void MainWindow::on_pushButton_10_clicked()
{
    QString text = ui->textEdit->toPlainText();
    number1 = new double(text.toDouble());
    sign = new int(2);
    ui->textEdit->clear();
}
//Multiplication Button
void MainWindow::on_pushButton_14_clicked()
{
    QString text = ui->textEdit->toPlainText();
    number1 = new double(text.toDouble());
    sign = new int(3);
    ui->textEdit->clear();
}
//Division Button
void MainWindow::on_pushButton_15_clicked()
{
    QString text = ui->textEdit->toPlainText();
    number1 = new double(text.toDouble());
    sign = new int(4);
    ui->textEdit->clear();
}
//Modulo Button
void MainWindow::on_pushButton_4_clicked()
{
    QString text = ui->textEdit->toPlainText();
    number1 = new double(text.toDouble());
    sign = new int(5);
    ui->textEdit->clear();
}
//Backspace Button
void MainWindow::on_pushButton_5_clicked()
{
    QString text = ui->textEdit->toPlainText();
    text.chop(1); // Remove the last character
    ui->textEdit->setPlainText(text);
}
//Equals Button
void MainWindow::on_pushButton_19_clicked()
{
    QString text = ui->textEdit->toPlainText();
    number2 = new double(text.toDouble());
    if(*sign==1){
        answer = new double(*number1 + *number2);
    }
    else if(*sign==2){
        answer = new double(*number1 - *number2);
    }
    else if(*sign==3){
        answer = new double(*number1 * *number2);
    }
    else if(*sign==4){
        answer = new double(*number1 / *number2);

    }
    // else if(*sign==5){
    //     *answer = *number1 % *number2;
    // }

    QString stringValue = QString::number(*answer);

    ui->textEdit->setPlainText(stringValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}
