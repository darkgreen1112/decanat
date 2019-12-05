#pragma once
#include "QString"

class Specialty
{
public:
    explicit Specialty();
    void setUuid(int _uuid);
    void setUuidDepartment(int _uuidDepartment);
    void setNumber(QString _number);
    void setName(QString _name);
    int getUuid();
    int getUuidDepartment();
    QString getNumber();
    QString getName();

private:
    int uuid;           //уникальный идентификатор специальности
    int uuidDepartment;    //уникальный идентификатор кафедры
    QString number;         //номер специальности
    QString name;           //наименование специальности
};
