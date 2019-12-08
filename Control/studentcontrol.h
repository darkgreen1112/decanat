#pragma once

#include "Control/contextdb.h"
#include "Interface/listview.h"
#include "Interface/changerecord.h"
#include "recordchangemode.h"

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
    void delRecord();
private:
    ListView * listView;
    ChangeRecord * changeRecord;
    ContextDb context;
};
