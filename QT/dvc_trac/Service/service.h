#ifndef SERVICE_H
#define SERVICE_H

#include <QMainWindow>
#include <QObject>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<QFileInfo>
#include"D:\DELTA\GIthub\Learning24\QT\dvc_trac\Database\database.h"

using namespace std;
class service
{
public:
    service();
};
class Declarations{
private:
    map<QString,vector<QString>>devicedetails;
    map<QString,vector<QString>>userdetails;
    map<QString,vector<pair<QString,pair<QString,pair<QString,QString>>>>> logs;
    // Database dbconnec;
public:
    //Setters Functions
    void setdevicedetails(QString devicetype,QString deviceid ){
        devicedetails[devicetype].push_back(deviceid);
    }
    void setuserdetails(QString username,QString userloc ){
        userdetails[username].push_back(userloc);
    }
    void setlogs(QString devicetype,QString deviceid,QString username,QString userloc,QString fileloc){
        logs[devicetype].push_back(make_pair(deviceid,make_pair(username,make_pair(userloc,fileloc))));
    }
    //Getters Functions
    map<QString,vector<QString>> getdevicedetails(){
        return devicedetails;
    }
    map<QString,vector<QString>> getuserdetails(){
        return userdetails;
    }
    map<QString,vector<pair<QString,pair<QString,pair<QString,QString>>>>> getlogs(){
        return logs;
    }


};

#endif // SERVICE_H
