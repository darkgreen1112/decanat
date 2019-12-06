#include "specialtycontrol.h"

SpecialtyControl::SpecialtyControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

SpecialtyControl::~SpecialtyControl()
{
    delete listView;
}

void SpecialtyControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список специальностей");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    connect(listView, SIGNAL(delRecord()), this, SLOT(delRecord()));
}

void SpecialtyControl::show()
{
    listView->show();
    listView->exec();
}

void SpecialtyControl::addRecord()
{
    qDebug() << "добавить специальность";
}

void SpecialtyControl::delRecord()
{
    qDebug() << "удалить специальность";
}
