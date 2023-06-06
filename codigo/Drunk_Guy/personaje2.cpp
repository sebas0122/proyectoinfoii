#include "personaje2.h"

Personaje2::Personaje2()
{

}

QRectF Personaje2::boundingRect() const
{
    return QRectF(-20, -20, 40, 40); // Ancho: 40, Alto: 40
}


void Personaje2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/images/usuario2.png");

    QPixmap pixmapInvertido = pixmap.transformed(QTransform().scale(1, -1)); // Invertir en el eje Y

    painter->drawPixmap(boundingRect(), pixmapInvertido, pixmapInvertido.rect());
}

void Personaje2::velocidades()
// calcula las velocidades
{
    v = v + (a*DT);
    qDebug() << "Velocidad: "<< v;
}

void Personaje2::posiciones()
// calcula y Actualiza las posiciones
{
    _y = _y + (v * DT);
    setPos(x(), _y);
    //qDebug() << "Posición y:" << _y;
}
