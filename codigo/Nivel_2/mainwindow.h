#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <personaje.h>
#include <QGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include <gasolina.h>
#include <obstaculo.h>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void animar();
    void movimientoVehiculos();
    void movimientoGasolina();
    //void movimientoPeatones();
    void subeGasolina();
    void bajaGasolina(int x);
    void aumentarItems();
    void Actualizar();

signals:
    void colisionGasolina();
    void colisionObstaculo();
    void acelera();
    void freno();


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    Personaje* usuario;
    QTimer *timer, *timer2;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *ev);
    bool W;
    bool D;
    bool A;
    bool S;
    int gasolina=100;
    QVector<Obstaculo*> vehiculos;
    QVector<int> Carriles={35,180,350,500};
    QVector<Gasolina*> g;
};
#endif // MAINWINDOW_H
