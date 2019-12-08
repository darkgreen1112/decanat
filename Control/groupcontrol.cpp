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
    connect(listView, SIGNAL(editRecord()), this, SLOT(editRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("Специальность №") << trUtf8("Группа №"), context.setupModelGroup());
}

void GroupControl::show()
{
    listView->show();
}

void GroupControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeGroup(), false);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void GroupControl::editRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeGroup(), true);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));

    group = context.getRequestForGroup(listView->getTable().currentIndex().row());
    changeRecord->getWidgetsGroup().lineEditSpecialty.setText(group.getUuidSpecialty());
    changeRecord->getWidgetsGroup().lineEditNumber.setText(group.getNumber());

    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void GroupControl::saveRecord()
{
    if(changeRecord->getWidgetsGroup().lineEditSpecialty.text() != "" && changeRecord->getWidgetsGroup().lineEditNumber.text() != "")
    {
        if(!changeRecord->getIsEdited())
        {
            group.setUuidSpecialty(changeRecord->getWidgetsGroup().lineEditSpecialty.text());
            group.setNumber(changeRecord->getWidgetsGroup().lineEditNumber.text());
            if (context.addGroup(group))
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
            group.setUuidSpecialty(changeRecord->getWidgetsGroup().lineEditSpecialty.text());
            group.setNumber(changeRecord->getWidgetsGroup().lineEditNumber.text());
            if (context.changeGroup(group))
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

void GroupControl::delRecord()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Информация", "Пожалуйста подтвердите удаление записи", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        if (context.delGroup(group))
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
