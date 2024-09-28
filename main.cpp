#include "mainwindow.h"
#include "field.h"
#include "field.h"
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Field fil;
    QObject::connect(&w, &MainWindow::game_clicked, &fil, &Field::show);
    w.resize(600, 500);
    fil.resize(600, 500);

    w.show();
    return a.exec();
}
