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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(points.size() > 0)
    {
        painter.setBrush(Qt::red);
        painter.drawEllipse(points[0], 5, 5);
        for(int i = 1; i < points.size(); i++)
        {
            painter.setBrush(Qt::black);
            painter.drawEllipse(points[i], 5 ,5);
            for (int j = 1; j < i; j++)
            {
                int tmp = (pow((points[i].x() - points[j].x()),2) + (pow((points[i].y() - points[j].y()),2)));
                len[i] += tmp;
                len[j] += tmp;
                //qDebug("len[i]=%d, len[j]=%d", len[i],len[j]);
            }


        }

        if(points.size() > 1)
        {
            int min = len[1];
            int pos = 1;
            for (int i = 2; i < len.size(); i++)
                if (min > len[i])
                {
                    min = len[i];
                    pos = i;
                }

            for (int i = 0; i < points.size(); i++)
                if (i != pos)
                    painter.drawLine(points[i], points[pos]);
         }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    points.push_back(QPoint(event->x(), event->y()));
    len.push_back(0);
    repaint();

}
