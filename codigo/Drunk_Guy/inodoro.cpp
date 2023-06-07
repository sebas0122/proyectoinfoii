#include "inodoro.h"

inodoro::inodoro(int _tamano)
{
    tamano = _tamano;
}

int inodoro::gettamano()
{
    return tamano;
}

QRectF inodoro::boundingRect() const
{
    return QRectF(-tamano/2, -tamano/2, tamano, tamano);
}

void inodoro::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // Dibuja el inodoro
    //painter->setBrush(Qt::white);
    //painter->drawRect(-tamano/2, -tamano/2, tamano, tamano);
    QPixmap pixmap;
    pixmap.load(":/images/inodoro.jpg");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
