#include "serviceprovider.h"

serviceProvider::serviceProvider()
{
    fuelTime = new QTimer;
    batterylevelTime = new QTimer;

    setFuel(10);
    setBatteryLevel();

    connect(fuelTime , &QTimer::timeout , this , &serviceProvider::getFuel);
    fuelTime->start(1000);

    connect(batterylevelTime , &QTimer::timeout , this , &serviceProvider::getBatteryLevel);
    batterylevelTime->start(1000);
}

serviceProvider::~serviceProvider()
{

}

void serviceProvider::setFuel(int x)
{
    fuel = x;
}

void serviceProvider::setBatteryLevel()
{
    batterylevel = 80.30;
}

void serviceProvider::getBatteryLevel()
{
    batterylevel -= 0.2;
    qDebug() << batterylevel;
    if(batterylevel <= 79)
    {
        qDebug() <<"battery is low";
        batterylevelTime->stop();
    }
}



std::vector<QString> serviceProvider::sendOperatorData()
{
    return dataProvider::DP_Object()->sendOperator();
}

void serviceProvider::sendUserDataToDB(QString op,QString col,QString trans)
{
    dataProvider::DP_Object()->insertInUserSettingDB(op , col , trans);
    updateLastOp(op);
}

void serviceProvider::updateUser(QString op, QString col, QString trans)
{
    dataProvider::DP_Object()->updateUserdata(op , col , trans);
}

void serviceProvider::sendOperator(const QString &op)
{
    dataProvider::DP_Object()->insertNewOperator(op);
}

void serviceProvider::updateLastOp(const QString& a)
{
    dataProvider::DP_Object()->updateLastOperator(a);
}

void serviceProvider::addNewRowEngine()
{
    dataProvider::DP_Object()->addNewRowOfEngineHours();
}

void serviceProvider::updateEngine(int x)
{
    dataProvider::DP_Object()->insertEngineHours(x);
}

QString serviceProvider::sendLastOperator()
{
    return dataProvider::DP_Object()->GetLastOpCol();
}

int serviceProvider::sendTotalKm()
{
    qDebug()<<"Service";
    return dataProvider::DP_Object()->getTotalKm();
}

int serviceProvider::sendEngineHour()
{
    return dataProvider::DP_Object()->getEnginHour();
}

void serviceProvider::getFuel()
{
    fuel -= 1;
    dataProvider::DP_Object()->updateTotalKM();
    qDebug() <<fuel;
    if(fuel == 0)
    {
        qDebug() <<"fuel is empty";
        fuelTime->stop();
    }
}


