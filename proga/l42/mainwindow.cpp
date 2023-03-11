#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msgBox;
    if(event->modifiers() & Qt::ControlModifier)
    {
        boardX=event->x();
        boardY=event->y();

    }
    else if(event->modifiers() & Qt::ShiftModifier)
    {
        x = event->x();
        y = event->y();

    }
    if((x<boardX)||(x>boardX+(a*n))||(y<boardY)||(y>boardY+(a*n)))
        msgBox.setText("не попал");
    else
    {
        h=(x-boardX)/a;
        k=(y-boardY)/a;

        msgBox.setText(QString(65+h) + QString(56-k));
    }
    msgBox.exec();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QString s;
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i+j)%2 == 0)
            {
                painter.setBrush(QColor(255,255,255));
                painter.drawRect(boardX+a*i,boardY+a*j,a,a);
            }
            else
            {
                painter.setBrush(QColor(0,0,0));
                painter.drawRect(boardX+a*i,boardY+a*j,a,a);
            }
        }
        char x ='A'+i;
        "ABCDEGJH"[0];
        QChar asd;
       painter.drawText(boardX*i,boardY-a/2,QString(asd));
      //painter.drawText(boardY-a/2,boardY*i,QString(56-i));

    }
}

