#include "mainwindow.hh"
#include "ui_mainwindow.h"

int it = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arr.push_back("1.jpeg");
    arr.push_back("2.jpg");
    arr.push_back("3.jpg");
    setImage(arr[it]);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(it < (arr.size()-1))
    {
        setImage(arr[++it]);
    }
    else
    {
        it = 0;
        setImage(arr[it]);
    }
}

void MainWindow::setImage(QString name)
{
    QPixmap pix("C:/projects Qt/untitled1/"+name);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_2_clicked()
{
    if(it != 0)
    {
        setImage(arr[--it]);
    }
    else
    {
        it = (arr.size()-1);
        setImage(arr[it]);
    }
}

