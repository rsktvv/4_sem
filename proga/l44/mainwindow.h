#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>
#include <QWidget>
#include <QCursor>
#include <QPoint>

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
   void mouseMoveEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QRect rect;
    int a=3;
    bool click=false;
};
#endif // MAINWINDOW_H
