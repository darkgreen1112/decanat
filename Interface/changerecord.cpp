#include "changerecord.h"

ChangeRecord::ChangeRecord(QString _mode) : mode(_mode)
{
    setWindowTitle(mode);
    setWindowFlags(Qt::Window);
    setMinimumSize(400,500);
    setMaximumSize(600,800);

    layoutData = new QVBoxLayout();
    initializationWidgetsData();

    buttonSave = new QPushButton("Сохранить");
    buttonDel = new QPushButton("Удалить");

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
        widgetsDepartment->labelNumber.setText("№");
        layoutData->addWidget(& widgetsDepartment->labelNumber);
        layoutData->addWidget(& widgetsDepartment->textEditNumber);
        widgetsDepartment->labelName.setText("Наименование");
        layoutData->addWidget(& widgetsDepartment->labelName);
        layoutData->addWidget(& widgetsDepartment->textEditName);
    }
}
