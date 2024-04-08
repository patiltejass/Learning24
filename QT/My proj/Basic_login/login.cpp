#include "login.h"
#include "ui_login.h"
#include<QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString email = ui->textEdit->toPlainText();
    QString password = ui->textEdit_2->toPlainText();

    // Check if fields are filled and passwords match
    if(email.isEmpty() || password.isEmpty()){
        QMessageBox::warning(nullptr, "Warning", "Please fill all the fields");
        return;
    }
    emit loginInfo(email, password);
    this->close();
}

