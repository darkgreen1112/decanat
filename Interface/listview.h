#pragma once
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>

class ListView : public QDialog
{
    Q_OBJECT
public:
    explicit ListView();
    ~ListView();
    QVBoxLayout& getLayoutGlobal();
    QHBoxLayout& getLayoutButton();
    QVBoxLayout& getLayoutList();
    QTableView&  getTable();

signals:
    void addRecord();
    void delRecord();

private:
    QVBoxLayout * layoutGlobal;
    QHBoxLayout * layoutButton;
    QVBoxLayout * layoutList;

    QPushButton * buttonAdd;
    QPushButton * buttonDel;

    QTableView  * table;
};
