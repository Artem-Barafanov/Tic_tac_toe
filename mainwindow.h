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
signals:
    void game_clicked();
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

};
#endif // MAINWINDOW_H
