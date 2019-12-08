#include "contextdb.h"

ContextDb::ContextDb()
{

}
ContextDb::~ContextDb()
{
    delete model;
}

bool ContextDb::connect()
{
    if(QFile("F:/gitExtensions/decanat/decanat.db").exists())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("ExampleDataBase");
        db.setDatabaseName("F:/gitExtensions/decanat/decanat.db");
        if(db.open())
        {
            model = new QSqlQueryModel();
            return true;
        }
        else
        {
            qDebug() << "Не удалось присоединиться к базе данных";
        }
    }
    else
    {
        qDebug() << "Не удалось открыть файл базы данных";
    }
    return false;
}

void ContextDb::disconnect()
{
    db.close();
}

QSqlQueryModel& ContextDb::setupModelDepartment()
{
    model->setQuery("select * from Department");
    return * model;
}

QSqlQueryModel& ContextDb::setupModelSpecialty()
{
    model->setQuery("select * from Specialty");
    return * model;
}

QSqlQueryModel& ContextDb::setupModelGroup()
{
    model->setQuery("select * from Party");
    return * model;
}
QSqlQueryModel& ContextDb::setupModelStudent()
{
    model->setQuery("select * from Student");
    return * model;
}
