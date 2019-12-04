#include "contextdb.h"

ContextDb::ContextDb()
{

}
ContextDb::~ContextDb()
{

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
