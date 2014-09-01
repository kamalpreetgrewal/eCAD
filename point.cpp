#include "point.h"
#include <QDebug>
#include "mainwindow.h"

Point::Point()
{

}

QRectF Point::boundingRect() const
{
    // outer most edges
    qreal penwidth = 1;
    return QRectF(-1 - penwidth /2, -1 - penwidth/2,
                  2 + penwidth, 2 + penwidth);
}

void Point:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    QPen paintpen(Qt::red);
    paintpen.setWidth(2);
    paintpen.setBrush(Qt::SolidPattern);
    painter->setPen(paintpen);
    painter->drawEllipse(boundingRect());
}
