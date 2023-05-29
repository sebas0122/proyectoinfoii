#include "obstaculo.h"

Obstaculo::Obstaculo()
{

}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(-35,-35,35,35);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush_);
    painter->drawRect(boundingRect());

}

void Obstaculo::setBrush(const QBrush &brush)
{
    brush_ = brush;
}
