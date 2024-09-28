#include <QtWidgets>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *tic = new QLabel("Крестики-нолики", centralWidget());
    tic->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    tic->move(15,30);
    QFont font = tic->font();
    font.setPointSize(30);
    tic->setFont(font);
    tic->setFixedSize(550, 500);
    tic->setAutoFillBackground(true);

    MyPushButton *game = new MyPushButton("Игра",centralWidget());
    game->setEnabled(false);
    game->setStyleSheet("color: grey");
    font = game->font();
    font.setPointSize(20);
    game->setFont(font);
    game->setFixedSize(200, 50);
    game->move(80, 100);
    game->setAutoFillBackground(true);

    MyPushButton *auth = new MyPushButton("Авторизация", centralWidget());
    font = auth->font();
    font.setPointSize(20);
    auth->setFont(font);
    auth->setFixedSize(200, 50);
    auth->move(300, 100);
    auth->setAutoFillBackground(true);

    MyPushButton *ok = new MyPushButton("OK", centralWidget());
    ok->hide();
    font = ok->font();
    font.setPointSize(20);
    ok->setFont(font);
    ok->setFixedSize(200, 50);
    ok->move(300, 300);

    QLabel *lbl = new QLabel(centralWidget());
    lbl->setText("Введите имена игроков:");
    lbl->hide();
    lbl->move(10,100);
    font = lbl->font();
    font.setPointSize(15);
    lbl->setFont(font);
    lbl->setFixedSize(400, 100);

    QLineEdit *qle1 = new QLineEdit(centralWidget());
    qle1->hide();
    qle1->move(250,130);
    font = qle1->font();
    font.setPointSize(15);
    qle1->setFont(font);
    qle1->setFixedSize(250, 35);

    QLineEdit *qle2 = new QLineEdit(centralWidget());
    qle2->hide();
    qle2->move(250,180);
    font = qle2->font();
    font.setPointSize(15);
    qle2->setFont(font);
    qle2->setFixedSize(250, 35);

    QObject::connect(auth, &MyPushButton::clicked, auth, &MyPushButton::Hide_itself);
    QObject::connect(auth, &MyPushButton::Hide_another,game, &MyPushButton::hide);
    QObject::connect(auth, &MyPushButton::Show_another, lbl, &QLabel::show);


    QObject::connect(auth, &MyPushButton::Show_another,qle1, &QWidget::show);
    QObject::connect(qle1, &QLineEdit::editingFinished, [=]() {
        QString text1 = qle1->text();
        qle1->setEnabled(false);
    });
    QObject::connect(auth, &MyPushButton::Show_another,qle2, &QWidget::show);
    QObject::connect(qle2, &QLineEdit::editingFinished, [=]() {
        QString text2 = qle2->text();
        qle2->setEnabled(false);
    });

    QObject::connect(auth, &MyPushButton::Show_another,ok, &MyPushButton::show);
    QObject::connect(ok, &MyPushButton::clicked,ok, &MyPushButton::Hide_itself);
    QObject::connect(ok, &MyPushButton::Hide_another,lbl, &QLabel::hide);
    QObject::connect(ok, &MyPushButton::Hide_another,qle1, &QWidget::hide);
    QObject::connect(ok, &MyPushButton::Hide_another,qle2, &QWidget::hide);
    QObject::connect(ok, &MyPushButton::Show_another,auth, &MyPushButton::show);
    QObject::connect(ok, &MyPushButton::Show_another, [game]() {
        game->show();
        game->setEnabled(true);
        game->setStyleSheet("background-color: white; color: black;");
    });


    QObject::connect(game, &MyPushButton::clicked,game, [this] () {
        this->close();});
    QObject::connect(game, &MyPushButton::clicked, [this] () {
        emit game_clicked();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
