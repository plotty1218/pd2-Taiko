#include "start.h"
#include "ui_start.h"
#include "mainwindow.h"

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{
    newgame = new MainWindow(this, *this);
    newgame->show();
}

void Start::on_pushButton_2_clicked()
{
    this->close();
}
void Start::stopgame()
{
    delete newgame;
}
