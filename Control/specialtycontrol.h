#pragma once

#include "Control/contextdb.h"
#include "Interface/listview.h"
#include "Interface/changerecord.h"
#include "recordchangemode.h"

class SpecialtyControl : public QObject
{
    Q_OBJECT
public:
    SpecialtyControl(ContextDb& _context);
    ~SpecialtyControl();
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
