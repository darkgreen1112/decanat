#pragma once
#include <QString>

class Student
{
public:
    explicit Student();
    void setUuid(int _uuid);
    void setUuidGroup(int _uuidGroup);
    void setNumber(QString _number);
    void setSurname(QString _surname);
    void setName(QString _name);
    void setPatronymic(QString _patronymic);
    void setOrder(QString _order);
    int getUuid();
    int getUuidGroup();
    QString getNumber();
    QString getSurname();
    QString getName();
    QString getPatronymic();
    QString getOrder();

private:
    int uuid;           //уникальный идентификатор студента
    int uuidGroup;      //уникальный идентификатор группы
    QString number;         //номер студенческого билета
    QString surname;        //фамилия
    QString name;           //имя
    QString patronymic;     //отчество
    QString order;          //номер приказа о зачислении
};

