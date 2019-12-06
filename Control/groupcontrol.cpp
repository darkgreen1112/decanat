#include "groupcontrol.h"

GroupControl::GroupControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

GroupControl::~GroupControl()
{
    delete listView;
}

void GroupControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список групп");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    connect(listView, SIGNAL(delRecord()), this, SLOT(delRecord()));
}

void GroupControl::show()
{
    listView->show();
    listView->exec();
}

void GroupControl::addRecord()
{
    qDebug() << "добавить группу";
}

void GroupControl::delRecord()
{
    qDebug() << "удалить группу";
}
