#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <personaje.h>
#include <botellas.h>
#include <QPainter>
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
    //connect(this,SIGNAL(salto()), this, SLOT(Actualizar()));

    Botellas* B1 = new Botellas();
    B1->setPos(35, 35);
    B1->lleno=false;
    scene->addItem(B1);
    botellas.push_back(B1);

    Botellas* B2 = new Botellas();
    B2->setPos(267, 35);
    B2->setBrush(Qt::yellow);
    B2->lleno=true;

    scene->addItem(B2);
    botellas.push_back(B2);

    Botellas* B3 = new Botellas();
    B3->setPos(500, 35);
    B3->lleno=false;
    scene->addItem(B3);
    botellas.push_back(B3);

    E1=new Enemigos();
    E1->setPos(20,380);
    scene->addItem(E1);
    E2=new Enemigos();
    E2->setPos(480,380);
    scene->addItem(E2);


    connect(timer,SIGNAL(timeout()), this, SLOT(movimientoBotellas()));
    connect(this,SIGNAL(colisionBotellallena()), this, SLOT(subeSalud()));
    connect(this,SIGNAL(colisionBotellavacia()), this, SLOT(bajaSalud()));
    connect(timer, SIGNAL(timeout()), this, SLOT(movimientoEnemigos()));
    connect(this, SIGNAL(colisionEnemigo()), this, SLOT(bajaSalud()));
    connect(this,SIGNAL(salto()), this, SLOT(Actualizar()));

    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animar()
{
    if (W)
    {
        emit salto();
    }
    if (D)
    {
        usuario->setPos(usuario->x() + 2, usuario->y());
    }
    if (A)
    {
        usuario->setPos(usuario->x() - 2, usuario->y());
    }
    if (usuario->collidesWithItem(l2))
    {
        A = false;
    }
    if (usuario->collidesWithItem(l3))
    {
        D = false;
    }
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
}

void MainWindow::Actualizar()
//Actualiza las velocidades y posiciones del cuerpo
{

    usuario->velocidades();
    usuario->posiciones();
    if(usuario->collidesWithItem(l4) && W==true){
        usuario->_y=380;
        usuario->vy=-50;
        W=false;
    }

}

void MainWindow::movimientoBotellas(){
    for (auto it = botellas.begin(); it != botellas.end(); ++it) {
        Botellas* botellaActual = *it;

        if (usuario->collidesWithItem(botellaActual)) {
            if(botellaActual->lleno){
                botellaActual->lleno=rand() % 2;
                if(botellaActual->lleno){
                    botellaActual->setBrush(Qt::yellow);
                    botellaActual->setPos(35+(rand()%466),35);
                }
                else{
                    botellaActual->setBrush(Qt::darkGray);
                    botellaActual->setPos(35+(rand()%466),35);
                }
                emit colisionBotellallena();

            }
            else{
                botellaActual->lleno=rand() % 2;
                if(botellaActual->lleno){
                    botellaActual->setBrush(Qt::yellow);
                    botellaActual->setPos(35+(rand()%466),35);
                }
                else{
                    botellaActual->setBrush(Qt::darkGray);
                    botellaActual->setPos(35+(rand()%466),35);
                }
                emit colisionBotellavacia();

            }
        }
        else if(botellaActual->collidesWithItem(l4)){
            botellaActual->lleno=rand() % 2;
            if(botellaActual->lleno){
                botellaActual->setBrush(Qt::yellow);
                botellaActual->setPos(35+(rand()%466),35);
            }
            else{
                botellaActual->setBrush(Qt::darkGray);
                botellaActual->setPos(35+(rand()%466),35);
            }
        }
        else{
            botellaActual->setPos(botellaActual->x(), botellaActual->y()+1);
        }
    }
}

void MainWindow::subeSalud(){
    if(salud<=95){
        salud += 5;
        ui->lcdNumber->display(salud);
    }
}

void MainWindow::bajaSalud(){
    salud -= 5;
    ui->lcdNumber->display(salud);
}

void MainWindow::movimientoEnemigos(){

    static bool colision=false;
    if(E1->collidesWithItem(l3)){
        E1->setPos(20,380);
    }
    else{
        E1->setPos(E1->x()+1,E1->y());
    }
    if(E2->collidesWithItem(l2)){
        E2->setPos(480,380);
    }
    else{
        E2->setPos(E2->x()-1,E2->y());
    }

    if((usuario->collidesWithItem(E1) || usuario->collidesWithItem(E2)) && !colision){
        colision=true;
        emit colisionEnemigo();
    }

    if(!usuario->collidesWithItem(E1) && !usuario->collidesWithItem(E2)){
        colision=false;
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        A=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        D=false;
    }

}

