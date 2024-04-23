#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include <vector>
#include <QSettings>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>

static const QString path = "People.db";

class dataProvider : public QObject
{
    Q_OBJECT
private:
    dataProvider();
    virtual ~dataProvider();

    dataProvider(const dataProvider&) = delete; // Prevent copying
    dataProvider& operator=(const dataProvider&) = delete;

    int lastId;

    QSqlDatabase dashboard_Db;
public:

    static dataProvider* DP_Object(){
        static dataProvider *Obj;

        if(!Obj)
        {
            Obj = new dataProvider;
        }
        return Obj;
    }

    bool createTable();
    bool crateUserSetting();
    bool isOpen();

    int getTotalKm();
    bool updateTotalKM();

    int getEnginHour();
    bool insertEngineHours(int x);
    bool addNewRowOfEngineHours();


    bool insertNewOperator(const QString &op);
    QString GetLastOpCol();
    std::vector<QString> sendOperator();
    bool updateLastOperator(QString a);


    bool updateUserdata(const QString &user , const QString &colour , const QString &transmissionType);


    bool insertInUserSettingDB(const QString &user , const QString &colour , const QString &transmissionType);


};

#endif // DATAPROVIDER_H
