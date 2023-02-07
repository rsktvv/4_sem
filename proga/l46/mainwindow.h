#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <QVector>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>
#include <QtMath>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int size=50;
    int score=0;
    int k=0;
    QVector <QPoint> mass;
};
#endif // MAINWINDOW_H
