#include "studentcontrol.h"

StudentControl::StudentControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

StudentControl::~StudentControl()
{
    delete listView;
    if (changeRecord) { delete changeRecord; }
}

void StudentControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список студентов");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    connect(listView, SIGNAL(editRecord()), this, SLOT(editRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("Группа №") << trUtf8("Студ. билет №") << trUtf8("Фамилия")
                         << trUtf8("Имя") << trUtf8("Отчество") << trUtf8("Приказ №"), context.setupModelStudent());
}

void StudentControl::show()
{
    listView->show();
}

void StudentControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeStudent(), false);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void StudentControl::editRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeDepartment(), true);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void StudentControl::saveRecord()
{
    qDebug() << "сработало";
}
