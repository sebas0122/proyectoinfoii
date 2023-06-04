#ifndef INODORO_H
#define INODORO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QObject>

class inodoroJ : public QGraphicsItem
{

private:
    int tamano;

public:
    inodoroJ();
    inodoroJ(int _tamano);

    int gettamano();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // INODORO_H
