#include "specialtycontrol.h"

SpecialtyControl::SpecialtyControl(ContextDb& _context)
{
    context = _context;
    InitializationWindow();
}

SpecialtyControl::~SpecialtyControl()
{
    delete listView;
    if (changeRecord) { delete changeRecord; }
}

void SpecialtyControl::InitializationWindow()
{
    listView = new ListView();
    listView->setWindowTitle("Список специальностей");
    connect(listView, SIGNAL(addRecord()), this, SLOT(addRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("Кафедра №") << trUtf8("Код специальности") << trUtf8("Наименование"), context.setupModelSpecialty());
}

void SpecialtyControl::show()
{
    listView->show();
}

void SpecialtyControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeSpecialty());
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void SpecialtyControl::delRecord()
{
    qDebug() << "удалить специальность";
}
