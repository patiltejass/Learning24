#ifndef DASHBOARDCLASS_H
#define DASHBOARDCLASS_H

#include <QMainWindow>
#include "serviceprovider.h"
#include "usersettings.h"
#include "meteredashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DashBoardClass;
}
QT_END_NAMESPACE

class DashBoardClass : public QMainWindow
{
    Q_OBJECT

public:
    DashBoardClass(QWidget *parent = nullptr);
    ~DashBoardClass();

private slots:
    void on_Start_Button_clicked();

    void on_User_Settings_Button_clicked();
public slots:
    void changeCol(QString col);
    void updateEngineHours(int x);

private:
    Ui::DashBoardClass *ui;
    serviceProvider *serviceProviderobj;
    UserSettings *UserSettings_Obj;
    MetereDashboard *MetereDashboard_Obj;
    void startButtonToggle();
    int startButtonState;


public:
    QString LastOp;
    int TotalKm;
    int lastEngin;
};
#endif // DASHBOARDCLASS_H
