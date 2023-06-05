#ifndef PERSONAJE2_H
#define PERSONAJE2_H

#include <QGraphicsItem>
#include <QPainter>
#define DT 0.1

class Personaje2: public QGraphicsItem
{
public:
    Personaje2();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void velocidades();
    void posiciones();
    float _y=380, v=-1, a;
};

#endif // PERSONAJE2_H
