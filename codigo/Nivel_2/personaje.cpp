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

void Personaje::velocidades()
// calcula las velocidades
{
    v = v + (a*DT);
    qDebug() << "Velocidad: "<< v;
}

void Personaje::posiciones()
// calcula y Actualiza las posiciones
{
    _y = _y + (v * DT) + (0.5 * a * pow(DT,2));
    setPos(x(), (_y));
    //qDebug() << "Posición y:" << _y;
}
