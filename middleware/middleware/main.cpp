#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include "sockettest.h"
#include "jsonpattern.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SocketTest cTest;
    cTest.Connect();

    MainWindow w;
    w.show();
    return a.exec();
}
