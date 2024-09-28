#ifndef FIELD_H
#define FIELD_H

#include <QtWidgets>
#include "MyPushButton.h"

namespace Ui {
class Field;
}

class Field : public QWidget
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr);
    ~Field();

private:
    Ui::Field *ui;
    MyPushButton *b0;
    MyPushButton *b1;
    MyPushButton *b2;
    MyPushButton *b3;
    MyPushButton *b4;
    MyPushButton *b5;
    MyPushButton *b6;
    MyPushButton *b7;
    MyPushButton *b8;
};

#endif // FIELD_H
