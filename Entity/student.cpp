#include "Entity/student.h"

Student::Student()
{

}

void Student::setUuid(int _uuid)
{
    uuid = _uuid;
}

void Student::setUuidGroup(int _uuidGroup)
{
    uuidGroup = _uuidGroup;
}

void Student::setNumber(QString _number)
{
    number = _number;
}

void Student::setSurname(QString _surname)
{
    surname = _surname;
}

void Student::setName(QString _name)
{
    name = _name;
}

void Student::setPatronymic(QString _patronymic)
{
    patronymic = _patronymic;
}

void Student::setOrder(QString _order)
{
    order = _order;
}

int Student::getUuid()
{
    return uuid;
}

int Student::getUuidGroup()
{
    return uuidGroup;
}

QString Student::getNumber()
{
    return number;
}

QString Student::getSurname()
{
    return surname;
}

QString Student::getName()
{
    return name;
}

QString Student::getPatronymic()
{
    return patronymic;
}

QString Student::getOrder()
{
    return order;
}
