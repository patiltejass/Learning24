#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
#include<vector>
#include "generatepdf.h"//.h>
// #include "includes/ImageLibrary"
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

private slots:
    void on_save_button_clicked();
    void showdrop();
    void updateloc(const QString &text);
    void updateserial(const QString &text);

    //void on_select_img_button_clicked();

    void on_select_img_button_clicked();

    void on_generate_button_clicked();

private:
    Ui::MainWindow *ui;
    map<QString,vector<QString>>*devicedetails;
    map<QString,vector<QString>>*userdetails;
    map<QString,vector<pair<QString,pair<QString,QString>>>> *logs;
    QString selectedImageFilename;
    Generatepdf *generate();
};
#endif // MAINWINDOW_H
