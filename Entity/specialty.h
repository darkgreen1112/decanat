#pragma once
#include "QString"

struct Specialty
{
    int uuid;           //уникальный идентификатор специальности
    int uuidDepartment;    //уникальный идентификатор кафедры
    QString number;         //номер специальности
    QString name;           //наименование специальности
};
