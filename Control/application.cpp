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

}

void Application::InitializationWindow()
{
    QPushButton* buttonStudent = new QPushButton("Студент");
    QPushButton* buttonGroup = new QPushButton("Группа");
    QPushButton* buttonSpecialty = new QPushButton("Специальность");
    QPushButton* buttonDepartment = new QPushButton("Кафедра");

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
    qDebug() << "открывается окно со студентами";
}

void Application::groupControl()
{
    qDebug() << "открывается окно с группами";
}

void Application::specialtyControl()
{
    qDebug() << "открывается окно со специальностями";
}

void Application::departmentControl()
{
    qDebug() << "открывается окно с кафедрами";
}
