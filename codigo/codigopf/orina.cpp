#include "orina.h"

orina::orina(int _Vo,float _tiempoalcance,int _tamanO)
{
    Vo=_Vo;
    tiempoalcance=_tiempoalcance;
    tamanO=_tamanO;
}

int orina::getVo()
{
    return Vo;
}

float orina::gettiempoalcance()
{
    return tiempoalcance;
}

int orina::gettamanO()
{
    return tamanO;
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
    tiempoalcance=(2 * Vo)/g;
}

void orina::modiVo(bool ver)
{
    if (ver){
        Vo+=5;
    }
    else{
        Vo-=5;
    }
}
