#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
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

    static dataProvider& DP_Object(){
        static dataProvider dp;
        return dp;
    }

    bool createTable();
    bool isOpen();
    bool insertEngineHours();
    bool updateTotalKM();
    bool addNewRowOfEngineHours();

};

#endif // DATAPROVIDER_H
