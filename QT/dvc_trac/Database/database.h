#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
// #include <QWidget>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QDir>
#include<map>
#include<vector>
using namespace std;
class Database:public QObject{

    Q_OBJECT
public:
    Database();
    QString path = QDir::currentPath();
    QString dbpath = path+"/example.db";
    QSqlDatabase db;
    bool openConnection();
    void closeConnection();
    bool createTable();
    bool insertData(const QString& deviceName, const QString& serialNumber, const QString& fileName, const QString& assignee, const QString& location);
    bool insertuserData(const QString& username, const QString& location);
    bool insertdeviceData(const QString& devicename, const QString& deviceid);
    vector<pair<QString,pair<QString,pair<QString,pair<QString,QString>>>>> setlogmap();
    vector<pair<QString,QString>> setusermap();
    vector<pair<QString,QString>> setdevicemap();
    ~Database();
// signals:
//     void sendlogdetails(const QString& devicename,const QString& serial_num,const QString& assignee,const QString& location,const QString& filename);
//     void senddevicedetails(const QString& devicename,const QString& deviceid);
//     void senduserdetails(const QString& username,const QString& location);
};

#endif // DATABASE_H
