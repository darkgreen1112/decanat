#include "Entity/specialty.h"

Specialty::Specialty()
{

}

void Specialty::setUuid(int _uuid)
{
    uuid = _uuid;
}

void Specialty::setUuidDepartment(int _uuidDepartment)
{
    uuidDepartment = _uuidDepartment;
}

void Specialty::setNumber(QString _number)
{
    number = _number;
}

void Specialty::setName(QString _name)
{
    name = _name;
}

int Specialty::getUuid()
{
    return uuid;
}

int Specialty::getUuidDepartment()
{
    return uuidDepartment;
}

QString Specialty::getNumber()
{
    return number;
}

QString Specialty::getName()
{
    return name;
}
