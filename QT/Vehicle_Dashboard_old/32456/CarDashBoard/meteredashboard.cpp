#include "meteredashboard.h"
#include "ui_meteredashboard.h"

MetereDashboard::MetereDashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MetereDashboard)
{
    ui->setupUi(this);
    speed =20;
    dialTimer = new QTimer;
    enginTimer = new QTimer;
    connect(enginTimer , &QTimer::timeout , this , &MetereDashboard::changeEngine);
    connect(dialTimer , &QTimer::timeout , this , &MetereDashboard::changeSpeed);
    dialTimer->start(100);
    enginTimer->start(300);
}

MetereDashboard::~MetereDashboard()
{
    enginTimer->stop();
    delete ui;
    delete dialTimer;
    delete enginTimer;

}

void MetereDashboard::getTotalKm(int x)
{
    totalKm = x;
    qDebug()<< "getTotal km of meterdashboard"<<totalKm;
    ui->lcdNumber->display(totalKm);
}

void MetereDashboard::getEngine(int x)
{
    engineHours = x;
    ui->lcdNumber_2->display(engineHours);
}

void MetereDashboard::changeSpeed()
{
    if(speed >= 200)
    {
        qDebug() <<"speed is out of limit";
        dialTimer->stop();
    }
    ui->dial->setValue(speed);
    ui->dial_2->setValue(speed);
    speed += 1;

}

void MetereDashboard::changeEngine()
{
    engineHours += 1;
    ui->lcdNumber_2->display(engineHours);
    qDebug() << "changeEngine" <<engineHours;
    emit sendEngine(engineHours);
}



