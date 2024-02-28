#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
#include<string>
#include "login.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void handleSignupInfo(const QString &email, const QString &password, const QString &confPassword);
    void handleLoginInfo(const QString &email, const QString &password);


private:
    Ui::MainWindow *ui;
    Login *login;
    Signup *signup;
    std::map <std::string,std::string>*mp;
};
#endif // MAINWINDOW_H
