#include"mainwindow.h"
#include"ui_mainwindow.h"
#include"dialog.h"
#include<QTimer>
#include<QLabel>
#include<unistd.h>
#include<ctime>
#include<QKeyEvent>
#include<QCloseEvent>
#include<QMessageBox>
QTimer *timer_count;
QTimer *timer_move1;
QTimer *timer_move2;
QTimer *timer_move3;
QTimer *timer_move4;
QTimer *timer_move5;
QTimer *timer_move6;
QTimer *timer_move7;
QTimer *timer_move8;
QTimer *timer_new;

MainWindow::MainWindow(QWidget *parent, Start &start) :
    QMainWindow(parent),
    w(start),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cnt = 30;
    score =0;

    x1=595;
    x2=595;
    x3=595;
    x4=595;
    x5=595;
    x6=595;
    x7=595;
    x8=595;
    y=135;
    av1=true;
    av2=true;
    av3=true;
    av4=true;
    av5=true;
    av6=true;
    av7=true;
    av8=true;

    srand(time(NULL));

    ui->setupUi(this);
    timer_count = new QTimer(this);
    timer_count->setInterval(1000);
    connect(timer_count,SIGNAL(timeout()),this,SLOT(timer_timeout()));
    timer_count->start();
    ui->lblnumber->setText(QString::number(cnt));


    timer_new = new QTimer(this);
    timer_new->setInterval((rand()%2)*1000);
    connect(timer_new,SIGNAL(timeout()),this,SLOT(newP()));
    timer_new->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key()){
        case Qt::Key_A:{
            int x_1 = ui->p1->x();
            int x_5 = ui->p5->x();
            if(x_1<140 && x_1>130){
                timer_move1->stop();
                ui->p1->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }else if(x_5<140 && x_5>130){
                timer_move5->stop();
                ui->p5->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }
            break;
        }
        case Qt::Key_S:{
            int x_2=ui->p2->x();
            int x_6=ui->p6->x();
            if(x_2<140 && x_2>130){
                timer_move2->stop();
                ui->p2->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }else if(x_6<140 && x_6>130){
                timer_move6->stop();
                ui->p6->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }
            break;
        }
        case Qt::Key_K:{
            int x_3=ui->p3->x();
            int x_7=ui->p7->x();
            if(x_3<140 && x_3>130){
                timer_move3->stop();
                ui->p3->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }else if(x_7<140 && x_7>130){
                timer_move7->stop();
                ui->p7->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }
            break;
        }
        case Qt::Key_L:{
            int x_4=ui->p4->x();
            int x_8=ui->p8->x();
            if(x_4<140 && x_4>130){
                timer_move4->stop();
                ui->p4->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }else if(x_8<140 && x_8>130){
                timer_move8->stop();
                ui->p8->move(QPoint(500,100));
                score++;
                ui->score->setText(QString::number(score));
            }
            break;
        }
    }
}

void MainWindow::timer_timeout()
{
    --cnt;
    ui->lblnumber->setText(QString::number(cnt));
    if(cnt==0)
    {
        timer_count->stop();
        cnt=30;
        dialog = new Dialog(this,w,*this);
        dialog -> show();

    }
}

