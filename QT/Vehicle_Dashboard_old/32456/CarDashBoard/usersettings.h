#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include <QDialog>
#include <QString>
#include <vector>
#include "addoperatorwindow.h"
#include "serviceprovider.h"
#include "meteredashboard.h"


namespace Ui {
class UserSettings;
}

class UserSettings : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettings(QWidget *parent = nullptr);
    ~UserSettings();
    std::vector<QString> askForOp();

private slots:
    void on_AddOperator_Button_clicked();
    void on_Load_Button_clicked();
    void on_Update_button_clicked();

private:
    Ui::UserSettings *ui;
    AddOperatorWindow *adOp_Obj;
    serviceProvider *serviceProvider_obj;
    void setCombo();

signals:
    void sendDataOfUser(QString a , QString b , QString c);
    void updateUser(QString a , QString b , QString c);
    void sendColour(QString col);

};

#endif // USERSETTINGS_H
