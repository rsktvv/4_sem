#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(point.size() > 0)
    {
        painter.drawEllipse(point[0], 5, 5);
        for(int i = 1; i < point.size(); i++)
        {
            painter.drawEllipse(point[i], 5 ,5);
            for (int j = 1; j < i; j++)
            {
                int a = (point[i].x() - point[j].x()) * (point[i].x() - point[j].x()) +
                          (point[i].y() - point[j].y()) * (point[i].y() - point[j].y());
                l[j] += a;
                l[i] += a;
            }
        }
        if(point.size() > 1)
        {
            int min = l[1];
            int pos = 1;
            for (int i = 2; i < l.size(); i++)
                if (min > l[i])
                {
                    min = l[i];
                    pos = i;
                }
            for (int i = 0; i < point.size(); i++)
                if (i != pos)
                    painter.drawLine(point[i], point[pos]);

        }

    }


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    point.push_back(QPoint(event->x(), event->y()));
    l.push_back(0);
repaint();

}
