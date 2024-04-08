#include "database.h"
#include<QDir>
#include<vector>
#include<map>
using namespace std;

Database::Database() {
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbpath);
    if (openConnection()) {
        createTable();
    }
}

Database::~Database()
{
    closeConnection();
}

bool Database::openConnection()
{
    if (!db.open()) {
        qDebug() << "Error: " << db.lastError().text();
        return false;
    }
    return true;
}

void Database::closeConnection()
{
    db.close();
}

bool Database::createTable()
{
    QSqlQuery query;
    qDebug() <<"Table Created Successfully";
    query.exec("CREATE TABLE IF NOT EXISTS Users(username TEXT PRIMARY KEY, location TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS Devicesdetails(devicename TEXT, deviceid TEXT PRIMARY KEY)");
    return query.exec("CREATE TABLE IF NOT EXISTS devices (id INTEGER PRIMARY KEY AUTOINCREMENT, deviceName TEXT, serialNumber TEXT, fileName TEXT, assignee TEXT, location TEXT)");
}

bool Database::insertData(const QString& deviceName, const QString& serialNumber, const QString& fileName, const QString& assignee, const QString& location)
{
    QSqlQuery query;
    query.prepare("INSERT INTO devices(deviceName, serialNumber, fileName, assignee, location) VALUES (:deviceName, :serialNumber, :fileName, :assignee, :location)");
    query.bindValue(":deviceName", deviceName);
    query.bindValue(":serialNumber", serialNumber);
    query.bindValue(":fileName", fileName);
    query.bindValue(":assignee", assignee);
    query.bindValue(":location", location);
    return query.exec();
}
bool Database::insertuserData(const QString& username, const QString& location){
    QSqlQuery query;
    query.prepare("INSERT INTO Users(username,location) VALUES (:username,:location)");
    query.bindValue(":username", username);
    query.bindValue(":location", location);
    return query.exec();
}
bool Database::insertdeviceData(const QString& devicename, const QString& deviceid){
    QSqlQuery query;
    query.prepare("INSERT INTO Devicesdetails(devicename, deviceid) VALUES (:devicename, :deviceid)");
    query.bindValue(":devicename", devicename);
    query.bindValue(":deviceid", deviceid);
    return query.exec();
}
vector<pair<QString,pair<QString,pair<QString,pair<QString,QString>>>>> Database::setlogmap() {
    vector<pair<QString,pair<QString,pair<QString,pair<QString,QString>>>>>logs;
    QSqlQuery query;
    if (!query.exec("SELECT deviceName, serialNumber, fileName, assignee, location FROM devices")) {
        qDebug() << "Error executing query:" << query.lastError();
    }
    while (query.next()) {
        QString device_name = query.value(0).toString();
        QString serial_num = query.value(1).toString();
        QString filename = query.value(2).toString();
        QString assignee = query.value(3).toString();
        QString location = query.value(4).toString();
        logs.push_back(make_pair(device_name,make_pair(serial_num,make_pair(assignee,make_pair(location,filename)))));
    }
    return logs;
}
vector<pair<QString,QString>> Database::setusermap(){
    // map<QString,vector<QString>>ans;
    vector<pair<QString,QString>> user;
    QSqlQuery query;
    if (!query.exec("SELECT username, location FROM Users")) {
        qDebug() << "Error executing query:" << query.lastError();
    }
    while(query.next()){
        QString username = query.value(0).toString();
        QString location = query.value(1).toString();
        // emit senduserdetails(username,location);
        qDebug()<<username<<" "<<location<<"\n";
        user.push_back(make_pair(username,location));
    }
    return user;
}
vector<pair<QString,QString>> Database::setdevicemap(){
    // map<QString,vector<QString>>ans;
    vector<pair<QString,QString>> device;
    QSqlQuery query;
    if (!query.exec("SELECT devicename, deviceid FROM Devicesdetails")) {
        qDebug() << "Error executing query:" << query.lastError();
    }
    while(query.next()){
        QString devicename = query.value(0).toString();
        QString deviceid = query.value(1).toString();
        // ans[username].emplace_back(location);
        // emit senddevicedetails(devicename,deviceid);
        // qDebug()<<devicename<<" "<<deviceid<<"\n";
        device.push_back(make_pair(devicename,deviceid));
    }
    return device;
}
