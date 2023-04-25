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
    point = QPoint(event->x(),event->y());
    for(int i=0;i<geometry().width();i+=a)
        for(int j=0;j<geometry().height();j+=a)
            mass.append(QRect(i,j,a,a));
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(int i=0;i<mass.size();i++)
        painter.drawRect(mass[i]);

    for(int i=0;i<mass.size();i++)
        if(pow(mass[i].topLeft().x()-point.x(),2)+pow(mass[i].topLeft().y()-point.y(),2)<=r*r)
            if(pow(mass[i].topRight().x()-point.x(),2)+pow(mass[i].topRight().y()-point.y(),2)<=r*r)
                if(pow(mass[i].bottomLeft().x()-point.x(),2)+pow(mass[i].bottomLeft().y()-point.y(),2)<=r*r)
                    if(pow(mass[i].bottomRight().x()-point.x(),2)+pow(mass[i].bottomRight().y()-point.y(),2)<=r*r)
                        painter.fillRect(mass[i],Qt::blue);
          painter.drawEllipse(point,r,r);
      }


