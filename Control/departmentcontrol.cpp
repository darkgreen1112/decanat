#include "departmentcontrol.h"

DepartmentControl::DepartmentControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

DepartmentControl::~DepartmentControl()
{
    delete listView;
    if (changeRecord) { delete changeRecord; }
}

void DepartmentControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список кафедр");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("№") << trUtf8("Наименование"), context.setupModelDepartment());
}

void DepartmentControl::show()
{
    listView->show();
}

void DepartmentControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeDepartment());
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void DepartmentControl::delRecord()
{
    qDebug() << "удалить кафедру";
}
