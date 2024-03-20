#include "mainwindow.h"
#include "signup.h"
#include "login.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include<string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mp = new std::map<std::string, std::string>;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mp;
}

void MainWindow::on_pushButton_clicked()
{
    Signup *sing = new Signup();
    connect(sing, &Signup::signupInfo, this, &MainWindow::handleSignupInfo);
    sing->show();
}
void MainWindow::on_pushButton_2_clicked()
{
    Login *logi = new Login();
    connect(logi, &Login::loginInfo, this, &MainWindow::handleLoginInfo);
    logi->show();
}

void MainWindow::handleSignupInfo(const QString &email, const QString &password, const QString &confPassword)
{
    //qDebug() << "Signup info received: " << email << " " << password << " " << confPassword;
    // Perform further processing with signup info
    mp = new std::map<std::string,std::string>;


    std::string emailStr = email.toStdString();
    std::string passwordStr = password.toStdString();


    if((*mp)[emailStr] != ""){
        QMessageBox::warning(nullptr, "Warning", "User already Exists ");
    }
    else{
        (*mp)[emailStr] = passwordStr;
        QMessageBox::information(nullptr, "Success", "User registered");
    }
}
void MainWindow::handleLoginInfo(const QString &email, const QString &password){
    std::string emailStr = email.toStdString();
    std::string passwordStr = password.toStdString();
    auto it = mp->find(emailStr);
    if (it == mp->end()) {
        QMessageBox::warning(nullptr, "Warning", "User not Found ");
    } else if (it->second == passwordStr) {
        QMessageBox::information(nullptr, "Success", "Login Successful");
    } else {
        QMessageBox::warning(nullptr, "Warning", "Incorrect Password");
    }
}





