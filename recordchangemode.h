#pragma once
#include <QString>

struct RecordChangeMode {

    static QString ModeStudent()
    {
        return "Студент";
    }

    static QString ModeGroup()
    {
        return "Группа";
    }

    static QString ModeSpecialty()
    {
        return "Специальность";
    }

    static QString ModeDepartment()
    {
        return "Кафедра";
    }
};
