#pragma once
#include <QString>

class Group
{
    explicit Group();
    void setUuid(int _uuid);
    void setUuidSpecialty(int _uuidSpecialty);
    void setNumber(QString _number);
    int getUuid();
    int getUuidSpecialty();
    QString getNumber();

private:
    int uuid;               //уникальный идентификатор группы
    int uuidSpecialty;      //уникальный идентификатор специальности
    QString number;             //номер группы
};
