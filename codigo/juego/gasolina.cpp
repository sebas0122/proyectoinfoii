#include "gasolina.h"

Gasolina::Gasolina()
{

}

QRectF Gasolina::boundingRect() const
{
    return QRectF(-35,-35,35,35);
}

void Gasolina::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
