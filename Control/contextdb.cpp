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

Department ContextDb::getRequestForDepartment(int row)
{
    Department department;
    department.setUuid(model->data(model->index(row, 0)).toInt());
    department.setNumber(model->data(model->index(row, 1)).toInt());
    department.setName(model->data(model->index(row, 2)).toString());
    return department;
}

bool ContextDb::addDepartment(Department department)
{
    QSqlQuery query;
    if(query.exec("INSERT INTO Department (Number, Name)"
                  "VALUES (" + QString::number(department.getNumber()) + ", '" + department.getName() + "')"))
    {
        model->setQuery(model->query().lastQuery());
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

bool ContextDb::changeDepartment(Department department)
{
    QSqlQuery query;
    if(query.exec("update Department set Number =" + QString::number(department.getNumber()) + ", Name ='" + department.getName() + "' where uuid = " + QString::number(department.getUuid())))
    {
        model->setQuery(model->query().lastQuery());
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

bool ContextDb::delDepartment(Department department)
{
    QSqlQuery query;
    if(query.exec("delete from Department where uuid = " + QString::number(department.getUuid())))
    {
        model->setQuery(model->query().lastQuery());
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

Specialty ContextDb::getRequestForSpecialty(int row)
{
    Specialty specialty;
    specialty.setUuid(model->data(model->index(row, 0)).toInt());
    specialty.setUuidDepartment(model->data(model->index(row, 1)).toInt());
    specialty.setNumber(model->data(model->index(row, 2)).toString());
    specialty.setName(model->data(model->index(row, 3)).toString());
    return specialty;
}

bool ContextDb::addSpecialty(Specialty specialty)
{
    QSqlQuery query;
    query.exec("SELECT EXISTS (select * from Department where Number = " + QString::number(specialty.getUuidDepartment()) + ");");
    query.next();
    if (query.value(0) != 0)
    {
        if(query.exec("INSERT INTO Specialty (UuidDepartment, Number, Name)"
                      "VALUES (" + QString::number(specialty.getUuidDepartment()) + ", '" + specialty.getNumber() + "' , '" + specialty.getName() + "')"))
        {
            model->setQuery(model->query().lastQuery());
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ContextDb::changeSpecialty(Specialty specialty)
{
    QSqlQuery query;
    query.exec("SELECT EXISTS (select * from Department where Number = " + QString::number(specialty.getUuidDepartment()) + ");");
    query.next();
    if (query.value(0) != 0)
    {
        if(query.exec("update Specialty set UuidDepartment = " +
                  QString::number(specialty.getUuidDepartment()) + " , Number ='" + specialty.getNumber() + "' ," +
                  "Name ='" + specialty.getName() + "' where uuid = " + QString::number(specialty.getUuid())))
        {
            model->setQuery(model->query().lastQuery());
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ContextDb::delSpecialty(Specialty specialty)
{
    QSqlQuery query;
    if(query.exec("delete from Specialty where uuid = " + QString::number(specialty.getUuid())))
    {
        model->setQuery(model->query().lastQuery());
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

Group ContextDb::getRequestForGroup(int row)
{
    Group group;
    group.setUuid(model->data(model->index(row, 0)).toInt());
    group.setUuidSpecialty(model->data(model->index(row, 1)).toString());
    group.setNumber(model->data(model->index(row, 2)).toString());
    return group;
}

bool ContextDb::addGroup(Group group)
{
    QSqlQuery query;
    query.exec("SELECT EXISTS (select * from Specialty where Number = '" + group.getUuidSpecialty() + "');");
    query.next();
    if (query.value(0) != 0)
    {
        if(query.exec("INSERT INTO Party (uuidSpecialty, Number)"
                      "VALUES ('" + group.getUuidSpecialty() + "', " + group.getNumber() + ")"))
        {
            model->setQuery(model->query().lastQuery());
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ContextDb::changeGroup(Group group)
{
    QSqlQuery query;
    query.exec("SELECT EXISTS (select * from Specialty where Number = '" + group.getUuidSpecialty() + "');");
    query.next();
    if (query.value(0) != 0)
    {
        if(query.exec("update Party set uuidSpecialty = '" +
                  group.getUuidSpecialty() + "' , Number =" + group.getNumber() +
                  " where uuid = " + QString::number(group.getUuid())))
        {
            model->setQuery(model->query().lastQuery());
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ContextDb::delGroup(Group group)
{
    QSqlQuery query;
    if(query.exec("delete from Party where uuid = " + QString::number(group.getUuid())))
    {
        model->setQuery(model->query().lastQuery());
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}

Student ContextDb::getRequestForStudent(int row)
{
    Student student;
    student.setUuid(model->data(model->index(row, 0)).toInt());
    student.setUuidGroup(model->data(model->index(row, 1)).toInt());
    student.setNumber(model->data(model->index(row, 2)).toString());
    student.setSurname(model->data(model->index(row, 3)).toString());
    student.setName(model->data(model->index(row, 4)).toString());
    student.setPatronymic(model->data(model->index(row, 5)).toString());
    student.setOrder(model->data(model->index(row, 6)).toString());
    return student;
}

bool ContextDb::addStudent(Student student)
{
    QSqlQuery query;
    query.exec("SELECT EXISTS (select * from Party where Number = " + QString::number(student.getUuidGroup()) + ");");
    query.next();
    if (query.value(0) != 0)
    {
        if(query.exec("INSERT INTO Student (uuidGroup, Number, Surname, Name, Patronymic, [Order])"
                      "VALUES (" + QString::number(student.getUuidGroup()) + "," +
                      "'" + student.getNumber() + "', " +
                      "'" + student.getSurname() + "', " +
                      "'" + student.getName() + "', " +
                      "'" + student.getPatronymic() + "', " +
                      "'" + student.getOrder() + "' )"))
        {
            model->setQuery(model->query().lastQuery());
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ContextDb::changeStudent(Student student)
{
    QSqlQuery query;
    query.exec("SELECT EXISTS (select * from Party where Number = " + QString::number(student.getUuidGroup()) + ");");
    query.next();
    if (query.value(0) != 0)
    {
        QSqlQuery query;
        if(query.exec("update Student set uuidGroup = " + QString::number(student.getUuidGroup())
                      + ", Number = '" + student.getNumber() +
                      + "', Surname = '" + student.getSurname()
                      + "', Name = '" + student.getName()
                      + "', Patronymic = '" + student.getPatronymic()
                      + "', [Order] = '" + student.getOrder()
                 + "' where uuid = " + QString::number(student.getUuid())))
        {
            model->setQuery(model->query().lastQuery());
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ContextDb::delStudent(Student student)
{
    QSqlQuery query;
    if(query.exec("delete from Student where uuid = " + QString::number(student.getUuid())))
    {
        model->setQuery(model->query().lastQuery());
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}
