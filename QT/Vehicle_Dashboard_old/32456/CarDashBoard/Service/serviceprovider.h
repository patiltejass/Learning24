#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H
#include <QObject>
#include "../DataBase/dataprovider.h"
#include <QTimer>
#include <QString>
#include <vector>

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
    //dataProvider *dataProviderobj;
    void getFuel();
    void setFuel(int x);
    void setBatteryLevel();
    void getBatteryLevel();
    double calculateRPM(int numRotations, double timeInSeconds);
    std::vector<QString> sendOperatorData();
    void updateLastOp(const QString& a);
    double calculateSpeed(double rpm, double circumference) ;
    void addNewRowEngine();
    void updateEngine(int x);
    QString sendLastOperator();
    int sendTotalKm();
    int sendEngineHour();

public slots:
    void sendUserDataToDB(QString op ,QString col ,QString trans);
    void updateUser(QString op ,QString col ,QString trans);
    void sendOperator(const QString &op);

};

#endif // SERVICEPROVIDER_H
