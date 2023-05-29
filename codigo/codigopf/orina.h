#ifndef ORINA_H
#define ORINA_H

#define g -9.8

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class orina:  public QGraphicsItem
{
private:
    int Vo,tamanO;
    float tiempoalcance;

public:
    orina();
    orina(int _Vo,float _tiempoalcance,int _tamanO);

    int getVo();
    float gettiempoalcance();
    int gettamanO();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    void tiempoparabolico();
    void modiVo(bool ver);
};

#endif // ORINA_H
