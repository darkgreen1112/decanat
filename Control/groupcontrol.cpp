#include "groupcontrol.h"

GroupControl::GroupControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

GroupControl::~GroupControl()
{
    delete listView;
    if (changeRecord) { delete changeRecord; }
}

void GroupControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список групп");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("Специальность №") << trUtf8("Группа №"), context.setupModelGroup());
}

void GroupControl::show()
{
    listView->show();
}

void GroupControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeGroup());
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void GroupControl::delRecord()
{
    qDebug() << "удалить группу";
}
