#pragma once
#include "QString"

class Department
{
public:
    explicit Department();
    void setUuid(int _uuid);
    void setNumber(int _number);
    void setName(QString _name);
    int getUuid();
    int getNumber();
    QString getName();

private:
    int uuid;           //уникальный идентификатор кафедры
    int number;         //номер кафедры
    QString name;       //наименование кафедры
};
