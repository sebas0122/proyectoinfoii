#include "botellas.h"

Botellas::Botellas()
{
    brush_ = Qt::darkGray;
}

QRectF Botellas::boundingRect() const
{
    return QRectF(-35,-35,35,35);
}

void Botellas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush_);
    painter->drawRect(boundingRect());

}

void Botellas::setBrush(const QBrush &brush)
{
    brush_ = brush;
}
