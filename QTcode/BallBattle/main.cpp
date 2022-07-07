#include "mainwindow.h"
#include <QApplication>
#include "maingamer.h"
#include "camera.h"
mainGamer* mainGamer::gamePointer = NULL;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
