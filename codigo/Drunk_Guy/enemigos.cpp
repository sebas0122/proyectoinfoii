#include "enemigos.h"

Enemigos::Enemigos()
{

}

QRectF Enemigos::boundingRect() const
{
    return QRectF(-20, -20, 40, 40);
}

void Enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkRed);
    //painter->drawRect(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/images/enemigo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

