#include "MyPushButton.h"

int MyPushButton::value = 1;
int Buttons[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
int size_butt = 9;

MyPushButton::MyPushButton(const QString &text, QWidget *w) : QPushButton(w){
    this->setText(text);
    }

void MyPushButton::Hide_itself(){
    this->hide();
    emit Hide_another();
    emit Show_another();
}

void MyPushButton::SetValue(const int i){
    if (value == 1){
        this->setText("X");
        this->setEnabled(false);
        value = 0;
        Buttons[i] = 1;
    }
    else {
        this->setText("O");
        this->setEnabled(false);
        value = 1;
        Buttons[i] = 0;
    }
}

void MyPushButton::CheckWin(int arr[],const int i){
    if ((arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 1) ||
        (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 1) ||
        (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 1) ||
        (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 1) ||
        (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 1) ||
        (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 1) ||
        (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 1) ||
        (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 1)) {
        emit Win("X Won");
    }
    else if ((arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 0) ||
             (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 0) ||
             (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 0) ||
             (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 0) ||
             (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 0) ||
             (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 0) ||
             (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 0) ||
             (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 0)) {
        emit Win("O Won");
    }
}

