#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QGraphicsItem>
#include <QPainter>

class Enemigos: public QGraphicsItem
{
public:
    Enemigos();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ENEMIGOS_H
