#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QMessageBox msg;
    if(k<5)
    {
        mass.append(event->pos());
        if(10-2*(int)sqrt(pow(mass[k].x()-geometry().width()/2,2)+pow(mass[k].y()-geometry().height()/2,2))/size >= 0)
            score+=10-2*(int)sqrt(pow(mass[k].x()-geometry().width()/2,2)+pow(mass[k].y()-geometry().height()/2,2))/size;
        k++;
    }
    if(k==5)
    {
        msg.setText(QString("%1").arg(score));
        msg.exec();
    }
    repaint();



}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QString s;

    for(int i=1;i<11;i++)
    {
        painter.drawEllipse(geometry().width()/2-i*size/2,geometry().height()/2-i*size/2,i*size,i*size);
        if(i==1)
            painter.drawText(geometry().width()/2-6,geometry().height()/2+3,s.sprintf("%d",10));
        if(i>1)
        {
            painter.drawText(geometry().width()/2+10+(i-1)*size/2,geometry().height()/2+5,s.sprintf("%d",11-i));
            painter.drawText(geometry().width()/2-15-(i-1)*size/2,geometry().height()/2+5,s.sprintf("%d",11-i));
            painter.drawText(geometry().width()/2-5 ,geometry().height()/2+15+(i-1)*size/2,s.sprintf("%d",11-i));
            painter.drawText(geometry().width()/2-5 ,geometry().height()/2-5-(i-1)*size/2,s.sprintf("%d",11-i));
        }
    }


    for(int i=0;i<mass.size();i++)
    {
        pen.setWidth(5);
        painter.setPen(pen);
        painter.drawPoint(mass[i]);
    }


}
MainWindow::~MainWindow()
{
    delete ui;
}

