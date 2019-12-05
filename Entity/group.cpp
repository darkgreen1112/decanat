#include "Entity/group.h"

Group::Group()
{

}
void Group::setUuid(int _uuid)
{
    uuid = _uuid;
}

void Group::setUuidSpecialty(int _uuidSpecialty)
{
    uuidSpecialty = _uuidSpecialty;
}

void Group::setNumber(QString _number)
{
    number = _number;
}

int Group::getUuid()
{
    return uuid;
}

int Group::getUuidSpecialty()
{
    return uuidSpecialty;
}

QString Group::getNumber()
{
    return number;
}
