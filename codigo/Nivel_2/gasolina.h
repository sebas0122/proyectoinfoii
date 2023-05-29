#ifndef GASOLINA_H
#define GASOLINA_H

#include <QGraphicsItem>
#include <QPainter>

class Gasolina: public QGraphicsItem
{
public:
    Gasolina();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBrush(const QBrush &brush);
    QRectF boundingRect() const;
    bool lleno;

private:
    QBrush brush_;
};

#endif // GASOLINA_H