void MainWindow::movep1()
{
    x1=x1-10;
    ui-> p1 -> move(QPoint(x1,y));
    if(x1<(-59))
    {
        timer_move1->stop();
        ui-> p1 -> move(QPoint(595,y));
        av1=true;
    }
}
void MainWindow::movep2()
{
    x2=x2-10;
    ui-> p2 -> move(QPoint(x2,y));
    if(x2<(-59))
    {
        timer_move2->stop();
        ui-> p2 -> move(QPoint(595,y));
        av2=true;
    }
}
void MainWindow::movep3()
{
    x3=x3-10;
    ui-> p3 -> move(QPoint(x3,y));
    if(x3<(-59))
    {
        timer_move3->stop();
        ui-> p3 -> move(QPoint(595,y));
        av3=true;
    }
}
void MainWindow::movep4()
{
    x4=x4-10;
    ui-> p4 -> move(QPoint(x4,y));
    if(x4<(-59))
    {
        timer_move4->stop();
        ui-> p4 -> move(QPoint(595,y));
        av4=true;
    }
}
void MainWindow::movep5()
{
    x5=x5-10;
    ui-> p5 -> move(QPoint(x5,y));
    if(x5<(-59))
    {
        timer_move5->stop();
        ui-> p5 -> move(QPoint(595,y));
        av5=true;
    }
}
void MainWindow::movep6()
{
    x6=x6-10;
    ui-> p6 -> move(QPoint(x6,y));
    if(x6<(-59))
    {
        timer_move6->stop();
        ui-> p6 -> move(QPoint(595,y));
        av6=true;
    }
}
void MainWindow::movep7()
{
    x7=x7-10;
    ui-> p7 -> move(QPoint(x7,y));
    if(x7<(-59))
    {
        timer_move7->stop();
        ui-> p7 -> move(QPoint(595,y));
        av7=true;
    }
}
void MainWindow::movep8()
{
    x8=x8-10;
    ui-> p8 -> move(QPoint(x8,y));
    if(x8<(-59))
    {
        timer_move8->stop();
        ui-> p8 -> move(QPoint(595,y));
        av8=true;
    }
}

void MainWindow::newP()
{
    int b;
    b=rand()%8;
    switch(b){
    case 0:
        if(av1==true){
            timer_move1 = new QTimer(this);
            timer_move1->setInterval(80);
            connect(timer_move1,SIGNAL(timeout()),this,SLOT(movep1()));
            timer_move1->start();
            av1=false;
        }
        break;
    case 1:
        if(av2==true){
            timer_move2 = new QTimer(this);
            timer_move2->setInterval(80);
            connect(timer_move2,SIGNAL(timeout()),this,SLOT(movep2()));
            timer_move2->start();
            av2=false;
        }
        break;
    case 2:
        if(av3==true){
            timer_move3 = new QTimer(this);
            timer_move3->setInterval(80);
            connect(timer_move3,SIGNAL(timeout()),this,SLOT(movep3()));
            timer_move3->start();
            av3=false;
        }
        break;
    case 3:
        if(av4==true){
            timer_move4 = new QTimer(this);
            timer_move4->setInterval(80);
            connect(timer_move4,SIGNAL(timeout()),this,SLOT(movep4()));
            timer_move4->start();
            av4=false;
        }
        break;
    case 4:
        if(av5==true){
            timer_move5 = new QTimer(this);
            timer_move5->setInterval(80);
            connect(timer_move5,SIGNAL(timeout()),this,SLOT(movep5()));
            timer_move5->start();
            av5=false;
        }
        break;
    case 5:
        if(av6==true){
            timer_move6 = new QTimer(this);
            timer_move6->setInterval(80);
            connect(timer_move6,SIGNAL(timeout()),this,SLOT(movep6()));
            timer_move6->start();
            av6=false;
        }
        break;
    case 6:
        if(av7==true){
            timer_move7 = new QTimer(this);
            timer_move7->setInterval(80);
            connect(timer_move7,SIGNAL(timeout()),this,SLOT(movep7()));
            timer_move7->start();
            av7=false;
        }
        break;
    case 7:
        if(av8==true){
            timer_move8 = new QTimer(this);
            timer_move8->setInterval(80);
            connect(timer_move8,SIGNAL(timeout()),this,SLOT(movep8()));
            timer_move8->start();
            av8=false;
        }
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
        w.stopgame();
        event->accept();
}



 /*   timer_move = new QTimer(this);
    timer_move->setInterval(100);
    connect(timer_move,SIGNAL(timeout()),this,SLOT(moveP()));
    timer_move->start();
  newpeople = new QLabel(this);
    newpeople->setPixmap(QPixmap("C:\pd2-Taiko\pd2-Taiko\2.png"));
    newpeople->setGeometry(x,y,w,h);
    newpeople->show();
    timer_move = new QTimer(this);
    timer_move->setInterval(60);
    connect(timer_move,SIGNAL(timeout()),this,SLOT(moveP(newpeople)));
    timer_move->start();
*/
