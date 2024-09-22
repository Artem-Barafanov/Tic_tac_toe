#include <QtWidgets>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MyPushButton.h"

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

    QLabel *lbl_winner = new QLabel(centralWidget());
    lbl_winner->hide();
    lbl_winner->move(230,330);
    font = lbl_winner->font();
    font.setPointSize(30);
    lbl_winner->setFont(font);
    lbl_winner->setFixedSize(200, 200);
    lbl_winner->setAutoFillBackground(true);

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

    int x = 150;
    int y = 100;
    int size = 90;

    MyPushButton *b0 = new MyPushButton("",centralWidget());
    MyPushButton *b1 = new MyPushButton("",centralWidget());
    MyPushButton *b2 = new MyPushButton("",centralWidget());
    MyPushButton *b3 = new MyPushButton("",centralWidget());
    MyPushButton *b4 = new MyPushButton("",centralWidget());
    MyPushButton *b5 = new MyPushButton("",centralWidget());
    MyPushButton *b6 = new MyPushButton("",centralWidget());
    MyPushButton *b7 = new MyPushButton("",centralWidget());
    MyPushButton *b8 = new MyPushButton("",centralWidget());
    QList<MyPushButton*> cells = {b0, b1, b2, b3, b4, b5, b6, b7, b8};

    int mooving[9][2] = {{x,y}, {x+size,y}, {2*size+x,y}, {x,size+y}, {size+x,size+y}, {2*size+x,size+y}, {x,2*size+y},
                       {size+x,2*size+y}, {2*size+x,2*size+y}};
    for (int i = 0; i<cells.size(); i++){
        cells[i]->hide();
        cells[i]->move(mooving[i][0], mooving[i][1]);
        font = cells[i]->font();
        font.setPointSize(15);
        cells[i]->setFont(font);
        cells[i]->setFixedSize(size, size);
    }

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
    QObject::connect(game, &MyPushButton::clicked,game, &MyPushButton::Hide_itself);
    QObject::connect(game, &MyPushButton::Hide_another, auth, &MyPushButton::hide);
    for (int i = 0; i<cells.size(); ++i) {
        QObject::connect(game, &MyPushButton::Show_another, cells[i], &MyPushButton::show);
    }

    for (int i = 0; i<cells.size(); ++i) {
        QObject::connect(cells[i], &QPushButton::clicked, [cells, i]() {
            cells[i]->SetValue(i);
        });
    }

    extern int Buttons[];
    extern int size_butt;

    for (int i = 0; i<cells.size(); ++i) {
        QObject::connect(cells[i], &QPushButton::clicked, [cells, i]() {
            cells[i]->CheckWin(Buttons, size_butt);
        });
    }

    for (int i = 0; i<cells.size(); ++i) {
        QObject::connect(cells[i], &MyPushButton::Win, [lbl_winner](const QString result) {
            lbl_winner->setText(result);
            lbl_winner->show();
        });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
