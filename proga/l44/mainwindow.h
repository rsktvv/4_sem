#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QList>
#include <QMainWindow>

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
    Ui::MainWindow *ui;
    QList <QPoint> point;
    QList <int> l;



};
#endif // MAINWINDOW_H
