#include "obstaculo.h"

Obstaculo::Obstaculo(int _tamano)
{
    tamano=_tamano;
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(-tamano,-tamano,tamano,tamano);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush_);
    painter->drawRect(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/images/carroEnemigo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

void Obstaculo::setBrush(const QBrush &brush)
{
    brush_ = brush;
}
