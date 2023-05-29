#ifndef BOTELLAS_H
#define BOTELLAS_H

#include <QGraphicsItem>
#include <QPainter>

class Botellas: public QGraphicsItem
{
public:
    Botellas();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBrush(const QBrush &brush);
    QRectF boundingRect() const;
    bool lleno;

private:
    QBrush brush_;
};

#endif // BOTELLAS_H
