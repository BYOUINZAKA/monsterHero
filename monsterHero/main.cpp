#include "mainwindow.h"
#include <QApplication>

#include "blockcontroller.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication aaa(argc, argv);
    MainWindow w;
    w.show();

    return aaa.exec();
}
