#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Field)
{
    ui->setupUi(this);
    int x = 150;
    int y = 100;
    int size = 90;

    QLabel *lbl_winner = new QLabel(this);
    lbl_winner->hide();
    lbl_winner->move(230,330);
    QFont font;
    font = lbl_winner->font();
    font.setPointSize(30);
    lbl_winner->setFont(font);
    lbl_winner->setFixedSize(200, 200);
    lbl_winner->setAutoFillBackground(true);

    MyPushButton *b0 = new MyPushButton("", this);
    MyPushButton *b1 = new MyPushButton("", this);
    MyPushButton *b2 = new MyPushButton("", this);
    MyPushButton *b3 = new MyPushButton("", this);
    MyPushButton *b4 = new MyPushButton("", this);
    MyPushButton *b5 = new MyPushButton("", this);
    MyPushButton *b6 = new MyPushButton("", this);
    MyPushButton *b7 = new MyPushButton("", this);
    MyPushButton *b8 = new MyPushButton("", this);
    QList<MyPushButton*> cells = {b0, b1, b2, b3, b4, b5, b6, b7, b8};

    int mooving[9][2] = {{x,y}, {x+size,y}, {2*size+x,y}, {x,size+y}, {size+x,size+y}, {2*size+x,size+y}, {x,2*size+y},
                         {size+x,2*size+y}, {2*size+x,2*size+y}};
    for (int i = 0; i<cells.size(); i++){
        cells[i]->show();
        cells[i]->move(mooving[i][0], mooving[i][1]);
        font = cells[i]->font();
        font.setPointSize(15);
        cells[i]->setFont(font);
        cells[i]->setFixedSize(size, size);
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

Field::~Field()
{
    delete ui;
}
