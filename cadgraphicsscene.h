#ifndef CADGRAPHICSSCENE_H
#define CADGRAPHICSSCENE_H

#include <QGraphicsScene>

class cadgraphicsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit cadgraphicsscene(QObject *parent = 0);

signals:

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

};

#endif // CADGRAPHICSSCENE_H