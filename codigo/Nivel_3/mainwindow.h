#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <personaje.h>
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
    Enemigos* E1, * E2;


public slots:
    void animar();
    void Actualizar();
    void movimientoBotellas();
    void movimientoEnemigos();
    void subeSalud();
    void bajaSalud();


signals:
    void colisionBotellallena();
    void colisionBotellavacia();
    void colisionEnemigo();
    void salto();


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
    void keyReleaseEvent(QKeyEvent *ev);

    bool W;
    bool D;
    bool A;
    int salud=100;
    QVector<Botellas*> botellas;



};
#endif // MAINWINDOW_H
