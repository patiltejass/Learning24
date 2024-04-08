#include<string>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(text1()));//1
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(text2()));//2
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(text3()));//3
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(text4()));//4
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(text5()));//5
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(text6()));//6
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(text7()));//7
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(text8()));//8
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(text9()));//9
    connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(text00()));//00
    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(text0()));//0
    connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(text_()));//.
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(textplus()));//+
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(textsub()));//-
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(textmul()));//*
    connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(textdiv()));// "/"
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(textrem()));//%
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(textback()));//+

}
void MainWindow::text1(){
    ui->textEdit->insertPlainText("1");
}
void MainWindow::text2(){
    ui->textEdit->insertPlainText("2");
}
void MainWindow::text3(){
    ui->textEdit->insertPlainText("3");
}
void MainWindow::text4(){
    ui->textEdit->insertPlainText("4");
}
void MainWindow::text5(){
    ui->textEdit->insertPlainText("5");
}
void MainWindow::text6(){
    ui->textEdit->insertPlainText("6");
}
void MainWindow::text7(){
    ui->textEdit->insertPlainText("7");
}
void MainWindow::text8(){
    ui->textEdit->insertPlainText("8");
}
void MainWindow::text9(){
    ui->textEdit->insertPlainText("9");
}
void MainWindow::text00(){
    ui->textEdit->insertPlainText("00");
}
void MainWindow::text0(){
    ui->textEdit->insertPlainText("0");
}
void MainWindow::text_(){
    ui->textEdit->insertPlainText(".");
}
void MainWindow::textplus(){
     QString var1 = ui->textEdit->toPlainText();
     a=std::stod(var1);
     sign = 1;
     ui->textEdit->clear();
}
void MainWindow::textsub(){
     QString var1 = ui->textEdit->toPlainText();
     a=std::stod(var1);
     sign = 2;
     ui->textEdit->clear();
}
void MainWindow::textmul(){
     QString var1 = ui->textEdit->toPlainText();
     a=std::stod(var1);
     sign = 3;
     ui->textEdit->clear();
}
void MainWindow::textdiv(){
     QString var1 = ui->textEdit->toPlainText();
     a=std::stod(var1);
     sign = 4;
     ui->textEdit->clear();
}
void MainWindow::textrem(){
     QString var1 = ui->textEdit->toPlainText();
     a=std::stod(var1);
     sign = 5;
     ui->textEdit->clear();
}
void MainWindow::textback() {
     QString currentText = ui->textEdit->toPlainText();
     if (!currentText.isEmpty()) {
         currentText.chop(1);
         ui->textEdit->setText(currentText);
     }
}
MainWindow::~MainWindow()
{
    delete ui;
}

