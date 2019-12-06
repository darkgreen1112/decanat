#include "departmentcontrol.h"

DepartmentControl::DepartmentControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

DepartmentControl::~DepartmentControl()
{
    delete listView;
}

void DepartmentControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список кафедр");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    connect(listView, SIGNAL(delRecord()), this, SLOT(delRecord()));
}

void DepartmentControl::show()
{
    listView->show();
    listView->exec();
}

void DepartmentControl::addRecord()
{
    qDebug() << "добавить кафедру";
}

void DepartmentControl::delRecord()
{
    qDebug() << "удалить кафедру";
}
