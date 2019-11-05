#include "graph_qwidget.h"
#include "mainwindow.h"
#include <cstdlib>

graph_qWidget::graph_qWidget(QWidget *parent) : QWidget(parent)
{
    ker = 30;
    brushColorIdx = 0;
}
int graph_qWidget::linearSearch(int x,int y){    
    for(int i=points.size()-1;i>-1;i--){
        QPair<QPair<int,int>, int>  it = points[i];
        if(it.first.first == x && it.first.second == y)
            return it.second;
    }
    return -1;
}

void graph_qWidget::paintEvent(QPaintEvent *pe) {
    QStyleOption styleOption;
    styleOption.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &styleOption, &painter, this);
    int size = this->width();
    int half = size/2;

    if ( ker==1 ){
        painter.setPen(QPen(Qt::black, ker, Qt::DotLine));
        painter.drawLine(half,0,half,size);
        painter.drawLine(0,half,size,half);
    }
    else {
        for(int i = -1*half; i<=half; i+=1){
            if (abs(i)%ker!=0)
                continue;
            painter.setPen(QPen(QColor(33,46,54), 2.5, Qt::SolidLine));
            painter.drawLine(i+half,0,i+half,size);
            painter.drawLine(0,i+half,size,i+half);
        }

    }
    QVector<QPair<QPair<int,int>, int> >::iterator it;
    QColor brushColor;
    for(it =  points.begin(); it != points.end() ; ++it){
        switch (it->second) {
        case 0:
            brushColor = Qt::yellow;
            break;
        case 1:
            brushColor = Qt::red;
            break;
        case 2:
            brushColor = Qt::black;
            break;
        case 3:
            brushColor = Qt::blue;
            break;
        case 4:
            brushColor = Qt::white;
            break;
        }
        painter.setPen(QPen(brushColor, ker, Qt::SolidLine));
        painter.drawPoint(ker*it->first.first + width()/2-ker/2,height()/2 -  ker*it->first.second-ker/2);
    }
}
