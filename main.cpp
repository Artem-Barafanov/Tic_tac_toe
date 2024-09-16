#include "mainwindow.h"
#include "MyPushButton.h"
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

    MyPushButton *game = new MyPushButton("Игра",&w);
    game->setEnabled(false);
    game->setStyleSheet("color: grey");
    font = game->font();
    font.setPointSize(20);
    game->setFont(font);
    game->setFixedSize(200, 50);
    game->move(80, 100);
    game->setAutoFillBackground(true);

    MyPushButton *auth = new MyPushButton("Авторизация", &w);
    font = auth->font();
    font.setPointSize(20);
    auth->setFont(font);
    auth->setFixedSize(200, 50);
    auth->move(300, 100);
    auth->setAutoFillBackground(true);

    MyPushButton *ok = new MyPushButton("OK", &w);
    ok->hide();
    font = ok->font();
    font.setPointSize(20);
    ok->setFont(font);
    ok->setFixedSize(200, 50);
    ok->move(300, 300);

    QLabel *lbl = new QLabel(&w);
    lbl->setText("Введите имена игроков:");
    lbl->hide();
    lbl->move(10,100);
    font = lbl->font();
    font.setPointSize(15);
    lbl->setFont(font);
    lbl->setFixedSize(400, 100);

    QLineEdit *qle1 = new QLineEdit(&w);
    qle1->hide();
    qle1->move(250,130);
    font = qle1->font();
    font.setPointSize(15);
    qle1->setFont(font);
    qle1->setFixedSize(250, 35);

    QLineEdit *qle2 = new QLineEdit(&w);
    qle2->hide();
    qle2->move(250,180);
    font = qle2->font();
    font.setPointSize(15);
    qle2->setFont(font);
    qle2->setFixedSize(250, 35);

    w.resize(600, 500);
    QObject::connect(auth, SIGNAL(clicked()),auth, SLOT(Hide_itself()));
    QObject::connect(auth, SIGNAL(Hide_another()),game, SLOT(hide()));
    QObject::connect(auth, SIGNAL(Show_another()),lbl, SLOT(show()));


    QObject::connect(auth, SIGNAL(Show_another()),qle1, SLOT(show()));
    QObject::connect(qle1, &QLineEdit::editingFinished, [=]() {
        QString text1 = qle1->text();
        qle1->setEnabled(false);
    });
    QObject::connect(auth, SIGNAL(Show_another()),qle2, SLOT(show()));
    QObject::connect(qle2, &QLineEdit::editingFinished, [=]() {
        QString text2 = qle2->text();
        qle2->setEnabled(false);
    });

    QObject::connect(auth, SIGNAL(Show_another()),ok, SLOT(show()));
    QObject::connect(ok, SIGNAL(clicked()),ok, SLOT(Hide_itself()));
    QObject::connect(ok, SIGNAL(Hide_another()),lbl, SLOT(hide()));
    QObject::connect(ok, SIGNAL(Hide_another()),qle1, SLOT(hide()));
    QObject::connect(ok, SIGNAL(Hide_another()),qle2, SLOT(hide()));
    QObject::connect(ok, SIGNAL(Show_another()),auth, SLOT(show()));
    QObject::connect(ok, &MyPushButton::Show_another, [game]() {
        game->show();
        game->setEnabled(true);
        game->setStyleSheet("background-color: white; color: black;");
    });
    w.show();

    return a.exec();
}
