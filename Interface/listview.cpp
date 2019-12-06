#include "listview.h"

ListView::ListView()
{
    setMinimumSize(700,500);
    setWindowFlags(Qt::Window);

    buttonAdd = new QPushButton("Добавить");
    buttonDel = new QPushButton("Удалить");
    connect(buttonAdd, SIGNAL(clicked()), this, SIGNAL(addRecord()));
    connect(buttonDel, SIGNAL(clicked()), this, SIGNAL(delRecord()));

    layoutButton = new QHBoxLayout();
    layoutButton->addWidget(buttonAdd);
    layoutButton->addWidget(buttonDel);

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
