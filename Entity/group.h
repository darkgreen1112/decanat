#pragma once
#include <QString>

class Group
{
public:
    explicit Group();
    void setUuid(int _uuid);
    void setUuidSpecialty(QString _uuidSpecialty);
    void setNumber(QString _number);
    int getUuid();
    QString getUuidSpecialty();
    QString getNumber();

private:
    int uuid;               //уникальный идентификатор группы
    QString uuidSpecialty;      //уникальный идентификатор специальности
    QString number;             //номер группы
};
