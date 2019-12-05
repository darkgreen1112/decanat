#pragma once

#include <QObject>
#include <QPushButton>
#include "Interface/menu.h"
#include "Control/contextdb.h"
#include "Control/studentcontrol.h"
#include "Control/groupcontrol.h"
#include "Control/specialtycontrol.h"
#include "Control/departmentcontrol.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application();
    ~Application();

public slots:
    void studentControl();
    void groupControl();
    void specialtyControl();
    void departmentControl();

private:
    void InitializationWindow();
    Menu *menu;
    ContextDb * context;
    StudentControl * student;
    GroupControl * group;
    SpecialtyControl * specialty;
    DepartmentControl * department;
};
