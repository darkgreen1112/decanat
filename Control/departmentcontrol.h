#pragma once

#include "Control/contextdb.h"

class DepartmentControl : public QObject
{
    Q_OBJECT
public:
    DepartmentControl(ContextDb& _context);
    ~DepartmentControl();
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

    Department department;
};

