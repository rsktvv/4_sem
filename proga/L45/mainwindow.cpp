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

int MainWindow::Color(QPoint point,QVector<QPoint> circles)
{
    int color=0;
    for(int i=0;i<circles.size();i++)
    {
       int distance=0;
        distance = qPow(point.x()-circles[i].x(),2)+qPow(point.y()-circles[i].y(),2);
        if (distance<=r*r/3)
            color++;
    }
    return color;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
      circles.append(event->pos());
      repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QPoint pixel;

   for (int i=0;i<circles.size();i++)
       painter.drawEllipse(circles[i].x()-r/2,circles[i].y()-r/2,r,r);

   for(pixel.setX(0);pixel.x()<geometry().width();pixel.rx()++)
       for(pixel.setY(0);pixel.y()<geometry().height();pixel.ry()++)
       {
           QColor colors[]={Qt::red,Qt::green,Qt::yellow,Qt::blue,Qt::gray};
           int index = Color(pixel,circles);
           pen.setColor(colors[index-2]);
           painter.setPen(pen);
           painter.drawPoint(pixel);
       }
}
