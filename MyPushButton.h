#pragma once
#include <QtWidgets>

class MyPushButton : public QPushButton {
    Q_OBJECT
public:
    static int value;
    MyPushButton(const QString &text, QWidget *w);
public slots:
    void CheckWin(int arr[],const int i);
    void Hide_itself();
    void SetValue(const int i);
signals:
    void Hide_another();
    void Show_another();
    void Set_Able_another();
    void Win(QString x);
};
