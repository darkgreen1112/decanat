#pragma once
#include "QString"

struct Specialty
{
    int uuid;           //уникальный идентификатор специальности
    int uuidFaculty;    //уникальный идентификатор факультета
    QString number;         //номер специальности
    QString name;           //наименование специальности
};
