#pragma once

#include "Control/contextdb.h"

class StudentControl : public QObject
{
    Q_OBJECT
public:
    StudentControl(ContextDb& _context);
    ~StudentControl();
    void show();

private:
    void InitializationWindow();

public slots:
    void addRecord();
    void editRecord();
    void saveRecord();
    void delRecord();

private:
    ListView * listView;
    ChangeRecord * changeRecord;
    ContextDb context;

    Student student;
};
