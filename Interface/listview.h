#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QSqlQueryModel>
#include <QHeaderView>

class ListView : public QWidget
{
    Q_OBJECT
public:
    explicit ListView();
    ~ListView();
    QVBoxLayout& getLayoutGlobal();
    QHBoxLayout& getLayoutButton();
    QVBoxLayout& getLayoutList();
    QTableView&  getTable();
    void setupModel(const QStringList &headers, QSqlQueryModel &model);

signals:
    void addRecord();

private:
    QVBoxLayout * layoutGlobal;
    QHBoxLayout * layoutButton;
    QVBoxLayout * layoutList;

    QPushButton * buttonAdd;

    QTableView  * table;

};
