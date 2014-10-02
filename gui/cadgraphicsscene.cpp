#include "cadgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

CadGraphicsScene::CadGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    setFlags();
}


void CadGraphicsScene::setFlags()
{
    mFirstClick = true;
    mSecondClick = false;
    mPaintFlag = false;
}

void CadGraphicsScene::setMode(Mode mode)
{
    entityMode = mode;
}

void CadGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    Point *pointItem;
    Line *lineItem;
    switch (entityMode){
    case NoMode:
        qDebug() << "No Mode" ;
        break;

    case PointMode:
        pointItem = new Point;
        addItem(pointItem);
        pointItem->setPos(mouseEvent->scenePos());
        //      emit createdPoint(pointItem);
        break;

    case LineMode:
        if(mFirstClick){
            pointItem = new Point;
            addItem(pointItem);
            pointItem->setPos(mouseEvent->scenePos());
            start_p = mouseEvent->scenePos();
            mFirstClick = false;
            mSecondClick = true;
        }

        else if(!mFirstClick && mSecondClick){
            pointItem = new Point;
            addItem(pointItem);
            pointItem->setPos(mouseEvent->scenePos());
            end_p = mouseEvent->scenePos();
            mPaintFlag = true;
            mSecondClick = false;
        }
        if(mPaintFlag)
        {
            lineItem = new Line(start_p, end_p);
            addItem(lineItem);
//          entityMode = NoMode;
            setFlags();
        }

        break;


    default:
        ;
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void CadGraphicsScene::writeStream(QXmlStreamWriter *stream)
{
    foreach(QGraphicsItem* item, items())
    {
//        if(item->type() == Point::Type )
//        {
            Point* myItem = dynamic_cast<Point*>(item);
            stream->writeStartElement("Point");
            stream->writeAttribute("xCoord", QString::number(myItem->x()));
            stream->writeAttribute("yCoord", QString::number(myItem->y()));
            stream->writeEndElement();  //end of Point Item
//        }
    }
}

void CadGraphicsScene::readStream(QXmlStreamReader *stream)
{
    while (!stream->atEnd())
    {
        stream->readNext();
        if (stream->isStartElement() && stream->name() == "Point")
        {
            qreal x = 0.0, y = 0.0;
            foreach(QXmlStreamAttribute attribute, stream->attributes())
            {
                if (attribute.name() == "xCoord") x = attribute.value().toString().toDouble();
                if (attribute.name() == "yCoord") y = attribute.value().toString().toDouble();
            }
            Point *myPoint = new Point;
            addItem(myPoint);
            myPoint->setPos(x,y);
        }
    }
}