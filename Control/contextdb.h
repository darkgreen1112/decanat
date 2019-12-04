#pragma once

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>

class ContextDb
{
public:
    ContextDb();
    ~ContextDb();
    bool connect();
    void disconnect();
private:
    QSqlDatabase    db;
};
