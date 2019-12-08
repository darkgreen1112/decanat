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
    connect(listView, SIGNAL(editRecord()), this, SLOT(editRecord()));
    listView->setupModel(QStringList() << trUtf8("Идентификатор") << trUtf8("№") << trUtf8("Наименование"), context.setupModelDepartment());
}

void DepartmentControl::show()
{
    listView->show();
}

void DepartmentControl::addRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeDepartment(), false);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void DepartmentControl::editRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeDepartment(), true);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));
    department = context.getRequestForDepartment(listView->getTable().currentIndex().row());
    changeRecord->getWidgetsDepartment().lineEditNumber.setText(QString::number(department.getNumber()));
    changeRecord->getWidgetsDepartment().lineEditName.setText(department.getName());
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void DepartmentControl::saveRecord()
{
    if(changeRecord->getWidgetsDepartment().lineEditNumber.text() != "" &&
            changeRecord->getWidgetsDepartment().lineEditName.text() != "")
    {
        if(!changeRecord->getIsEdited())
        {
            department.setNumber(changeRecord->getWidgetsDepartment().lineEditNumber.text().toInt());
            department.setName(changeRecord->getWidgetsDepartment().lineEditName.text());
            if (context.addDepartment(department))
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
            department.setNumber(changeRecord->getWidgetsDepartment().lineEditNumber.text().toInt());
            department.setName(changeRecord->getWidgetsDepartment().lineEditName.text());
            if (context.changeDepartment(department))
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

void DepartmentControl::delRecord()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Информация", "Пожалуйста подтвердите удаление записи", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        if (context.delDepartment(department))
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
