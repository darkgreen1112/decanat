#pragma once

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "Entity/department.h"
#include "Entity/specialty.h"
#include "Entity/group.h"
#include "Entity/student.h"
#include "recordchangemode.h"
#include "Interface/listview.h"
#include "Interface/changerecord.h"

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

    Department getRequestForDepartment(int row);
    Specialty getRequestForSpecialty(int row);
    Group getRequestForGroup(int row);
    Student getRequestForStudent(int row);

    bool addDepartment(Department department);
    bool changeDepartment(Department department);
    bool delDepartment(Department department);

    bool addSpecialty(Specialty specialty);
    bool changeSpecialty(Specialty specialty);
    bool delSpecialty(Specialty specialty);

    bool addGroup(Group group);
    bool changeGroup(Group group);
    bool delGroup(Group group);

    bool addStudent(Student student);
    bool changeStudent(Student student);
    bool delStudent(Student student);

private:
    QSqlQueryModel * model;
    QSqlDatabase    db;
};
