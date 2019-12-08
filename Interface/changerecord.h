#pragma once
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "recordchangemode.h"

struct WidgetsDepartment;
struct WidgetsSpecialty;
struct WidgetsGroup;
struct WidgetsStudent;

class ChangeRecord : public QDialog
{
    Q_OBJECT
public:
    ChangeRecord(QString _mode, bool _isEdited);
    ~ChangeRecord();
    bool getIsEdited();

    WidgetsDepartment& getWidgetsDepartment();
    WidgetsSpecialty&  getWidgetsSpecialty();
    WidgetsGroup&      getWidgetsGroup();
    WidgetsStudent&    getWidgetsStudent();

signals:
    void saveRecord();
    void delRecord();

private:
    void initializationWidgetsData();

private:
    QString mode;
    bool isEdited;

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
    QLineEdit lineEditNumber;
    QLabel labelName;
    QLineEdit lineEditName;
};

struct WidgetsSpecialty {
    QLabel labelDepartment;
    QLineEdit lineEditDepartment;
    QLabel labelNumber;
    QLineEdit lineEditNumber;
    QLabel labelName;
    QLineEdit lineEditName;
};

struct WidgetsGroup {
    QLabel labelSpecialty;
    QLineEdit lineEditSpecialty;
    QLabel labelNumber;
    QLineEdit lineEditNumber;
};

struct WidgetsStudent {
    QLabel labelGroup;
    QLineEdit lineEditGroup;
    QLabel labelNumber;
    QLineEdit lineEditNumber;
    QLabel labelSurname;
    QLineEdit lineEditSurname;
    QLabel labelName;
    QLineEdit lineEditName;
    QLabel patronymic;
    QLineEdit lineEditPatronymic;
    QLabel labelOrder;
    QLineEdit lineEditOrder;
};
