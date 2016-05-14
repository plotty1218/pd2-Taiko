#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"mainwindow.h"
#include"start.h"
namespace Ui {
class Dialog;
}
class MainWindow;
class Start;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent ,Start &start,MainWindow &newgame);
    ~Dialog();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Start &w;
    MainWindow &newgame;
};

#endif // DIALOG_H
