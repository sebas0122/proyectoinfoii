#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "orina.h"
#include "inodoro.h"
#include <iostream>
#include <gasolina.h>
#include <obstaculo.h>
#include <personaje2.h>
#include <personaje3.h>
#include <botellas.h>
#include <enemigos.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //NIVEL 1
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    bool W=false;
    bool D=false;
    bool A=false;
    bool S=false;

    Enemigos* E1, * E2;
    bool Wn3=false;
    bool Dn3=false;
    bool An3=false;

    bool n1,n2,n3;

signals:
    //NIVEL1
    void aviso(int);
    void resultado1();

    //NIVEL2
    void colisionGasolina();
    void colisionObstaculo();
    void acelera();
    void freno();

    //NIVEL3
    void colisionBotellallena();
    void colisionBotellavacia();
    void colisionEnemigo();
    void salto();

public slots:
    //NIVEL 1
    void aumentarPunt();
    void Animar();
    void variacionarea();
    void aleatorio();

    //NIVEL 2
    void animar();
    void movimientoVehiculos();
    void movimientoGasolina();
    //void movimientoPeatones();
    void subeGasolina();
    void bajaGasolina(int x);
    void aumentarItems();
    void Actualizar();

    //NIVEL3
    void animarn3();
    void Actualizarn3();
    void movimientoBotellas();
    void movimientoEnemigos();
    void subeSalud();
    void bajaSalud();

private slots:
    void nivel1();
    void nivel2();
    void nivel3();

private:
    Ui::MainWindow *ui;

    //NIVEL 1
    QGraphicsScene *scene;
    orina *orina1;
    inodoro *inodoro1;
    QTimer *timer;
    QTimer *timer2;
    QTimer *timeri;
    QTimer *timeraleatorio;
    int puntuacion=0;
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;
    int tiempostart=10;
    bool moverI=false;
    bool moverD=false;
    bool moverA=false;
    bool moverB=false;
    bool verdad=false;
    int area;
    int entradas=0;
    int maquina=0;
    void Menu();

    //NIVEL2
    Personaje2* usuario;
    QTimer *timern2, *timer2n2;

    int gasolina=100;
    QVector<Obstaculo*> vehiculos;
    QVector<int> Carriles={35,180,350,500};
    QVector<Gasolina*> g;

    //NIVEL3
    Personaje3* usuarion3;
    QTimer *timern3;

    int salud=100;
    QVector<Botellas*> botellas;
};
#endif // MAINWINDOW_H
