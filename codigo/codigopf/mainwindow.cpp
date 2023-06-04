#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(-5000, -2500, 10000, 5000);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(0,0,1000,720);

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

    area=200;

    inodoro1=new inodoro(area);
    orina1= new orina(1,10,2);
    orina1->setPos(orina1->x(),243);

    scene->addItem(orina1);
    scene->addItem(inodoro1);
    orina1->tiempoparabolico();
    tiempostart=orina1->gettiempoalcance();
    cout<<tiempostart;

    timer=new QTimer();
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));
    timer->start(500);

    timer2=new QTimer();
    connect(timer2,SIGNAL(timeout()), this, SLOT(Animar()));

    timeri = new QTimer();
    connect(timeri, SIGNAL(timeout()), this, SLOT(variacionarea()));  // Cambiar SIGNAL por timeout()
    timeri->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    /*if(ev->key()==Qt::Key_A)
    {
        moverI=true;
        timer2->start(400);
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverB=true;
        verdad=false;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        cout<<"Ab "<<tiempostart;
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverA=true;
        verdad=true;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=true;
        timer2->start(tiempostart);
    }*/
}

void MainWindow::Animar()
{
    if(moverI)
    {
        orina1->setPos(orina1->x()-10,orina1->y());
        moverI=false;
    }
    if(moverD)
    {
        orina1->setPos(orina1->x()+10,orina1->y());
        moverD=false;
    }
    if(moverA)
    {
        orina1->setPos(orina1->x(),orina1->y()-10);
        moverA=false;
    }
    if(moverB)
    {
        orina1->setPos(orina1->x(),orina1->y()+10);
        moverB=false;
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
        moverI=true;
        timer2->start(400);
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverB=true;
        verdad=false;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        cout<<"Ab "<<tiempostart;
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverA=true;
        verdad=true;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=true;
        timer2->start(tiempostart);
    }
<<<<<<< Updated upstream
    /*
    if(ev->key()==Qt::Key_A && entradas==1)
    {
        moverI=false;
        entradas=0;
=======
}

void MainWindow::Animar()
{
    if(moverI)
    {
        orina1->setPos(orina1->x()-2,orina1->y());
        moverI=false;
    }
    if(moverD)
    {
        orina1->setPos(orina1->x()+2,orina1->y());
        entradas=1;
    }
    if(moverA)
    {
        orina1->setPos(orina1->x(),orina1->y()-2);
        entradas=1;
    }
    if(moverB)
    {
        orina1->setPos(orina1->x(),orina1->y()+2);
        entradas=1;
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
        moverI=true;
        timer2->start(400);
>>>>>>> Stashed changes
    }
    else if(ev->key()==Qt::Key_S && entradas==1)
    {
<<<<<<< Updated upstream
        moverB=false;
        entradas=0;
=======
        moverB=true;
        verdad=false;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        cout<<"Ab "<<tiempostart;
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
>>>>>>> Stashed changes
    }
    else if(ev->key()==Qt::Key_W && entradas==1)
    {
<<<<<<< Updated upstream
        moverA=false;
        entradas=0;
=======
        moverA=true;
        verdad=true;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
>>>>>>> Stashed changes
    }
    else if(ev->key()==Qt::Key_D && entradas==1)
    {
<<<<<<< Updated upstream
       moverD=false;
       entradas=0;
    }*/
=======
        moverD=true;
        timer2->start(tiempostart);
    }

    if(ev->key()==Qt::Key_A && entradas==1)
    {
        moverI=false;
        entradas=0;
    }
    else if(ev->key()==Qt::Key_S && entradas==1)
    {
        moverB=false;
        entradas=0;
    }
    else if(ev->key()==Qt::Key_W && entradas==1)
    {
        moverA=false;
        entradas=0;
    }
    else if(ev->key()==Qt::Key_D && entradas==1)
    {
       moverD=false;
       entradas=0;
    }
>>>>>>> Stashed changes
}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}

void MainWindow::variacionarea()
{
    scene->removeItem(inodoro1);
    delete inodoro1;
    area -= 5;
    inodoro1 = new inodoro(area);
    scene->addItem(inodoro1);

    // Detiene el temporizador si el tamaño llega a 0
    if (area <= 0){
        timeri->stop();
        area = 0;
    }
}
<<<<<<< Updated upstream

void MainWindow::aleatorio()
{

}

=======
>>>>>>> Stashed changes
