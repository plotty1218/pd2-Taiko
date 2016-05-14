#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include"start.h"
#include"dialog.h"
namespace Ui {
class MainWindow;
}
class Start;
class Dialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT

friend class Dialog;

public:
    explicit MainWindow(QWidget *parent , Start &start);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

private slots:
    void timer_timeout();
    void movep1();
    void movep2();
    void movep3();
    void movep4();
    void movep5();
    void movep6();
    void movep7();
    void movep8();
    void newP();
    void low();

private:
    int cnt;
    int score;
    Ui::MainWindow *ui;
    Start &w;
    int x1,x2,x3,x4,x5,x6,x7,x8,y;
    bool av1,av2,av3,av4,av5,av6,av7,av8;
    void keyPressEvent(QKeyEvent * event);
    Dialog * dialog;
};

#endif // MAINWINDOW_H
