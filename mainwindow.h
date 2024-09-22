#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "MyPushButton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *tic;
    MyPushButton *game;
    MyPushButton *auth;
    MyPushButton *ok;
    QLabel *lbl;
    QLabel *lbl_winner;
    QLineEdit *qle1;
    QLineEdit *qle2;
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
#endif // MAINWINDOW_H
