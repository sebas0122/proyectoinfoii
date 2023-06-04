#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(0,0,500,400);
    ui->graphicsView->setScene(scene);
    W=false;
    A=false;
    D=false;
    S=false;

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    l4=new QGraphicsLineItem(0,400,500,400);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    usuario = new Personaje();
    scene->addItem(usuario);
    usuario->setPos(250,380);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(animar()));
    timer->start(10);

    Obstaculo* V1 = new Obstaculo(40);
    V1->setPos(35, 35);
    V1->setBrush(Qt::darkGray);
    scene->addItem(V1);
    vehiculos.push_back(V1);

    Obstaculo* V2 = new Obstaculo(60);
    V2->setPos(180, 35);
    V2->setBrush(Qt::green);
    scene->addItem(V2);
    vehiculos.push_back(V2);

    Obstaculo* V3 = new Obstaculo(35);
    V3->setPos(350, 35);
    V3->setBrush(Qt::red);
    scene->addItem(V3);
    vehiculos.push_back(V3);

    Obstaculo* V4 = new Obstaculo(70);
    V4->setPos(500, 35);
    V4->setBrush(Qt::blue);
    scene->addItem(V4);
    vehiculos.push_back(V4);

    connect(timer,SIGNAL(timeout()), this, SLOT(movimientoVehiculos()));
    connect(timer,SIGNAL(timeout()), this, SLOT(movimientoGasolina()));
    connect(this, &MainWindow::colisionObstaculo, this, [this]() { bajaGasolina(5); });
    connect(this, SIGNAL(colisionGasolina()), this, SLOT(subeGasolina()));
    connect(this, SIGNAL(acelera()), this, SLOT(Actualizar()));
    connect(this, SIGNAL(freno()), this, SLOT(Actualizar()));


    timer2=new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(aumentarItems()));
    connect(timer2, &QTimer::timeout, this, [this]() { bajaGasolina(10); });
    timer2->start(10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W)
    {
        W=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        D=true;
    }
    else if(ev->key()==Qt::Key_A)
    {
        A=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        S=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W)
    {
        W=false;
        usuario->v = 0;
    }
    else if(ev->key()==Qt::Key_D)
    {
        D=false;
    }
    else if(ev->key()==Qt::Key_A)
    {
        A=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        S=false;
        usuario->v = 0;
    }
    /*
    if (ev->key() == Qt::Key_W || ev->key() == Qt::Key_S)
   {
       usuario->v = 0;
   }
    */
}

void MainWindow::animar()
{
    if (W)
    {
        emit acelera();
    }
    if (D)
    {
        usuario->setPos(usuario->x() + 2, usuario->y());
    }
    if (A)
    {
        usuario->setPos(usuario->x() - 2, usuario->y());
    }
    if (S)
    {
        emit freno();
    }
    if (usuario->collidesWithItem(l2))
    {
        A = false;
    }
    if (usuario->collidesWithItem(l3))
    {
        D = false;
    }
    if (usuario->collidesWithItem(l1))
    {
        W = false;
    }
    if (usuario->collidesWithItem(l4))
    {
        S = false;
    }
}

void MainWindow::subeGasolina(){
    if(gasolina<=95){
        gasolina += 5;
        ui->lcdNumber->display(gasolina);
    }
}

void MainWindow::bajaGasolina(int x){
    gasolina -= x;
    ui->lcdNumber->display(gasolina);
}

void MainWindow::movimientoVehiculos(){
    for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        Obstaculo* Vehiculo = *it;

        if (usuario->collidesWithItem(Vehiculo)) {
            emit colisionObstaculo();
            Vehiculo->v=(rand() % 2) + 1;
            Vehiculo->setPos(Carriles[(rand() % 4)],35);
            //usuario->setPos(usuario->x(),usuario->y()+30);
        }
        else if(Vehiculo->collidesWithItem(l4)){
            Vehiculo->v=(rand() % 2) + 1;
            Vehiculo->setPos(Carriles[(rand() % 4)],35);

        }
        else{
            Vehiculo->setPos(Vehiculo->x(), Vehiculo->y()+Vehiculo->v);
        }
    }
}

void MainWindow::movimientoGasolina(){
    for (auto it = g.begin(); it != g.end(); ++it) {
        Gasolina* G = *it;

        if (usuario->collidesWithItem(G)) {
            emit colisionGasolina();
            G->setPos(Carriles[(rand() % 4)],35);
        }
        else if(G->collidesWithItem(l4)){
            G->setPos(Carriles[(rand() % 4)],35);

        }
        else{
            G->setPos(G->x(), G->y()+1);
        }
    }
}

void MainWindow::aumentarItems(){
    Obstaculo* V = new Obstaculo(40);
    V->setPos(Carriles[(rand() % 4)],35);
    V->setBrush(Qt::darkGray);
    scene->addItem(V);
    vehiculos.push_back(V);
    Gasolina* G = new Gasolina();
    G->setPos(Carriles[(rand() % 4)],35);
    scene->addItem(G);
    g.push_back(G);

}

void MainWindow::Actualizar()
//Actualiza las velocidades y posiciones del cuerpo
{
    if (W)
    {
        // Aceleración positiva

        usuario->a = -10;
    }
    else if (S)
    {
        // Aceleración negativa (frenado)

        usuario->a = 10;
    }

    usuario->velocidades();
    usuario->posiciones();


    if(usuario->collidesWithItem(l4)){
        usuario->setPos(usuario->x(),380);
        S=false;
    }
    if(usuario->collidesWithItem(l1)){
        usuario->setPos(usuario->x(),20);
        W=false;
    }
}

