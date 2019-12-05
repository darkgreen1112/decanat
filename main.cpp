#include <QApplication>
#include "Control/application.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application *app = new Application;
    return a.exec();
}
