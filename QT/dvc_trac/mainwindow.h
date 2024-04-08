#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
#include<QFileInfo>
#include <QTimer>
#include <QColor>
#include <QPalette>
#include"Service/service.h"
#include"Database/database.h"
#include"generatepdf.h"
#include"updatedetails.h"
using namespace std;

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
signals:
    void sendDB(Database &dbconnection);
private slots:
    void on_save_button_clicked();
    void on_select_img_button_clicked();
    void showdrop();
    void updateloc(const QString &text);
    void updateserial(const QString &text);
    // void changeBackgroundColor();
    void on_generate_button_clicked();
    void on_update_user_button_clicked();
    void setting_logmap();
    void setting_usermap();
    void setting_devicemap();


private:
    Ui::MainWindow *ui;
    Declarations *declare;
    map<QString, vector<QString>> devicedetails1;  // Moved here
    map<QString, vector<QString>> userdetails1;
    map<QString,vector<pair<QString,pair<QString,pair<QString,QString>>>>> logs1;
    QString selectedImageFilename;
    Generatepdf * generate ;
    Updatedetails *update;
    Database dbconnection;
    vector<pair<QString,QString>> userdata;
    vector<pair<QString,QString>> devicedata;
    vector<pair<QString,pair<QString,pair<QString,pair<QString,QString>>>>>logdata;
    // QTimer *timer;
    // int currentColorIndex = -1;

};
#endif // MAINWINDOW_H
