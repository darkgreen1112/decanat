#include "listview.h"

ListView::ListView()
{
    setMinimumSize(700,500);
    setWindowFlags(Qt::Window);

    buttonAdd = new QPushButton("Добавить");
    connect(buttonAdd, SIGNAL(clicked()), this, SIGNAL(addRecord()));

    layoutButton = new QHBoxLayout();
    layoutButton->addWidget(buttonAdd);

    table = new QTableView();
    layoutList = new QVBoxLayout();
    layoutList->addWidget(table);

    layoutGlobal = new QVBoxLayout();
    layoutGlobal->addLayout(layoutButton);
    layoutGlobal->addLayout(layoutList);
    setLayout(layoutGlobal);
}

ListView::~ListView()
{
    delete layoutGlobal;
    delete layoutButton;
    delete layoutList;

    delete buttonAdd;

    delete table;
}

void ListView::setupModel(const QStringList &headers, QSqlQueryModel &model)
{
    for(int i = 0, j = 0; i < model.columnCount(); i++, j++){
        model.setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    table->setModel(& model);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    //неизвестный зверь
    table->setSelectionMode(QAbstractItemView::SingleSelection);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    table->setColumnHidden(0,true);
}

QVBoxLayout& ListView::getLayoutGlobal()
{
    return * layoutGlobal;
}

QHBoxLayout& ListView::getLayoutButton()
{
    return * layoutButton;
}

QVBoxLayout& ListView::getLayoutList()
{
    return * layoutList;
}

QTableView& ListView::getTable()
{
    return * table;
}
