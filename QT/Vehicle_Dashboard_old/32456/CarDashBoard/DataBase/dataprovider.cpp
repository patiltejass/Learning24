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
    crateUserSetting();
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
                             "TotalKM INTEGER,"
                             "LastOperartor TEXT"

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

QString dataProvider::GetLastOpCol()
{
    QString lastOperatorColor;

    QSqlQuery GetLastOpCol_Query;
    GetLastOpCol_Query.prepare("SELECT Colour FROM UserSettingDB JOIN DashboardDB ON UserSettingDB.Operator = DashboardDB.LastOperartor WHERE DashboardDB.id = 1;");

    if (GetLastOpCol_Query.exec()) {
        if (GetLastOpCol_Query.next()) {
            lastOperatorColor = GetLastOpCol_Query.value(0).toString();
        } else {
            qDebug() << "No data found .";
        }
    } else {
        qDebug() << "get last operator query failed:" << GetLastOpCol_Query.lastError().text();
    }

    return lastOperatorColor;
}

int dataProvider::getTotalKm()
{
    QSqlQuery getTotalKm_Query;
    getTotalKm_Query.prepare("SELECT TotalKm from DashboardDb Where id = 1;");
    int totalKm;
    if(getTotalKm_Query.exec())
    {
        if (getTotalKm_Query.next()) {
            totalKm = getTotalKm_Query.value(0).toInt();
            qDebug()<<"KM"<<totalKm;
            return totalKm;
        } else {
            qDebug() << "No data found for the specified condition.";
        }

    }
    qDebug()<<" getTotalKm not executed";
    return 0;
}

int dataProvider::getEnginHour()
{
    QSqlQuery q;
    q.prepare("SELECT EngineHour FROM DashboardDB WHERE ID = 1;");
    int x;
    if (q.exec()) {
        if (q.next()) {
            x = q.value(0).toInt();
            return x;
        } else {
            qDebug() << "No data found .";
        }
    } else {
        qDebug() << "get last operator query failed:" << q.lastError().text();
    }

    return x;
}


bool dataProvider::insertEngineHours(int x)
{
    QSqlQuery update_Engine_hours_Query;
    update_Engine_hours_Query.prepare("UPDATE DashboardDB "
                                      "SET EngineHour = (:x) "
                                      "WHERE id = 1;");
    update_Engine_hours_Query.bindValue(":x" , x);
    if (!update_Engine_hours_Query.exec()) {
        qDebug() << "Failed to update EngineHour";
        return false;
    }

    qDebug() << "EngineHour updated successfully";
    return true;
}

bool dataProvider::insertNewOperator(const QString &op)
{
    QSqlQuery insertNewOperatorQuery;
    insertNewOperatorQuery.prepare("INSERT INTO UserSettingDB (Operator) VALUES (:op)");
    insertNewOperatorQuery.bindValue(":op" , op);
    if(!insertNewOperatorQuery.exec())
    {
        qDebug() << "new operator not added";
        return false;
    }
    qDebug() << "new operator added successfully";
    return true;
}

bool dataProvider::updateTotalKM()
{
    QSqlQuery updateKmQuery;
    updateKmQuery.prepare("UPDATE DashboardDB SET TotalKM = TotalKM + 10 Where id = 1");

    if(!updateKmQuery.exec())
    {
        qDebug() << "km not update";
        return false;
    }
    qDebug() <<"KM Updated Succesfully";
    return true;
}

bool dataProvider::updateUserdata(const QString &ope , const QString &col , const QString &trans)
{
    QSqlQuery updateUserdata;
    updateUserdata.prepare("UPDATE UserSettingDB SET Colour = :b, TransmissionType = :c WHERE Operator = :a ;");
    updateUserdata.bindValue(":a" , ope);
    updateUserdata.bindValue(":b" , col);
    updateUserdata.bindValue(":c" , trans);

    if(!updateUserdata.exec())
    {
        qDebug() << "Userdata not updated";
        return false;
    }
    qDebug() <<"userdata Updated successfully";
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

bool dataProvider::crateUserSetting()
{
    if (dashboard_Db.tables().contains("UserSettingDB"))
    {
        qDebug() << " UserSettingDB Database is already created";
        return false;
    }
    QSqlQuery createTableQuery;
    createTableQuery.prepare("CREATE TABLE UserSettingDB ("
                             "Operator TEXT PRIMARY KEY,"
                             "Colour TEXT,"
                             "TransmissionType TEXT,"
                             "FOREIGN KEY (Operator) "
                             "REFERENCES DashboardDB(LastOperator)"
                             ")");

    if(createTableQuery.exec())
    {

        qDebug() << "table created";
        // QSqlQuery insertInitialKmQuery;
        // insertInitialKmQuery.prepare("INSERT INTO UserSettingDB (TotalKM) VALUES(0);");
        // if (insertInitialKmQuery.exec())
        // {
        //     qDebug() << "Initial value for TotalKM inserted successfully";
        //     return true;
        // }
        // else
        // {
        //     qDebug() << "Failed to insert initial value for TotalKM:" << insertInitialKmQuery.lastError().text();
        //     return false;
        // }
        return true;
    }
    qDebug() <<"Not created database"<< createTableQuery.lastError();
    return false;
}

bool dataProvider::insertInUserSettingDB(const QString &user, const QString &colour, const QString &transmissionType)
{
    QSqlQuery insertUserQuery;
    insertUserQuery.prepare("INSERT INTO UserSettingDB (Operator, Colour, TransmissionType) VALUES (:a, :b, :c)");
    insertUserQuery.bindValue(":a", user);
    insertUserQuery.bindValue(":b", colour);
    insertUserQuery.bindValue(":c", transmissionType);

    if(!insertUserQuery.exec())
    {
        qDebug() << "insert user Query not executed:" << insertUserQuery.lastError().text();
        return false;
    }
    qDebug() << "insert user Query executed successfully";
    return true;
}

std::vector<QString> dataProvider::sendOperator()
{
    std::vector<QString> operators;

    QSqlQuery sendopQuery;
    sendopQuery.prepare("SELECT Operator FROM UserSettingDB;");

    if (sendopQuery.exec()) {
        while (sendopQuery.next()) {
            QString operatorName = sendopQuery.value(0).toString();
            operators.push_back(operatorName);
        }
    } else {
        qDebug() << "Error executing query: " << sendopQuery.lastError().text();
    }

    return operators;
}

bool dataProvider::updateLastOperator(QString a)
{
    QSqlQuery updateLastOperator_Query;
    qDebug() <<a;
    updateLastOperator_Query.prepare("UPDATE DashboardDB SET LastOperartor = (:op) Where id = 1");
    updateLastOperator_Query.bindValue(":op" , a);
    if(!updateLastOperator_Query.exec())
    {
        qDebug() << "operator not update";
        return false;
    }
    qDebug() <<"operator Updated Succesfully";
    return true;
}
