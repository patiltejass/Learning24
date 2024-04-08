#ifndef UPDATEDETAILS_H
#define UPDATEDETAILS_H

#include <QDialog>
#include<map>
#include<vector>
#include"Database/database.h"

using namespace std;
namespace Ui {
class Updatedetails;
}

class Updatedetails : public QDialog
{
    Q_OBJECT

public:
    explicit Updatedetails(map<QString,vector<QString>>&userdetails1,
                           map<QString,vector<QString>>&devicedetails1,
                           QWidget *parent = nullptr);
    ~Updatedetails();

private slots:
    void updateWidget();

    void on_update_user_button_clicked();

    void on_pushButton_clicked();
public slots:
    void accessDB(Database &dbconnection);

private:
    Ui::Updatedetails *ui;
    QString Username;
    QString location;
    QString Dvcname;
    QString Sr_No;
    map<QString,vector<QString>>devicedetails2;
    map<QString,vector<QString>>userdetails2;
    Database *db;
};

#endif // UPDATEDETAILS_H
