#include "menu.h"

Menu::Menu()
{
    setWindowTitle("Меню");
    setWindowFlags(Qt::Window);
    setMinimumSize(350,400);
    setMaximumSize(400,600);
    vlayout = new QVBoxLayout();
    QWidget* widget = new QWidget();
    widget->setLayout(vlayout);
    this->setCentralWidget(widget);
}

Menu::~Menu()
{
    delete vlayout;
}

QVBoxLayout& Menu::getVlayout()
{
    return * vlayout;
}
