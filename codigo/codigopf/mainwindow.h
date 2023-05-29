#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <iostream>
#include "orina.h"
#include "inodoro.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

signals:
    void aviso(int);

public slots:
    void aumentarPunt();
    void animar();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    orina* orina1;
    inodoro* inodoro1;
    QTimer *timer;
    QTimer *timer2;

    int puntuacion=0;

    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;

    float tiempostart=10;

    bool moverI;
    bool moverD;
    bool moverA;
    bool moverB;
    bool verdad;
};
#endif // MAINWINDOW_H
