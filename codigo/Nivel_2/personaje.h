#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#define DT 0.1

class Personaje: public QGraphicsItem
{
public:
    Personaje();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void velocidades();
    void posiciones();
    float _y=380, v=-1, a;
};

#endif // PERSONAJE_H
