#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <QPoint>
#include <QColor>
#include <QMessageBox>
#include <QMouseEvent>
#include <qDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    int a = 50;
    int n = 8;
    int boardX,boardY;
    int x,y;
    int h,k;
};
#endif // MAINWINDOW_H
