#include "Entity/department.h"

Department::Department()
{

}

void Department::setUuid(int _uuid)
{
    uuid = _uuid;
}

void Department::setNumber(int _number)
{
    number = _number;
}

void Department::setName(QString _name)
{
    name = _name;
}

int Department::getUuid()
{
    return uuid;
}

int Department::getNumber()
{
    return number;
}

QString Department::getName()
{
    return name;
}
