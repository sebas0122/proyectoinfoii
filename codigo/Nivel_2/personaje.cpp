#include "personaje.h"

Personaje::Personaje()
{

}

QRectF Personaje::boundingRect() const
{
    return QRectF(-20, -20, 40, 40); // Ancho: 40, Alto: 40
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawRect(boundingRect());

}
