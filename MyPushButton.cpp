#include "MyPushButton.h"

MyPushButton::MyPushButton(const QString &text, QWidget *w) : QPushButton(w){
    this->setText(text);
    }

void MyPushButton::Hide_itself(){
    this->hide();
    emit Hide_another();
    emit Show_another();
}

