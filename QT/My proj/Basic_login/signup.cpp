#include "signup.h"
#include "ui_signup.h"
#include<QMessageBox>

Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_pushButton_clicked()
{
    QString email = ui->textEdit->toPlainText();
    QString password = ui->textEdit_2->toPlainText();
    QString conf_pass = ui->textEdit_3->toPlainText();

    // Check if fields are filled and passwords match
    if(email.isEmpty() || password.isEmpty() || conf_pass.isEmpty()){
        QMessageBox::warning(nullptr, "Warning", "Please fill all the fields");
        return;
    }
    else if(password != conf_pass) {
        QMessageBox::warning(nullptr, "Warning", "Password and Confirm Password do not match");
        return;
    }
    emit signupInfo(email, password, conf_pass);
    this->close();

}

