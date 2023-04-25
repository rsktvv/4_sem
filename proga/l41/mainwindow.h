#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QRect>
#include <QtMath>
#include <QVector>
#include <QPoint>
#include <QDesktopWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int r=100;
    int a=20;
    QPoint point;
    QVector <QRect> mass;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
