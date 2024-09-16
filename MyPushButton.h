#pragma once
#include <QtWidgets>

class MyPushButton : public QPushButton {
    Q_OBJECT
public:
    MyPushButton(const QString &text, QWidget *w);
public slots:
    void Hide_itself();
signals:
    void Hide_another();
    void Show_another();
    void Set_Able_another();
};
