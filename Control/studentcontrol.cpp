#include "studentcontrol.h"

StudentControl::StudentControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

StudentControl::~StudentControl()
{
    delete listView;
}

void StudentControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список студентов");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    connect(listView, SIGNAL(delRecord()), this, SLOT(delRecord()));
}

void StudentControl::show()
{
    listView->show();
    listView->exec();
}

void StudentControl::addRecord()
{
    qDebug() << "добавить студента";
}

void StudentControl::delRecord()
{
    qDebug() << "удалить студента";
}
