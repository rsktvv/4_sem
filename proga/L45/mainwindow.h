#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QRect>
#include <QtMath>
#include <QVector>
#include <QPoint>
#include <QDesktopWidget>
#include <QPainter>

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
    int Color(QPoint point,QVector<QPoint> circles);

private:
    Ui::MainWindow *ui;
    QVector <QPoint> circles;
    int r=120;
};
#endif // MAINWINDOW_H
