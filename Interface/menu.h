#pragma once

#include <QMainWindow>
#include <QVBoxLayout>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu();
    ~Menu();
    QVBoxLayout& getVlayout();
private:
    QVBoxLayout* vlayout;
};

