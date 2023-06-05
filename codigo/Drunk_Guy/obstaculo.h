#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsItem>
#include <QPainter>

class Obstaculo: public QGraphicsItem
{
public:
    Obstaculo();
    Obstaculo(int _tamano);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBrush(const QBrush &brush);
    QRectF boundingRect() const;
    int v=1;

private:
    QBrush brush_;
    int tamano;
};

#endif // OBSTACULO_H

