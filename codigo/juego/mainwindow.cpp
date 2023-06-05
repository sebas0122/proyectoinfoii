#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escenainicial();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::escenainicial()
{
    scene = new QGraphicsScene(-500, -250, 1000, 500);
    ui->graphicsView->setScene(scene);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(nivel1()));
}

void MainWindow::nivel1()
{
    delete scene;
    delete ui->pushButton;
    scene = new QGraphicsScene(-500, -250, 1000, 500);
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

    inodoro1=new inodoroJ(area);
    orina1= new orina(1,10,2);
    orina1->setPos(orina1->x(),243);

    scene->addItem(orina1);
    scene->addItem(inodoro1);
    orina1->tiempoparabolico();
    tiempostart=orina1->gettiempoalcance();
    //cout<<tiempostart;

    timer=new QTimer();
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));
    timer->start(500);

    timer2=new QTimer();
    connect(timer2,SIGNAL(timeout()), this, SLOT(Animar()));

    timeri = new QTimer();
    connect(timeri, SIGNAL(timeout()), this, SLOT(variacionarea()));  // Cambiar SIGNAL por timeout()
    timeri->start(1000);

    timeraleatorio=new QTimer();
    connect(timeraleatorio, SIGNAL(timeout()), this, SLOT(aleatorio()));
    timeraleatorio->start(4000);

    connect(this, SIGNAL(resultado1()), this, SLOT(nivel2()));
}

void MainWindow::keyPressEvent1(QKeyEvent *ev)
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
        timer2->start(tiempostart);
        A=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverB=true;
        verdad=false;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        //cout<<"Ab "<<tiempostart;
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
        S=false;
        usuario->v = 0;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverA=true;
        verdad=true;
        orina1->modiVo(verdad);
        orina1->tiempoparabolico();
        //tiempostart=orina1->gettiempoalcance();
        timer2->start(tiempostart);
        W=false;
        usuario->v = 0;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverD=true;
        timer2->start(tiempostart);
        D=false;
    }
    /*
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
    }*/
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
    inodoro1 = new inodoroJ(area);
    scene->addItem(inodoro1);

    // Detiene el temporizador si el tamaño llega a 0
    if (area <= 0){
        timeri->stop();
        area = 0;
        emit resultado1();
    }
}

void MainWindow::aleatorio()
{
    srand(time(NULL));
    maquina=rand() % 4+1;
    if (maquina==1){
        orina1->setPos(orina1->x()-10,orina1->y());
    }
    else if (maquina==2){
        orina1->setPos(orina1->x()+10,orina1->y());
    }
    else if (maquina==3){
        orina1->setPos(orina1->x(),orina1->y()-10);
    }
    else if (maquina==4){
        orina1->setPos(orina1->x(),orina1->y()+10);
    }
}

void MainWindow::nivel2()
{
    delete scene;
    if (puntuacion>=100){
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
        connect(timer3,SIGNAL(timeout()), this, SLOT(animar()));
        timer3->start(10);

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

        connect(timer3,SIGNAL(timeout()), this, SLOT(movimientoVehiculos()));
        connect(timer3,SIGNAL(timeout()), this, SLOT(movimientoGasolina()));
        connect(this, &MainWindow::colisionObstaculo, this, [this]() { bajaGasolina(5); });
        connect(this, SIGNAL(colisionGasolina()), this, SLOT(subeGasolina()));
        connect(this, SIGNAL(acelera()), this, SLOT(Actualizar()));
        connect(this, SIGNAL(freno()), this, SLOT(Actualizar()));
        connect(timer5,SIGNAL(timeout()),this, SLOT(sumatiempo()));
        //connect(this, SIGNAL(resultado2()),this, SLOT(nivel3()));


        timer2=new QTimer();
        connect(timer2, SIGNAL(timeout()), this, SLOT(aumentarItems()));
        connect(timer2, &QTimer::timeout, this, [this]() { bajaGasolina(10); });
        timer2->start(10000);
    }
    else{
       scene=new QGraphicsScene(0,0,500,400);
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
    else if(ev->key()==Qt::Key_S)
    {
        S=true;
    }
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

/*
void MainWindow::movimientoGasolina(){
    for (auto it = g.begin(); it != g.end(); ++it) {
        Gasolina* Ga = *it;

        if (usuario->collidesWithItem(Ga)) {
            emit colisionGasolina();
            Ga->setPos(Carriles[(rand() % 4)],35);
        }
        else if(Ga->collidesWithItem(l4)){
            Ga->setPos(Carriles[(rand() % 4)],35);

        }
        else{
            Ga->setPos(Ga->x(), Ga->y()+1);
        }
    }
}

void MainWindow::aumentarItems(){
    Obstaculo* V = new Obstaculo(40);
    V->setPos(Carriles[(rand() % 4)],35);
    V->setBrush(Qt::darkGray);
    scene->addItem(V);
    vehiculos.push_back(V);
    Gasolina* Ga = new Gasolina();
    Ga->setPos(Carriles[(rand() % 4)],35);
    scene->addItem(Ga);
    g.push_back(Ga);

}
*/
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

void MainWindow::sumatiempo()
{
    tiempo++;
    if (tiempo>=20){
        emit resultado2();
    }
}

