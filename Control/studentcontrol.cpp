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
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));
    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void StudentControl::editRecord()
{
    listView->close();
    changeRecord = new ChangeRecord(RecordChangeMode::ModeStudent(), true);
    connect(changeRecord, SIGNAL(saveRecord()), this, SLOT(saveRecord()));
    connect(changeRecord, SIGNAL(delRecord()), this, SLOT(delRecord()));

    student = context.getRequestForStudent(listView->getTable().currentIndex().row());
    changeRecord->getWidgetsStudent().lineEditGroup.setText(QString::number(student.getUuidGroup()));
    changeRecord->getWidgetsStudent().lineEditNumber.setText(student.getNumber());
    changeRecord->getWidgetsStudent().lineEditSurname.setText(student.getSurname());
    changeRecord->getWidgetsStudent().lineEditName.setText(student.getName());
    changeRecord->getWidgetsStudent().lineEditPatronymic.setText(student.getPatronymic());
    changeRecord->getWidgetsStudent().lineEditOrder.setText(student.getOrder());

    changeRecord->show();
    changeRecord->exec();
    listView->show();
}

void StudentControl::saveRecord()
{
    if(changeRecord->getWidgetsStudent().lineEditGroup.text() != "" && changeRecord->getWidgetsStudent().lineEditNumber.text() != "" &&
            changeRecord->getWidgetsStudent().lineEditSurname.text() != "" && changeRecord->getWidgetsStudent().lineEditName.text() != "" &&
            changeRecord->getWidgetsStudent().lineEditPatronymic.text() != "" && changeRecord->getWidgetsStudent().lineEditOrder.text() != "")
    {
        if(!changeRecord->getIsEdited())
        {
            student.setUuidGroup(changeRecord->getWidgetsStudent().lineEditGroup.text().toInt());
            student.setNumber(changeRecord->getWidgetsStudent().lineEditNumber.text());
            student.setSurname(changeRecord->getWidgetsStudent().lineEditSurname.text());
            student.setName(changeRecord->getWidgetsStudent().lineEditName.text());
            student.setPatronymic(changeRecord->getWidgetsStudent().lineEditPatronymic.text());
            student.setOrder(changeRecord->getWidgetsStudent().lineEditOrder.text());
            if (context.addStudent(student))
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
            student.setUuidGroup(changeRecord->getWidgetsStudent().lineEditGroup.text().toInt());
            student.setNumber(changeRecord->getWidgetsStudent().lineEditNumber.text());
            student.setSurname(changeRecord->getWidgetsStudent().lineEditSurname.text());
            student.setName(changeRecord->getWidgetsStudent().lineEditName.text());
            student.setPatronymic(changeRecord->getWidgetsStudent().lineEditPatronymic.text());
            student.setOrder(changeRecord->getWidgetsStudent().lineEditOrder.text());
            if (context.changeStudent(student))
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

void StudentControl::delRecord()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Информация", "Пожалуйста подтвердите удаление записи", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        if (context.delStudent(student))
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
