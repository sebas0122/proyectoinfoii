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
    void movimientoPeatones();
    void subeGasolina();
    void bajaGasolina(int x);

signals:
    void colisionGasolinallena();
    void colisionGasolinavacia();
    void colisionObstaculo();


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    Personaje* usuario;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *event);
    bool W;
    bool D;
    bool A;
    bool S;
};
#endif // MAINWINDOW_H
