#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <iostream>
#include<time.h>
#include <cstdlib>
#include "orina.h"
#include "inodoro.h"
#include <iostream>

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
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

signals:
    void aviso(int);

public slots:
    void aumentarPunt();
    void Animar();
    void variacionarea();
    void aleatorio();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    orina *orina1;
    inodoro *inodoro1;
    QTimer *timer;
    QTimer *timer2;
    QTimer *timeri;

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
};
#endif // MAINWINDOW_H
