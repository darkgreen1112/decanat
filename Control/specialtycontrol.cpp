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
    connect(listView, SIGNAL(editRecord()), this, SLOT(editRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("Кафедра №") << trUtf8("Код специальности") << trUtf8("Наименование"), context.setupModelSpecialty());
}

void SpecialtyControl::show()
{
    listView->show();
}

void SpecialtyControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeSpecialty(), false);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void SpecialtyControl::editRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeSpecialty(), true);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));

    specialty = context.getRequestForSpecialty(listView->getTable().currentIndex().row());
    changeRecord->getWidgetsSpecialty().lineEditDepartment.setText(QString::number(specialty.getUuidDepartment()));
    changeRecord->getWidgetsSpecialty().lineEditNumber.setText(specialty.getNumber());
    changeRecord->getWidgetsSpecialty().lineEditName.setText(specialty.getName());

    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void SpecialtyControl::saveRecord()
{
    if(changeRecord->getWidgetsSpecialty().lineEditDepartment.text() != "" && changeRecord->getWidgetsSpecialty().lineEditNumber.text() != "" &&
            changeRecord->getWidgetsSpecialty().lineEditName.text() != "")
    {
        if(!changeRecord->getIsEdited())
        {
            specialty.setUuidDepartment(changeRecord->getWidgetsSpecialty().lineEditDepartment.text().toInt());
            specialty.setNumber(changeRecord->getWidgetsSpecialty().lineEditNumber.text());
            specialty.setName(changeRecord->getWidgetsSpecialty().lineEditName.text());
            if (context.addSpecialty(specialty))
            {
                QMessageBox::information(nullptr, "Информация", "Запись добавлена");
                changeRecord->close();
            }
            else
            {
                QMessageBox::information(nullptr, "Информация", "Запрос на добавление записи отклонен. \nПожалуйста проверьте правильность данных");
            }
        }
        else
        {
            specialty.setUuidDepartment(changeRecord->getWidgetsSpecialty().lineEditDepartment.text().toInt());
            specialty.setNumber(changeRecord->getWidgetsSpecialty().lineEditNumber.text());
            specialty.setName(changeRecord->getWidgetsSpecialty().lineEditName.text());
            if (context.changeSpecialty(specialty))
            {
                QMessageBox::information(nullptr, "Информация", "Запись изменена");
                changeRecord->close();
            }
            else
            {
                QMessageBox::information(nullptr, "Информация", "Запрос на изменение записи отклонен. \nПожалуйста проверьте правильность данных");
            }
        }
    }
    else
    {
        QMessageBox::information(nullptr, "Информация", "Необходимо заполнить все поля");
    }
}

void SpecialtyControl::delRecord()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Информация", "Пожалуйста подтвердите удаление записи", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        if (context.delSpecialty(specialty))
        {
            QMessageBox::information(nullptr, "Информация", "Запись удалена");
            changeRecord->close();
        }
        else
        {
            QMessageBox::information(nullptr, "Информация", "Запрос на удаление записи отклонен. \nПожалуйста проверьте правильность данных");
        }
    }
}
