#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Defined ComboBox1
    ui->comboBox->addItem("Select an option");
    ui->comboBox->addItem(QIcon(":/rec/INR.png"),"INR");
    ui->comboBox->addItem(QIcon(":/rec/USD.png"),"USD");
    ui->comboBox->addItem(QIcon(":/rec/JPY.png"),"JPY");
    ui->comboBox->addItem(QIcon(":/rec/Euro.png"),"Euro");
    ui->comboBox->addItem(QIcon(":/rec/Pound.png"),"Pound");
    //Defined ComboBox2
    ui->comboBox_2->addItem("Select an option");
    ui->comboBox_2->addItem(QIcon(":/rec/INR.png"),"INR");
    ui->comboBox_2->addItem(QIcon(":/rec/USD.png"),"USD");
    ui->comboBox_2->addItem(QIcon(":/rec/JPY.png"),"JPY");
    ui->comboBox_2->addItem(QIcon(":/rec/Euro.png"),"Euro");
    ui->comboBox_2->addItem(QIcon(":/rec/Pound.png"),"Pound");
}

//Conversion Function
double converter(double x,int *sign1,int *sign2 ){

    //From INR to others
    if(*sign1==1){
        if(*sign2==1)       return (x);
        else if(*sign2==2)  return (x*0.12);
        else if(*sign2==3)  return (x*1.81);
        else if(*sign2==4)  return (x*0.011);
        else if(*sign2==5)  return (x+0.0094);
    }
    //From USD to Others
    if(*sign1==2){
        if(*sign2==2)       return (x);
        else if(*sign2==1)  return (x*82.88);
        else if(*sign2==3)  return (x*150.46);
        else if(*sign2==4)  return (x*0.92);
        else if(*sign2==5)  return (x+0.79);
    }
    //from JPY to Others
    if(*sign1==3){
        if(*sign2==3)       return (x);
        else if(*sign2==1)  return (x*0.55);
        else if(*sign2==2)  return (x*0.0066);
        else if(*sign2==4)  return (x*0.0061);
        else if(*sign2==5)  return (x+0.0052);
    }
    //From Euro to Others
    if(*sign1==4){
        if(*sign1==4)       return (x);
        else if(*sign2==1)  return (x*89.94);
        else if(*sign2==2)  return (x*1.08);
        else if(*sign2==3)  return (x*163.26);
        else if(*sign2==5)  return (x+0.85);
    }
    //From Pound to Others/*
    if(*sign1==5){
        if(*sign2==5)       return (x);
        else if(*sign2==1)  return (x*105.10);
        else if(*sign2==2)  return (x*1.26);
        else if(*sign2==3)  return (x*190.78);
        else if(*sign2==4)  return (x+1.16);
    }
    return 0.0;
}

void MainWindow::on_comboBox_activated(int index)
{
    //Setting placeholder for each Currency and Setting Sign1 value
    if(index==1){
        sign1 = new int(1);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText("Enter INR Value");
    }
    else if(index==2){
        sign1 = new int(2);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText("Enter USD Value");
    }
    else if(index==3){
        sign1 = new int(3);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText("Enter JPY Value");
    }
    else if(index==4){
        sign1 = new int(4);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText("Enter Euro Value");
    }
    else if(index==5){
        sign1 = new int(5);
        ui->textEdit->clear();
        ui->textEdit->insertPlainText("Enter Pound Value");
    }
}


//Setting sign2 value
void MainWindow::on_comboBox_2_activated(int index)
{
    if(index==1){
        sign2 = new int(1);
        ui->textEdit->clear();
    }
    else if(index==2){
        sign2 = new int(2);
        ui->textEdit->clear();
    }
    else if(index==3){
        sign2 = new int(3);
        ui->textEdit->clear();
    }
    else if(index==4){
        sign2 = new int(4);
        ui->textEdit->clear();
    }
    else if(index==5){
        sign2 = new int(5);
        ui->textEdit->clear();
    }
}

//Convert Button Function and call of Conversion Function and setting ans value in textedit2
void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    double *currency = new double(text.toDouble());
    double converted= converter(*currency,sign1,sign2);
    QString stringValue = QString::number(converted);
    ui->textEdit_2->setPlainText(stringValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}
