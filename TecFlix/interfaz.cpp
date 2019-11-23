#include "interfaz.h"
#include "ui_interfaz.h"
#include <QLabel>
#include <QWebEngineView>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <iostream>
#include <string>
#include <QString>
#include <conexion.h>
#include <QToolButton>
#include <pagina.h>
#include <worker.h>
#include <detalles.h>
#include <estructura.h>


using namespace std;

Interfaz::Interfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    filas=2;
    columnas= 5;
    esperaAnterior=false;
    esperaSiguiente=false;

    pagAct = new worker;
    pagAct->setData(78,filas*columnas);
    pagAct->start();

    pagAnt = new worker;
    pagAnt->setData(77,filas*columnas);
    pagAnt->start();

    pagSig = new worker;
    pagSig->setData(79,filas*columnas);
    pagSig->start();

    connect(pagAct,SIGNAL(enviar()),this,SLOT(recibir()));
    connect(pagAnt,SIGNAL(enviar()),this,SLOT(recibirAnt()));
    connect(pagSig,SIGNAL(enviar()),this,SLOT(recibirSig()));

    boton();
    //cargarPaginaActual();

}

Interfaz::~Interfaz()
{
    delete ui;
}
void Interfaz::recibir(){
    actual = pagAct->pag;
    pagAct->wait();
    cargarPaginaActual();
}


void Interfaz::recibirAnt(){
    anterior = pagAnt->pag;
    pagAnt->wait();
    if (esperaAnterior){
        on_ButtonAnterior_clicked();
        esperaAnterior=false;
    }
}

void Interfaz::recibirSig(){
    siguiente = pagSig->pag;
    pagSig->wait();
    if (esperaSiguiente){
        on_ButtonSiguiente_clicked();
        esperaSiguiente=false;
    }
}


void Interfaz::boton(){
    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas;j++){
            QToolButton *u = new QToolButton();
            Estructura *h = new Estructura(u);
            u->setParent(this);
            u->setGeometry(20+(800/columnas)*j,10+(580/filas)*i,(900/columnas)-40,(600/filas)-20);
            QPixmap b("/home/andy/Imágenes/cargando.jpeg");
            u->setIcon(b);
            botones.push_back(h);
        }
    }
}

void Interfaz::cargarPaginaActual(){
    ui->label->setNum(actual->id);
    for (int i=0; i< actual->getPeliculas().size();i++){
        botones[i]->setPelicula(actual->getPeliculas()[i]);
        conexion *p = new conexion(actual->getPeliculas()[i].getPosterLink(), botones[i]->boton);
    }
}


void Interfaz::on_ButtonAnterior_clicked()
{

    cout<<pagAnt->terminoHilo()<<endl;
    if (pagAnt->terminoHilo()){
        if (anterior!=nullptr){
            delete siguiente;
            siguiente = actual;
            actual = anterior;
            if (anterior->id==0){
                anterior=nullptr;
            } else {
                pagAnt->setData(anterior->id-1,filas*columnas);
                pagAnt->start();
            }
        cargarPaginaActual();
        }
    } else{
        for (int i = 0;i<botones.size();i++) {
            QPixmap b("/home/andy/Imágenes/cargando.jpeg");
            botones[i]->boton->setIcon(b);
            esperaAnterior=true;
        }
    }

}

void Interfaz::on_ButtonSiguiente_clicked()
{
    if (pagSig->terminoHilo()){
        if (siguiente!=nullptr){
            delete anterior;
            anterior = actual;
            actual = siguiente;
            pagSig->setData(siguiente->id+1,filas*columnas);
            pagSig->start();
        }
        cargarPaginaActual();
    }
    else {
        for (int i = 0;i<botones.size();i++) {
            QPixmap b("/home/andy/Imágenes/cargando.jpeg");
            botones[i]->boton->setIcon(b);
            esperaSiguiente=true;
        }
    }
}

void Interfaz::on_zoomin_clicked()
{
    if (columnas);
    columnas= columnas-1;
    for (int i=0; i<botones.size();i++){
        delete (botones[i]);
    }
    boton();
    cout<<"BOTONES----------------"<<botones.size()<<endl;

}

void Interfaz::click(){
    qDebug()<<"Me tocan ";
}

void Interfaz::on_zoomout_clicked()
{


}
