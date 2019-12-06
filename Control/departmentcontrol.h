#pragma once
#include "Control/contextdb.h"
#include "Interface/listview.h"

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
    void delRecord();
private:
    ListView * listView;

    ContextDb context;
};

