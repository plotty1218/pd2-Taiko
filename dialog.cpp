#include "dialog.h"
#include "ui_dialog.h"
#include"mainwindow.h"
Dialog::Dialog(QWidget *parent,Start &start,MainWindow &newgame) :
    QDialog(parent),
    w(start),
    newgame(newgame),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->score->setText(QString::number(newgame.score));
    if(newgame.score>=8){
        ui->highscore->move(QPoint(160,110));
        ui->highscore2->move(QPoint(0,0));
    }else{
        ui->lowscore->move(QPoint(160,110));
        ui->lowscore2->move(QPoint(0,0));
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    w.stopgame();
}

void Dialog::on_pushButton_clicked()
{
    Start n;
    n.show();
    w.stopgame();

}
void Dialog::closeEvent(QCloseEvent *event)
{
    w.stopgame();
}
