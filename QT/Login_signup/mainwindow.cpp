#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "signup.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(signup, &Signup::signupInfo, this, &MainWindow::handleSignupInfo);
    connect(login,&Login::loginInfo,this,&MainWindow::handleLoginInfo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Signup *sign =new Signup();
    sign->show();
}

void MainWindow::on_signup()
{
    qDebug() <<"on signu up callef";
}


void MainWindow::on_pushButton_2_clicked()
{
    Login *logi =new Login();
    logi->show();
}

void MainWindow::handleSignupInfo(const QString &email, const QString &password, const QString &confPassword)
{

    qDebug() << "Signup info received: " << email << " " << password << " " << confPassword;
}
void MainWindow::handleLoginInfo(const QString &email, const QString &password)
{
    qDebug()<<"Login Received";
}

