#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
#include<string>
#include "signup.h"
#include "login.h"


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
    void on_signup();
    void handleSignupInfo(const QString &email, const QString &password, const QString &confPassword);


private:
    Ui::MainWindow *ui;
    Signup *signup;
    Login *login;
    std::map<QString,QString>*mp;
};
#endif // MAINWINDOW_H
