#include <QApplication>
#include "Control/contextdb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ContextDb * db = new ContextDb();
    if( db->connect())
    {
        qDebug() << "подключение удалось";
    }

    return a.exec();
}
