#include "firstrun.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Firstrun w;
    w.show();
    
    return a.exec();
}
