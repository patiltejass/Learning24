#include "addoperatorwindow.h"
#include "ui_addoperatorwindow.h"

AddOperatorWindow::AddOperatorWindow(QWidget *parent)
    : QDialog(parent)
    ,serviceProvider_Obj(new serviceProvider)
    , ui(new Ui::AddOperatorWindow)
{
    ui->setupUi(this);
    connect(this , &AddOperatorWindow::sendOperator , serviceProvider_Obj, &serviceProvider::sendOperator);
}

AddOperatorWindow::~AddOperatorWindow()
{
    delete ui;
}
void AddOperatorWindow::changeCol(QString col)
{
    this->setStyleSheet("background-color:" + col + ";");
    qDebug() << "dashboard bg cahnge";
}

void AddOperatorWindow::on_add_button_clicked()
{
    QString operatorName = ui->lineEdit->text();

    emit sendOperator(operatorName);
}



