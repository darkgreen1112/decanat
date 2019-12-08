#pragma once
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include "recordchangemode.h"

struct WidgetsDepartment;
struct WidgetsSpecialty;
struct WidgetsGroup;
struct WidgetsStudent;

class ChangeRecord : public QDialog
{
public:
    ChangeRecord(QString _mode);
    ~ChangeRecord();

private:
    void initializationWidgetsData();
private:
    QString mode;

    QPushButton * buttonSave;
    QPushButton * buttonDel;

    QVBoxLayout * layoutGlobal;
    QVBoxLayout * layoutData;
    QVBoxLayout * layoutButton;

    WidgetsDepartment * widgetsDepartment;
    WidgetsSpecialty  * widgetsSpecialty;
    WidgetsGroup      * widgetsGroup;
    WidgetsStudent    * widgetsStudent;
};

struct WidgetsDepartment {
    QLabel labelNumber;
    QTextEdit textEditNumber;
    QLabel labelName;
    QTextEdit textEditName;
};

struct WidgetsSpecialty {

};

struct WidgetsGroup {

};

struct WidgetsStudent {

};
