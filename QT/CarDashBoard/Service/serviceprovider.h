#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H
#include <QObject>
#include "../DataBase/dataprovider.h"
#include <QTimer>

class serviceProvider : public QObject
{
    Q_OBJECT
private:
    float fuel;
    QTimer *fuelTime , *batterylevelTime;
    double batterylevel;
public:
    serviceProvider();
    ~serviceProvider();
    dataProvider *dataProviderobj;
    void getFuel();
    void setFuel(int x);
    void setBatteryLevel();
    void getBatteryLevel();
    double calculateRPM(int numRotations, double timeInSeconds);
};

#endif // SERVICEPROVIDER_H
