#include "changerecord.h"

ChangeRecord::ChangeRecord(QString _mode, bool _isEdited) : mode(_mode), isEdited(_isEdited)
{
    setWindowTitle(mode);
    setWindowFlags(Qt::Window);
    setMinimumSize(400,500);
    setMaximumSize(600,800);

    layoutData = new QVBoxLayout();
    initializationWidgetsData();

    buttonSave = new QPushButton("Сохранить");
    connect(buttonSave, SIGNAL(clicked()), this, SIGNAL(saveRecord()));
    buttonDel = new QPushButton("Удалить");
    buttonDel->setEnabled(isEdited);
    connect(buttonDel, SIGNAL(clicked()), this, SIGNAL(delRecord()));

    layoutButton = new QVBoxLayout();
    layoutButton->addWidget(buttonSave);
    layoutButton->addWidget(buttonDel);

    layoutGlobal = new QVBoxLayout();
    layoutGlobal->addLayout(layoutData);
    layoutGlobal->addLayout(layoutButton);
    setLayout(layoutGlobal);
}

ChangeRecord::~ChangeRecord()
{
    delete buttonSave;
    delete buttonDel;

    delete layoutGlobal;
    delete layoutData;
    delete layoutButton;

    if (widgetsDepartment) { delete widgetsDepartment; }
    if (widgetsSpecialty)  { delete widgetsSpecialty; }
    if (widgetsGroup)      { delete widgetsGroup; }
    if (widgetsStudent)    { delete widgetsStudent; }
}

void ChangeRecord::initializationWidgetsData()
{
    if (mode == RecordChangeMode::ModeDepartment())
    {
        widgetsDepartment = new WidgetsDepartment;

        widgetsDepartment->labelNumber.setText("<center>№</center>");
        widgetsDepartment->labelName.setText("<center>Наименование</center>");
        widgetsDepartment->lineEditNumber.setMaximumHeight(100);
        widgetsDepartment->lineEditName.setMaximumHeight(100);

        layoutData->addWidget(& widgetsDepartment->labelNumber);
        layoutData->addWidget(& widgetsDepartment->lineEditNumber);
        layoutData->addWidget(& widgetsDepartment->labelName);
        layoutData->addWidget(& widgetsDepartment->lineEditName);
    }
    else if (mode == RecordChangeMode::ModeSpecialty())
    {
        widgetsSpecialty = new WidgetsSpecialty;
        widgetsSpecialty->labelDepartment.setText("<center>Кафедра №</center>");
        widgetsSpecialty->labelNumber.setText("<center>Код специальности</center>");
        widgetsSpecialty->labelName.setText("<center>Наименование</center>");
        widgetsSpecialty->lineEditDepartment.setMaximumHeight(100);
        widgetsSpecialty->lineEditNumber.setMaximumHeight(50);
        widgetsSpecialty->lineEditName.setMaximumHeight(100);

        layoutData->addWidget(& widgetsSpecialty->labelDepartment);
        layoutData->addWidget(& widgetsSpecialty->lineEditDepartment);
        layoutData->addWidget(& widgetsSpecialty->labelNumber);
        layoutData->addWidget(& widgetsSpecialty->lineEditNumber);
        layoutData->addWidget(& widgetsSpecialty->labelName);
        layoutData->addWidget(& widgetsSpecialty->lineEditName);

    }
    else if (mode == RecordChangeMode::ModeGroup())
    {
        widgetsGroup = new WidgetsGroup;
        widgetsGroup->labelSpecialty.setText("<center>Код специальности</center>");
        widgetsGroup->labelNumber.setText("<center>Группа №</center>");
        widgetsGroup->lineEditSpecialty.setMaximumHeight(50);
        widgetsGroup->lineEditNumber.setMaximumHeight(50);

        layoutData->addWidget(& widgetsGroup->labelSpecialty);
        layoutData->addWidget(& widgetsGroup->lineEditSpecialty);
        layoutData->addWidget(& widgetsGroup->labelNumber);
        layoutData->addWidget(& widgetsGroup->lineEditNumber);
    }
    else if(mode == RecordChangeMode::ModeStudent())
    {
        widgetsStudent = new WidgetsStudent;
        widgetsStudent->labelGroup.setText("<center>Группа №</center>");
        widgetsStudent->lineEditGroup.setMaximumHeight(50);
        widgetsStudent->labelNumber.setText("<center>Студеческий билет №</center>");
        widgetsStudent->lineEditNumber.setMaximumHeight(50);
        widgetsStudent->labelSurname.setText("<center>Фамилия</center>");
        widgetsStudent->lineEditSurname.setMaximumHeight(50);
        widgetsStudent->labelName.setText("<center>Имя</center>");
        widgetsStudent->lineEditName.setMaximumHeight(50);
        widgetsStudent->patronymic.setText("<center>Отчество</center>");
        widgetsStudent->lineEditPatronymic.setMaximumHeight(50);
        widgetsStudent->labelOrder.setText("<center>Приказ №</center>");
        widgetsStudent->lineEditOrder.setMaximumHeight(50);

        layoutData->addWidget(& widgetsStudent->labelGroup);
        layoutData->addWidget(& widgetsStudent->lineEditGroup);
        layoutData->addWidget(& widgetsStudent->labelNumber);
        layoutData->addWidget(& widgetsStudent->lineEditNumber);
        layoutData->addWidget(& widgetsStudent->labelSurname);
        layoutData->addWidget(& widgetsStudent->lineEditSurname);
        layoutData->addWidget(& widgetsStudent->labelName);
        layoutData->addWidget(& widgetsStudent->lineEditName);
        layoutData->addWidget(& widgetsStudent->patronymic);
        layoutData->addWidget(& widgetsStudent->lineEditPatronymic);
        layoutData->addWidget(& widgetsStudent->labelOrder);
        layoutData->addWidget(& widgetsStudent->lineEditOrder);
    }
}

bool ChangeRecord::getIsEdited()
{
    return isEdited;
}

WidgetsDepartment& ChangeRecord::getWidgetsDepartment()
{
    return * widgetsDepartment;
}

WidgetsSpecialty& ChangeRecord::getWidgetsSpecialty()
{
    return * widgetsSpecialty;
}

WidgetsGroup& ChangeRecord::getWidgetsGroup()
{
    return * widgetsGroup;
}

WidgetsStudent& ChangeRecord::getWidgetsStudent()
{
    return * widgetsStudent;
}
