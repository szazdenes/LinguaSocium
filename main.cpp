#include "lingua.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lingua w;
    w.show();

    return a.exec();
}
