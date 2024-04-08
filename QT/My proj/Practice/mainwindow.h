#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    double a,b,ans,sign;
    MainWindow(QWidget *parent = nullptr);
    MainWindow(){
        a=0;
        b=0;
        ans=0;
        sign=0;
    }
    ~MainWindow();

private slots:
    void text1();
    void text2();
    void text3();
    void text4();
    void text5();
    void text6();
    void text7();
    void text8();
    void text9();
    void text00();
    void text0();
    void text_();
    void textplus();
    void textsub();
    void textmul();
    void textdiv();
    void textrem();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
