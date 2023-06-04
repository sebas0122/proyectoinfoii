#ifndef GASOLINA_H
#define GASOLINA_H

#include <QGraphicsItem>
#include <QPainter>

class Gasolina: public QGraphicsItem
{
public:
    Gasolina();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


};

#endif // GASOLINA_H
