#include "inodoro.h"

inodoro::inodoro(int _tamano)
{
    tamano = _tamano;
    timeri = new QTimer();
    connect(timeri, SIGNAL(timeout()), this, SLOT(variacionarea()));
    timeri->start(1000);
}

int inodoro::gettamano() const
{
    return tamano;
}

QRectF inodoro::boundingRect() const
{
    return QRectF(-tamano/2, -tamano/2, tamano, tamano);
}

void inodoro::variacionarea()
{
    // Reduce el tamaño del inodoro
    tamano -= 10;
    QRect(-tamano/2, -tamano/2, tamano, tamano);

    // Detiene el temporizador si el tamaño llega a 0
    if (tamano <= 0){
        timeri->stop();
        tamano = 0;
    }
    prepareGeometryChange();
}

void inodoro::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // Dibuja el inodoro
    painter->setBrush(Qt::white);
    painter->drawRect(-tamano/2, -tamano/2, tamano, tamano);
}
