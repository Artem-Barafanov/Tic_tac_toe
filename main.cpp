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

    QLabel *lbl_winner = new QLabel(&w);
    lbl_winner->hide();
    lbl_winner->move(230,330);
    font = lbl_winner->font();
    font.setPointSize(30);
    lbl_winner->setFont(font);
    lbl_winner->setFixedSize(200, 200);
    lbl_winner->setAutoFillBackground(true);

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
    MyPushButton *b0 = new MyPushButton("",&w);
    b0->hide();
    b0->move(x,y);
    font = b0->font();
    font.setPointSize(15);
    b0->setFont(font);
    b0->setFixedSize(size, size);
    MyPushButton *b1 = new MyPushButton("",&w);
    b1->hide();
    b1->move(x+size,y);
    font = b1->font();
    font.setPointSize(15);
    b1->setFont(font);
    b1->setFixedSize(size, size);
    MyPushButton *b2 = new MyPushButton("",&w);
    b2->hide();
    b2->move(2*size+x,y);
    font = b2->font();
    font.setPointSize(15);
    b2->setFont(font);
    b2->setFixedSize(size, size);
    MyPushButton *b3 = new MyPushButton("",&w);
    b3->hide();
    b3->move(x,size+y);
    font = b3->font();
    font.setPointSize(15);
    b3->setFont(font);
    b3->setFixedSize(size, size);
    MyPushButton *b4 = new MyPushButton("",&w);
    b4->hide();
    b4->move(size+x,size+y);
    font = b4->font();
    font.setPointSize(15);
    b4->setFont(font);
    b4->setFixedSize(size, size);
    MyPushButton *b5 = new MyPushButton("",&w);
    b5->hide();
    b5->move(2*size+x,size+y);
    font = b5->font();
    font.setPointSize(15);
    b5->setFont(font);
    b5->setFixedSize(size, size);
    MyPushButton *b6 = new MyPushButton("",&w);
    b6->hide();
    b6->move(x,2*size+y);
    font = b6->font();
    font.setPointSize(15);
    b6->setFont(font);
    b6->setFixedSize(size, size);
    MyPushButton *b7 = new MyPushButton("",&w);
    b7->hide();
    b7->move(size+x,2*size+y);
    font = b7->font();
    font.setPointSize(15);
    b7->setFont(font);
    b7->setFixedSize(size, size);
    MyPushButton *b8 = new MyPushButton("",&w);
    b8->hide();
    b8->move(2*size+x,2*size+y);
    font = b8->font();
    font.setPointSize(15);
    b8->setFont(font);
    b8->setFixedSize(size, size);

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
    QObject::connect(game, SIGNAL(Show_another()), b0, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b1, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b2, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b3, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b4, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b5, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b6, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b7, SLOT(show()));
    QObject::connect(game, SIGNAL(Show_another()), b8, SLOT(show()));

    QObject::connect(b0, &QPushButton::clicked, [b0]() {
        b0->SetValue(0);
    });
    QObject::connect(b1, &QPushButton::clicked, [b1]() {
        b1->SetValue(1);
    });
    QObject::connect(b2, &QPushButton::clicked, [b2]() {
        b2->SetValue(2);
    });
    QObject::connect(b3, &QPushButton::clicked, [b3]() {
        b3->SetValue(3);
    });
    QObject::connect(b4, &QPushButton::clicked, [b4]() {
        b4->SetValue(4);
    });
    QObject::connect(b5, &QPushButton::clicked, [b5]() {
        b5->SetValue(5);
    });
    QObject::connect(b6, &QPushButton::clicked, [b6]() {
        b6->SetValue(6);
    });
    QObject::connect(b7, &QPushButton::clicked, [b7]() {
        b7->SetValue(7);
    });
    QObject::connect(b8, &QPushButton::clicked, [b8]() {
        b8->SetValue(8);
    });

    extern int Buttons[];
    extern int size_butt;
    QObject::connect(b0, &QPushButton::clicked, [b0]() {
        b0->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b1, &QPushButton::clicked, [b1]() {
        b1->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b2, &QPushButton::clicked, [b2]() {
        b2->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b3, &QPushButton::clicked, [b3]() {
        b3->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b4, &QPushButton::clicked, [b4]() {
        b4->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b5, &QPushButton::clicked, [b5]() {
        b5->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b6, &QPushButton::clicked, [b6]() {
        b6->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b7, &QPushButton::clicked, [b7]() {
        b7->CheckWin(Buttons, size_butt);
    });
    QObject::connect(b8, &QPushButton::clicked, [b8]() {
        b8->CheckWin(Buttons, size_butt);
    });

    QObject::connect(b0, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b1, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b2, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b3, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b4, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b5, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b6, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b7, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });
    QObject::connect(b8, &MyPushButton::Win, [lbl_winner](const QString result) {
        lbl_winner->setText(result);
        lbl_winner->show();
    });

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
