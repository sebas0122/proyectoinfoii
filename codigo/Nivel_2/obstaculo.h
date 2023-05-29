#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsItem>
#include <QPainter>

class Obstaculo: public QGraphicsItem
{
public:
    Obstaculo();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBrush(const QBrush &brush);
    QRectF boundingRect() const;

private:
    QBrush brush_;
};

#endif // OBSTACULO_H
