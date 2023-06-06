#include "botellas.h"

Botellas::Botellas()
{

}

QRectF Botellas::boundingRect() const
{
    return QRectF(-35,-35,35,35);
}

void Botellas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(lleno){
        QPixmap pixmap;
        pixmap.load(":/images/cerveza.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
    else{
        QPixmap pixmap;
        pixmap.load(":/images/mug.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }

}

void Botellas::setBrush(const QBrush &brush)
{
    brush_ = brush;
}
