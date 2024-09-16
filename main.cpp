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

    int x = 150;
    int y = 100;
    int size = 90;
    MyPushButton *b1 = new MyPushButton("",&w);
    b1->hide();
    b1->move(x,y);
    font = b1->font();
    font.setPointSize(15);
    b1->setFont(font);
    b1->setFixedSize(size, size);
    MyPushButton *b2 = new MyPushButton("",&w);
    b2->hide();
    b2->move(x+size,y);
    font = b2->font();
    font.setPointSize(15);
    b2->setFont(font);
    b2->setFixedSize(size, size);
    MyPushButton *b3 = new MyPushButton("",&w);
    b3->hide();
    b3->move(2*size+x,y);
    font = b3->font();
    font.setPointSize(15);
    b3->setFont(font);
    b3->setFixedSize(size, size);
    MyPushButton *b4 = new MyPushButton("",&w);
    b4->hide();
    b4->move(x,size+y);
    font = b4->font();
    font.setPointSize(15);
    b4->setFont(font);
    b4->setFixedSize(size, size);
    MyPushButton *b5 = new MyPushButton("",&w);
    b5->hide();
    b5->move(size+x,size+y);
    font = b5->font();
    font.setPointSize(15);
    b5->setFont(font);
    b5->setFixedSize(size, size);
    MyPushButton *b6 = new MyPushButton("",&w);
    b6->hide();
    b6->move(2*size+x,size+y);
    font = b6->font();
    font.setPointSize(15);
    b6->setFont(font);
    b6->setFixedSize(size, size);
    MyPushButton *b7 = new MyPushButton("",&w);
    b7->hide();
    b7->move(x,2*size+y);
    font = b7->font();
    font.setPointSize(15);
    b7->setFont(font);
    b7->setFixedSize(size, size);
    MyPushButton *b8 = new MyPushButton("",&w);
    b8->hide();
    b8->move(size+x,2*size+y);
    font = b8->font();
    font.setPointSize(15);
    b8->setFont(font);
    b8->setFixedSize(size, size);
    MyPushButton *b9 = new MyPushButton("",&w);
    b9->hide();
    b9->move(2*size+x,2*size+y);
    font = b9->font();
    font.setPointSize(15);
    b9->setFont(font);
    b9->setFixedSize(size, size);

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
    QObject::connect(game, SIGNAL(clicked()),game, SLOT(Hide_itself()));
    QObject::connect(game, SIGNAL(Hide_another()), auth, SLOT(hide()));
    QObject::connect(game, SIGNAL(Show_another()), b1, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b2, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b3, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b4, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b5, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b6, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b7, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b8, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b9, SLOT(show()));


    QObject::connect(b1, SIGNAL(clicked()),b1, SLOT(SetValue()));
    QObject::connect(b2, SIGNAL(clicked()),b2, SLOT(SetValue()));
    QObject::connect(b3, SIGNAL(clicked()),b3, SLOT(SetValue()));
    QObject::connect(b4, SIGNAL(clicked()),b4, SLOT(SetValue()));
    QObject::connect(b5, SIGNAL(clicked()),b5, SLOT(SetValue()));
    QObject::connect(b6, SIGNAL(clicked()),b6, SLOT(SetValue()));
    QObject::connect(b7, SIGNAL(clicked()),b7, SLOT(SetValue()));
    QObject::connect(b8, SIGNAL(clicked()),b8, SLOT(SetValue()));
    QObject::connect(b9, SIGNAL(clicked()),b9, SLOT(SetValue()));

    /*
    QLabel *name1 = new QLabel(&w);
    lbl->setText(qle1->text());
    lbl->hide();
    lbl->move(10,100);
    font = lbl->font();
    font.setPointSize(15);
    lbl->setFont(font);
    lbl->setFixedSize(400, 100);

    QLabel *name2 = new QLabel(&w);
    lbl->setText(qle2->text());
    lbl->hide();
    lbl->move(10,100);
    font = lbl->font();
    font.setPointSize(15);
    lbl->setFont(font);
    lbl->setFixedSize(400, 100);

    QObject::connect(game, SIGNAL(Show_another()), name1, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), name2, SLOT(show()));
*/

    w.show();

    return a.exec();
}
