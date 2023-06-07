#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Menu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Menu()
{
    //scene = new QGraphicsScene(-500, -250, 1000, 500);
    //ui->graphicsView->setScene(scene);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(nivel1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(nivel2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(nivel3()));
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lcdNumber->hide();
    ui->lcdNumber_2->hide();
}

void MainWindow::nivel1()
{
    //delete scene;
    ui->label_2->show();
    ui->lcdNumber->show();
    QPixmap pixmap2(":/images/Imagen1.png");  // Ruta y nombre de la imagen de fondo
    QGraphicsPixmapItem* fondo1 = new QGraphicsPixmapItem(pixmap2);
    fondo1->setPos(-300, -380);  // Establecer la posición del fondo en las coordenadas (0, 0)
    fondo1->setScale(1.54);
    fondo1->setZValue(-1);
    n1=true;
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->label->hide();
    scene = new QGraphicsScene(-5000, -2500, 10000, 5000);
    scene->addItem(fondo1);
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
    orina1->setZValue(1);

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

    timeraleatorio=new QTimer();
    connect(timeraleatorio, SIGNAL(timeout()), this, SLOT(aleatorio()));
    timeraleatorio->start(1000);
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(n1){
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
    else if(n2){
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
    else if(n3){
        if(ev->key()==Qt::Key_W)
        {
            Wn3=true;
        }
        else if(ev->key()==Qt::Key_D)
        {
            Dn3=true;
        }
        else if(ev->key()==Qt::Key_A)
        {
            An3=true;
        }
    }
}

void MainWindow::Animar()
{
    if(moverI)
    {
        orina1->setPos(orina1->x()-20,orina1->y());
        moverI=false;
    }
    if(moverD)
    {
        orina1->setPos(orina1->x()+20,orina1->y());
        moverD=false;
    }
    if(moverA)
    {
        orina1->setPos(orina1->x(),orina1->y()-20);
        moverA=false;
    }
    if(moverB)
    {
        orina1->setPos(orina1->x(),orina1->y()+20);
        moverB=false;
    }
    if(orina1->collidesWithItem(inodoro1))
    {
        emit aviso(9);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(n1){
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
    }
    else if(n2){
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
    else if(n3){
        if(ev->key()==Qt::Key_A)
        {
            An3=false;
        }
        else if(ev->key()==Qt::Key_D)
        {
            Dn3=false;
        }
    }
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
        QString puntajeStr = QString::number(puntuacion);
        timer->stop();
        QMessageBox::information(this, "Game Over", "El juego ha terminado.");
        QMessageBox::information(this, "Puntaje", "Su puntaje fue: " + puntajeStr);
        QApplication::quit();
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
    ui->label_2->show();
    ui->lcdNumber->show();
    ui->label_3->setText("Gasolina");
    ui->label_3->show();
    ui->lcdNumber_2->display(gasolina);
    ui->lcdNumber_2->show();
    //delete scene;
    QPixmap pixmap2(":/images/Imagen2.png");  // Ruta y nombre de la imagen de fondo
    QGraphicsPixmapItem* fondo1 = new QGraphicsPixmapItem(pixmap2);
    fondo1->setPos(-70, 0);  // Establecer la posición del fondo en las coordenadas (0, 0)
    fondo1->setScale(1.54);
    fondo1->setZValue(-1);
    n2=true;
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->label->hide();
    scene=new QGraphicsScene(0,0,500,400);
    scene->addItem(fondo1);
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

    usuario = new Personaje2();
    scene->addItem(usuario);
    usuario->setPos(250,380);
    timern2 = new QTimer();
    connect(timern2,SIGNAL(timeout()), this, SLOT(animar()));
    timern2->start(10);

    Obstaculo* V1 = new Obstaculo(40);
    V1->setPos(60, 35);
    V1->setBrush(Qt::darkGray);
    scene->addItem(V1);
    vehiculos.push_back(V1);

    Obstaculo* V2 = new Obstaculo(40);
    V2->setPos(200, 35);
    V2->setBrush(Qt::green);
    scene->addItem(V2);
    vehiculos.push_back(V2);

    Obstaculo* V3 = new Obstaculo(40);
    V3->setPos(340, 35);
    V3->setBrush(Qt::red);
    scene->addItem(V3);
    vehiculos.push_back(V3);

    Obstaculo* V4 = new Obstaculo(40);
    V4->setPos(470, 35);
    V4->setBrush(Qt::blue);
    scene->addItem(V4);
    vehiculos.push_back(V4);

    connect(timern2,SIGNAL(timeout()), this, SLOT(movimientoVehiculos()));
    connect(timern2,SIGNAL(timeout()), this, SLOT(movimientoGasolina()));
    connect(timern2, SIGNAL(timeout()), this, SLOT(aleatorio_2()));
    connect(this, &MainWindow::colisionObstaculo, this, [this]() { bajaGasolina(5); });
    connect(this, SIGNAL(colisionGasolina()), this, SLOT(subeGasolina()));
    connect(this, SIGNAL(acelera()), this, SLOT(Actualizar()));
    connect(this, SIGNAL(freno()), this, SLOT(Actualizar()));


    timer2n2=new QTimer();
    connect(timer2n2, SIGNAL(timeout()), this, SLOT(aumentarItems()));
    connect(timer2n2, &QTimer::timeout, this, [this]() { bajaGasolina(10); });
    timer2n2->start(10000);

    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(aumentarPunt()));
    timer->start(1000);

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
        ui->lcdNumber_2->display(gasolina);
    }
}

void MainWindow::bajaGasolina(int x){
    gasolina -= x;
    ui->lcdNumber_2->display(gasolina);
    if (gasolina <= 0) {
        QString puntajeStr = QString::number(puntuacion);
        timer->stop();
        QMessageBox::information(this, "Game Over", "El juego ha terminado.");
        QMessageBox::information(this, "Puntaje", "Su puntaje fue: " + puntajeStr);
        QApplication::quit();
    }
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

void MainWindow::aleatorio_2()
{
    srand(time(NULL));
    maquina=rand() % 2+1;
    if (maquina==1){
        usuario->setPos(usuario->x()-1,usuario->y());
    }
    else if (maquina==2){
        usuario->setPos(usuario->x()+1,usuario->y());
    }
}

void MainWindow::nivel3()
{
    ui->label_2->show();
    ui->lcdNumber->show();
    ui->label_3->setText("Salud");
    ui->label_3->show();
    ui->lcdNumber_2->display(salud);
    ui->lcdNumber_2->show();
    ui->lcdNumber->display(puntuacion);
    QPixmap pixmap(":/images/Imagen3.png");  // Ruta y nombre de la imagen de fondo
    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem(pixmap);
    fondo->setPos(0, 0);  // Establecer la posición del fondo en las coordenadas (0, 0)
    fondo->setScale(1.25);
    fondo->setZValue(-1);
    n3=true;
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->label->hide();
    scene=new QGraphicsScene(0,0,500,400);
    ui->graphicsView->setScene(scene);
    scene->addItem(fondo);
    Wn3=false;
    An3=false;
    Dn3=false;

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    l4=new QGraphicsLineItem(0,400,500,400);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);



    usuarion3 = new Personaje3();
    scene->addItem(usuarion3);
    usuarion3->setPos(250,380);
    timern3 = new QTimer();
    connect(timern3,SIGNAL(timeout()), this, SLOT(animarn3()));
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

    connect(timern3,SIGNAL(timeout()), this, SLOT(movimientoBotellas()));
    connect(this,SIGNAL(colisionBotellallena()), this, SLOT(subeSalud()));
    connect(this, &MainWindow::colisionBotellavacia, this, [this]() {bajaSalud(5);});
    connect(timern3, SIGNAL(timeout()), this, SLOT(movimientoEnemigos()));
    connect(this, &MainWindow::colisionEnemigo, this, [this]() {bajaSalud(5);});
    connect(this,SIGNAL(salto()), this, SLOT(Actualizarn3()));

    timern3->start(10);

    timer2n2=new QTimer();
    connect(timer2n2, SIGNAL(timeout()), this, SLOT(aumentarBotellas()));
    connect(timer2n2, &QTimer::timeout, this, [this]() { bajaSalud(10); });
    timer2n2->start(10000);

    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(aumentarPunt()));
    timer->start(1000);

}

void MainWindow::animarn3()
{
    if (Wn3)
    {
        emit salto();
    }
    if (Dn3)
    {
        usuarion3->setPos(usuarion3->x() + 2, usuarion3->y());
    }
    if (An3)
    {
        usuarion3->setPos(usuarion3->x() - 2, usuarion3->y());
    }
    if (usuarion3->collidesWithItem(l2))
    {
        An3 = false;
    }
    if (usuarion3->collidesWithItem(l3))
    {
        Dn3 = false;
    }
}


void MainWindow::Actualizarn3()
//Actualiza las velocidades y posiciones del cuerpo
{

    usuarion3->velocidades();
    usuarion3->posiciones();
    if(usuarion3->collidesWithItem(l4) && Wn3==true){
        usuarion3->_y=380;
        usuarion3->vy=-50;
        Wn3=false;
    }

}

void MainWindow::movimientoBotellas(){
    for (auto it = botellas.begin(); it != botellas.end(); ++it) {
        Botellas* botellaActual = *it;

        if (usuarion3->collidesWithItem(botellaActual)) {
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
        ui->lcdNumber_2->display(salud);
    }
}

void MainWindow::bajaSalud(int x){
    salud -= x;
    ui->lcdNumber_2->display(salud);
    if (salud <= 0) {
        QString puntajeStr = QString::number(puntuacion);
        timer->stop();
        QMessageBox::information(this, "Game Over", "El juego ha terminado.");
        QMessageBox::information(this, "Puntaje", "Su puntaje fue: " + puntajeStr);
        QApplication::quit();
    }
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

    if((usuarion3->collidesWithItem(E1) || usuarion3->collidesWithItem(E2)) && !colision){
        colision=true;
        emit colisionEnemigo();
    }

    if(!usuarion3->collidesWithItem(E1) && !usuarion3->collidesWithItem(E2)){
        colision=false;
    }

}

void MainWindow::aumentarBotellas(){
    Botellas* B = new Botellas();
    B->lleno=rand() % 2;
    if(B->lleno){
        B->setBrush(Qt::yellow);
        B->setPos(35+(rand()%466),35);
    }
    else{
        B->setBrush(Qt::darkGray);
        B->setPos(35+(rand()%466),35);
    }
    scene->addItem(B);
    botellas.push_back(B);
}


