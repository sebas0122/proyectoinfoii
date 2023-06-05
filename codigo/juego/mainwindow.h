#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <iostream>
#include <QGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include <time.h>
#include <cstdlib>
#include "orina.h"
#include "inodoroj.h"
#include <iostream>
#include <personaje_2.h>
#include <gasolina.h>
#include <obstaculo.h>
#include <QVector>
#include <QMainWindow>
#include <QGraphicsItem>
#include <personaje_3.h>
#include <QTimer>
#include <botellas.h>
#include <enemigos.h>
#include <QVector>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent1(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

signals:
    void aviso(int);
    void resultado1();
    void resultado2();
    void colisionGasolina();
    void colisionObstaculo();
    void acelera();
    void freno();

private slots:
    void nivel1();
    void nivel2();
    //void nivel3();
    void aumentarPunt();
    void Animar();
    void variacionarea();
    void aleatorio();
    void animar();
    void movimientoVehiculos();
    //void movimientoGasolina();
    //void movimientoPeatones();
    void subeGasolina();
    void bajaGasolina(int x);
    //void aumentarItems();
    void Actualizar();
    void sumatiempo();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    orina *orina1;
    inodoroJ *inodoro1;
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

    void escenainicial();

    Personaje* usuario;
    QTimer *timer3, *timer4, *timer5;
    void keyPressEvent(QKeyEvent *event);
    bool W;
    bool D;
    bool A;
    bool S;
    int gasolina=100;
    int tiempo=0;
    QVector<Obstaculo*> vehiculos;
    QVector<int> Carriles={35,180,350,500};
    QVector<Gasolina*> g;
};
#endif // MAINWINDOW_H
