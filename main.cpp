#include "mainwindow.h"

#include <QApplication>
#include <oclock.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   // OClock clock;

  // clock.show();
    return a.exec();
}
