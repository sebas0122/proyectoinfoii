#include "personaje3.h"

Personaje3::Personaje3()
{

}

QRectF Personaje3::boundingRect() const
{
    return QRectF(-20, -20, 40, 40); // Ancho: 40, Alto: 40
}

void Personaje3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkGreen);
    //painter->drawRect(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/images/usuario3.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Personaje3::velocidades()
// calcula las velocidades
{
    vy = vy + (GRAV*DT);
}

void Personaje3::posiciones()
// calcula y Actualiza las posiciones
{
    _y = _y + (vy * DT) + (0.5 * GRAV * pow(DT,2));
    setPos(x(), (_y));
    qDebug() << "Posición y:" << _y;
}
