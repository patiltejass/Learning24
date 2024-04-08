#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void text1();
    void text2();
    void text3();
    void text4();
    void text5();
    void text6();
    void text7();
    void text8();
    void text9();
    void text0();
    void text00();
    void text_();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;
    double *number1;
    double *number2;
    double *answer;
    int *sign;

};
#endif // MAINWINDOW_H
