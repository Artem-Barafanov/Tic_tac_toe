#include "MyPushButton.h"

int MyPushButton::value = 1;

MyPushButton::MyPushButton(const QString &text, QWidget *w) : QPushButton(w){
    this->setText(text);
    }

void MyPushButton::Hide_itself(){
    this->hide();
    emit Hide_another();
    emit Show_another();
}

void MyPushButton::SetValue(){
    if (value == 1){
        this->setText("X");
        this->setEnabled(false);
        value = 0;
    }
    else {
        this->setText("O");
        this->setEnabled(false);
        value = 1;
    }
}


