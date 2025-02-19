#ifndef GRAPH_QWIDGET_H
#define GRAPH_QWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QStyle>
#include <QPainter>
#include <QStyleOption>
#include <QTime>

class graph_qWidget : public QWidget
{
    Q_OBJECT
public:
    explicit graph_qWidget(QWidget *parent = NULL);
    void paintEvent(QPaintEvent *);
    QVector<QPair<QPair<int,int> , int > > points = {};
    QVector<QPair<QString,QString> > recent = {};
    int ker;
    int x,y;
    int brushColorIdx;
    int linearSearch(int x,int y);

signals:
public slots:
};

#endif // GRAPH_QWIDGET_H
