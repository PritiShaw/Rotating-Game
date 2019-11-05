#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QPair>
#include <QtCore/qmath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Clipping
    int clipWinX,clipWinY;

private slots:
private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
