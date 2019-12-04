#pragma once
#include <QString>

struct Student
{
    int uuid;           //уникальный идентификатор студента
    int uuidGroup;      //уникальный идентификатор группы
    QString number;         //номер студенческого билета
    QString surname;        //фамилия
    QString name;           //имя
    QString patronymic;     //отчество
    QString order;          //номер приказа о зачислении
};

