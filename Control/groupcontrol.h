#pragma once

#include "Control/contextdb.h"

class GroupControl : public QObject
{
    Q_OBJECT
public:
    GroupControl(ContextDb& _context);
    ~GroupControl();
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

    Group group;
};
