#pragma once

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>
class ContextDb
{
public:
    ContextDb();
    ~ContextDb();
    bool connect();
    void disconnect();
    QSqlQueryModel& setupModelDepartment();
    QSqlQueryModel& setupModelSpecialty();
    QSqlQueryModel& setupModelGroup();
    QSqlQueryModel& setupModelStudent();

private:
    QSqlQueryModel * model;
    QSqlDatabase    db;
};
