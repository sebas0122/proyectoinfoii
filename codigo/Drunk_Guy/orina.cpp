#include "orina.h"

orina::orina(float _Vo,int _tamanO,int _altura)
{
    Vo=_Vo;
    tamanO=_tamanO;
    altura=_altura;
}

int orina::getVo()
{
    return Vo;
}

int orina::gettiempoalcance()
{
    return tiempoalcance;
}

int orina::gettamanO()
{
    return tamanO;
}

int orina::getaltura()
{
    return altura;
}

QRectF orina::boundingRect() const
{
    return QRect(-tamanO/2, -tamanO/2, tamanO, tamanO);
}

void orina::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(Qt::yellow); // Color de la orina
    painter->drawEllipse(-tamanO/2, -tamanO/2, tamanO, tamanO); // Dibuja la orina como un círculo
}

void orina::tiempoparabolico()
{
    tiempoalcance=sqrt((2*altura)/G)*1000;
}

void orina::modiVo(bool ver)
{
    if (ver){
        Vo+=1;
    }
    else if(ver==false && Vo>1){
        Vo-=1;
    }
}

float orina::distancia()
{
    return Vo*tiempoalcance;
}
