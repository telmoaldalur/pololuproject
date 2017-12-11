#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //system("rfcomm connect 0 00:06:66:4E:08:72");
    //system("wminput -w");
    w.show();

    return a.exec();

}
