#include "application.h"

Application::Application()
{
    context = new ContextDb();
    if(context->connect())
    {
        menu = new Menu();
        InitializationWindow();
        menu->show();
    }
}

Application::~Application()
{
    if (menu) delete menu;

    delete context;

    if (student) { delete student; }
    if (group) { delete group; }
    if (specialty) { delete specialty; }
    if (department) { delete department; }

    if (buttonStudent) { delete buttonStudent; }
    if (buttonGroup) { delete buttonGroup; }
    if (buttonSpecialty) { delete buttonSpecialty; }
    if (buttonDepartment) { delete buttonDepartment; }
}

void Application::InitializationWindow()
{
    buttonStudent = new QPushButton("Студент");
    buttonGroup = new QPushButton("Группа");
    buttonSpecialty = new QPushButton("Специальность");
    buttonDepartment = new QPushButton("Кафедра");

    connect(buttonStudent, SIGNAL(clicked()), this, SLOT(studentControl()));
    connect(buttonGroup, SIGNAL(clicked()), this, SLOT(groupControl()));
    connect(buttonSpecialty, SIGNAL(clicked()), this, SLOT(specialtyControl()));
    connect(buttonDepartment, SIGNAL(clicked()), this, SLOT(departmentControl()));

    buttonStudent->setMinimumHeight(50);
    buttonGroup->setMinimumHeight(50);
    buttonSpecialty->setMinimumHeight(50);
    buttonDepartment->setMinimumHeight(50);

    menu->setToolTip("Пожалуйста выберите пункт меню");

    menu->getVlayout().addWidget(buttonStudent);
    menu->getVlayout().addWidget(buttonGroup);
    menu->getVlayout().addWidget(buttonSpecialty);
    menu->getVlayout().addWidget(buttonDepartment);
}

void Application::studentControl()
{
    student = new StudentControl(*context);
    student->show();
}

void Application::groupControl()
{
    group = new GroupControl(*context);
    group->show();
}

void Application::specialtyControl()
{
    specialty = new SpecialtyControl(*context);
    specialty->show();
}

void Application::departmentControl()
{
    department = new DepartmentControl(*context);
    department->show();
}
