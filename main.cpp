#include "mainwindow.h"

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QLabel *tic = new QLabel("Крестики-нолики",&w);
    tic->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    tic->move(15,30);
    QFont font = tic->font();
    font.setPointSize(30);
    tic->setFont(font);
    tic->setFixedSize(550, 500);
    tic->setAutoFillBackground(true);

    QPushButton *game = new QPushButton("Игра",&w);
    game->setEnabled(false);
    game->setStyleSheet("color: grey");
    font = game->font();
    font.setPointSize(20);
    game->setFont(font);
    game->setFixedSize(200, 50);
    game->move(80, 100);
    game->setAutoFillBackground(true);

    QPushButton *authorization = new QPushButton("Авторизация",&w);
    font = authorization->font();
    font.setPointSize(20);
    authorization->setFont(font);
    authorization->setFixedSize(200, 50);
    authorization->move(300, 100);
    authorization->setAutoFillBackground(true);

    w.resize(600, 500);
    w.show();
    return a.exec();
}
