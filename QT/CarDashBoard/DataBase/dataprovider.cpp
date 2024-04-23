#include "dataprovider.h"

dataProvider::dataProvider() {
    dashboard_Db = QSqlDatabase::addDatabase("QSQLITE");
    dashboard_Db.setDatabaseName(path);

    if(!dashboard_Db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database Connected Succesfully";
    }
    createTable();
}

dataProvider::~dataProvider()
{
    if(dashboard_Db.open())
    {
        dashboard_Db.close();
    }
}

bool dataProvider::createTable()
{
    if (dashboard_Db.tables().contains("DashboardDB"))
    {
        qDebug() << " DashboardDB Database is already created";
        return false;
    }
    QSqlQuery createTableQuery;
    createTableQuery.prepare("CREATE TABLE DashboardDB ("
                             "ID INTEGER PRIMARY KEY,"
                             "EngineHour INTEGER,"
                             "TotalKM INTEGER"
                             ")");

    if(createTableQuery.exec())
    {

        qDebug() << "table created";
        QSqlQuery insertInitialKmQuery;
        insertInitialKmQuery.prepare("INSERT INTO DashboardDB (TotalKM) VALUES(0);");
        if (insertInitialKmQuery.exec())
        {
            qDebug() << "Initial value for TotalKM inserted successfully";
            return true;
        }
        else
        {
            qDebug() << "Failed to insert initial value for TotalKM:" << insertInitialKmQuery.lastError().text();
            return false;
        }
        return true;
    }
    qDebug() <<"Not created database"<< createTableQuery.lastError();
    return false;
}

bool dataProvider::isOpen()
{
    return dashboard_Db.isOpen();
}

bool dataProvider::insertEngineHours()
{
    QSqlQuery update_Engine_hours_Query;
    update_Engine_hours_Query.prepare("UPDATE DashboardDB "
                                      "SET EngineHour = EngineHour + 1 "
                                      "WHERE id = :last_id");
    update_Engine_hours_Query.bindValue(":last_id", lastId); // Assuming you have retrieved lastId from addNewRowOfEngineHours()

    if (!update_Engine_hours_Query.exec()) {
        qDebug() << "Failed to update EngineHour";
        return false;
    }

    qDebug() << "EngineHour updated successfully";
    return true;
}

bool dataProvider::updateTotalKM()
{
    QSqlQuery updateKmQuery;
    updateKmQuery.prepare("UPDATE DashboardDB SET TotalKM = TotalKM + 10 ");

    if(!updateKmQuery.exec())
    {
        qDebug() << "km not update";
        return false;
    }
    qDebug() <<"KM Updated Succesfully";
    return true;
}

bool dataProvider::addNewRowOfEngineHours()
{
    QSqlQuery insert_Engine_hours_Query;
    insert_Engine_hours_Query.prepare("INSERT INTO DashboardDB (EngineHour) VALUES(0)");

    if (!insert_Engine_hours_Query.exec()) {
        qDebug() << "Engine row not inserted";
        return false;
    }

    lastId = insert_Engine_hours_Query.lastInsertId().toInt();

    qDebug() << "Engine row inserted with ID:" << lastId;
    return true;
}
