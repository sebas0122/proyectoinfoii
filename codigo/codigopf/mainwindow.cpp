#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(-500, -250, 1000, 500);
    ui->graphicsView->setScene(scene);

    // limites de la escena
    l1 = new QGraphicsLineItem(-500,-250,500,-250);
    l2 = new QGraphicsLineItem(-500,250,500,250);
    l3 = new QGraphicsLineItem(-500,-250,-500,250);
    l4 = new QGraphicsLineItem(500,-250,500,250);

    // Se agregan los limites a la escena
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    inodoro1=new inodoro(50);
    orina1= new orina();

    timer=new QTimer();
    connect(timer,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));
    timer->start(33);

    timer2=new QTimer();
    connect(timer2,SIGNAL(timeout()), this, SLOT(Animar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverI=true;
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverB=true;
        verdad=false;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        tiempostart=orina1->gettiempoalcance();
        tiempostart=tiempostart*1000;
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverA=true;
        verdad=true;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        tiempostart=orina1->gettiempoalcance();
        tiempostart=tiempostart*1000;
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=true;
        timer2->start(tiempostart);
    }
}

void MainWindow::animar()
{
    if(moverI)
    {
        orina1->setPos(orina1->x()-2,orina1->y());
    }
    if(moverD)
    {
        orina1->setPos(orina1->x()+2,orina1->y());
    }
    if(moverA)
    {
        orina1->setPos(orina1->x(),orina1->y()-2);
    }
    if(moverB)
    {
        orina1->setPos(orina1->x(),orina1->y()+2);
    }
    if(orina1->collidesWithItem(inodoro1))
    {
        emit aviso(9);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverI=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverB=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverA=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=false;
    }
}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}

