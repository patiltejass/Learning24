#include "serviceprovider.h"

serviceProvider::serviceProvider():
    dataProviderobj(&dataProvider::DP_Object())
{
    fuelTime = new QTimer;
    batterylevelTime = new QTimer;
    setFuel(10);
    setBatteryLevel();
    connect(fuelTime , &QTimer::timeout , this , &serviceProvider::getFuel);
    fuelTime->start(1000);
    connect(batterylevelTime , &QTimer::timeout , this , &serviceProvider::getBatteryLevel);
    batterylevelTime->start(1000);
    calculateRPM(10 , 0.5);
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

double serviceProvider::calculateRPM(int numRotations, double timeInSeconds)
{
    double revolutionsPerSecond = numRotations / timeInSeconds;

    double rpm = revolutionsPerSecond * 60;
    qDebug() <<rpm;
    return rpm;
}

void serviceProvider::getFuel()
{
    fuel -= 1;
    dataProviderobj->updateTotalKM();
    qDebug() <<fuel;
    if(fuel == 0)
    {
        qDebug() <<"fuel is empty";
        fuelTime->stop();
    }
}

