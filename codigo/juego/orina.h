#ifndef ORINA_H
#define ORINA_H

#define G 9.8

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class orina:  public QGraphicsItem
{
private:
    int tamanO,altura;    //tamanO de la orina; altura es la altura inicial desde donde parte la orina
    int tiempoalcance,Vo; //tiempoalcance es el tiempo que demora en caer la orina; Vo la velocidad inicial horizantal con la que parte la orina

public:
    orina();
    orina(float _Vo,int _tamanO,int _altura);

    int getVo();
    int gettiempoalcance();
    int gettamanO();
    int getaltura();
    float distancia();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    void tiempoparabolico();
    void modiVo(bool ver);
};

#endif // ORINA_H
