#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

