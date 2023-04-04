#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCursor cursi(Qt::OpenHandCursor);

    setMouseTracking(true);
    centralWidget()->setMouseTracking(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    rect=QRect(100,100,100,100);
    QPainter painter(this);
    painter.drawRect(rect);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    click=true;
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::setCursor(QCursor());
    if(abs(event->x()-rect.left())<=a)
        {
            if((abs(event->y()-rect.top())<=a))
            {
                QWidget::setCursor(QCursor(Qt::SizeFDiagCursor));
                if(click)
                    rect.setTopLeft(event->pos());
            }
            else if(abs(event->y()-rect.bottom())<=a)
            {
                QWidget::setCursor(QCursor(Qt::SizeBDiagCursor));
                if(click)
                    rect.setBottomLeft(event->pos());
            }
            else
            {
                QWidget::setCursor(QCursor(Qt::SizeHorCursor));
                if(click)
                    rect.setLeft(event->x());
            }
        }
        else if(abs(event->x()-rect.right())<=a)
        {
            if(abs(event->y()-rect.bottom())<=a)
            {
                QWidget::setCursor(QCursor(Qt::SizeFDiagCursor));
                if(click)
                {
                    rect.setBottomRight(event->pos());
                }
            }
            else if(abs(event->y()-rect.top())<=a)
            {
                QWidget::setCursor(QCursor(Qt::SizeBDiagCursor));
                if(click)
                {
                    rect.setTopRight(event->pos());
                }
            }
            else
            {
                QWidget::setCursor(QCursor(Qt::SizeHorCursor));
                if(click)
                   rect.setRight(event->x());
            }

        }
        else if(abs(event->y()-rect.top())<=a)
        {
            QWidget::setCursor(QCursor(Qt::SizeVerCursor));
            if(click)
                rect.setTop(event->y());
        }
        else if(abs(event->y()-rect.bottom())<=a)
        {
            QWidget::setCursor(QCursor(Qt::SizeVerCursor));
            if(click)
                rect.setBottom(event->y());
        }
    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    click=false;
}

