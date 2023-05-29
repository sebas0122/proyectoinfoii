#include "gasolina.h"

Gasolina::Gasolina()
{
    brush_ = Qt::darkGray;
}

QRectF Gasolina::boundingRect() const
{
    return QRectF(-35,-35,35,35);
}

void Gasolina::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush_);
    painter->drawRect(boundingRect());

}

void Gasolina::setBrush(const QBrush &brush)
{
    brush_ = brush;
}
