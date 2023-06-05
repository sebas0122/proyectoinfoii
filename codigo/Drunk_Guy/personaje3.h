#ifndef PERSONAJE3_H
#define PERSONAJE3_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#define EY 6000
#define GRAV 9.8
#define DT 0.1
class Personaje3: public QGraphicsItem
{
public:
    Personaje3();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void velocidades();
    void posiciones();
    float _y=380, vy=-50;

};

#endif // PERSONAJE3_H
