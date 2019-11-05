#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph_qwidget.h"
#define insertPoint(x,y) ui->graph->points.push_back(QPair<QPair<int , int>,int >(QPair< int , int >(x,y),ui->graph->brushColorIdx))

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusLabel = new QLabel("");
    statusLabel->setMinimumWidth(75);
    connect(ui->graph, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->graph, SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->graph, SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));
    ui->graph->resize(720,720);
}

MainWindow::~MainWindow()
{
    delete ui;
}

