#include "inodoroj.h"

inodoroJ::inodoroJ(int _tamano)
{
    tamano = _tamano;
}

int inodoroJ::gettamano()
{
    return tamano;
}

QRectF inodoroJ::boundingRect() const
{
    return QRectF(-tamano/2, -tamano/2, tamano, tamano);
}

void inodoroJ::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // Dibuja el inodoro
    painter->setBrush(Qt::white);
    painter->drawRect(-tamano/2, -tamano/2, tamano, tamano);
}
