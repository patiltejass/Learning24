#include "dashboardclass.h"
#include "./ui_dashboardclass.h"

DashBoardClass::DashBoardClass(QWidget *parent)
    : QMainWindow(parent)
    ,serviceProviderobj(new serviceProvider)
    , ui(new Ui::DashBoardClass)
{
    ui->setupUi(this);
    startButtonState = 0;
    connect(UserSettings_Obj, &UserSettings::sendColour , this, &DashBoardClass::changeCol);
    // In the constructor or initialization of DashBoardClass
    //connect(MetereDashboard_Obj, &MetereDashboard::sendEngine , this , &DashBoardClass::updateEngineHours);
    LastOp = serviceProviderobj->sendLastOperator();
    TotalKm = serviceProviderobj->sendTotalKm();
    lastEngin = serviceProviderobj->sendEngineHour();
}

DashBoardClass::~DashBoardClass()
{
    delete ui;
    delete serviceProviderobj;
}

void DashBoardClass::on_Start_Button_clicked()
{
    if(startButtonState == 0){
        ui->Start_Button->setStyleSheet("background-color: green; color: white;");
        ui->Start_Button->setText("STOP");
        MetereDashboard_Obj = new MetereDashboard(this);
        connect(MetereDashboard_Obj, &MetereDashboard::sendEngine, this, &DashBoardClass::updateEngineHours);

        MetereDashboard_Obj->show();
        MetereDashboard_Obj->setStyleSheet("background-color: " + LastOp +"; color: white;");
        MetereDashboard_Obj->getTotalKm(TotalKm);
        MetereDashboard_Obj->getEngine(lastEngin);
        startButtonState = 1;
    }
    else{
        ui->Start_Button->setStyleSheet("background-color: rgb(107, 114, 142); color: white;");
        ui->Start_Button->setText("START");
        LastOp = serviceProviderobj->sendLastOperator();
        MetereDashboard_Obj->close();
        startButtonState = 0;
    }
}

void DashBoardClass::on_User_Settings_Button_clicked()
{
    UserSettings_Obj =  new UserSettings;
    UserSettings_Obj->show();
}

void DashBoardClass::changeCol(QString col)
{
    this->setStyleSheet("background-color:" + col + ";");
    qDebug() << "dashboard bg cahnge";
}

void DashBoardClass::updateEngineHours(int x)
{
    qDebug() << "updateEngineHours dashboardclass" <<x;
    serviceProviderobj->updateEngine(x);
}

