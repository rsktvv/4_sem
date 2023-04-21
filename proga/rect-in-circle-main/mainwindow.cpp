#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    x = event->x();
    y = event->y();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QRect screen = frameGeometry();
    QPainter painter(this);

    for(int i = 0 ; i < screen.width(); i+=20){
        for(int j = 0; j < screen.height(); j+=20){
                painter.drawRect(i,j,20,20);
                if(((qPow((i-x),2)+qPow((j-y),2)<=10000 && qPow(((i+20)-x),2)+qPow(((j+20)-y),2)<=10000)))
                {
                    painter.fillRect(i,j,20,20,Qt::blue);
                }
             }
        }


    painter.drawEllipse(x-100,y-100,200,200);

}


