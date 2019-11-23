#include "interfaz.h"
#include "ui_interfaz.h"
#include <iostream>
#include <unistd.h>

using namespace std;


Interfaz::Interfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graficos->setScene(scene);

    definirMatriz();
    //definirObstaculos();
    dibujar();
    //caminar(7,3,90,78);

    connect(pro,SIGNAL(progreso()),this,SLOT(handleresul()));



}
void Interfaz::definirMatriz(){

    for (int i = 0; i<100;i++){
        for (int j=0;j<100;j++){
            NodoM *n = new NodoM();
            matriz[i][j]=n;
        }
    }
}

void Interfaz::definirObstaculos(){
    matriz[30][70]->setFree(false);
    matriz[40][2]->setFree(false);
    matriz[60][4]->setFree(false);
    matriz[95][7]->setFree(false);
    matriz[30][9]->setFree(false);
    matriz[23][70]->setFree(false);
    matriz[30][11]->setFree(false);
    matriz[34][87]->setFree(false);
    matriz[30][23]->setFree(false);
    matriz[35][20]->setFree(false);
    matriz[30][31]->setFree(false);
    matriz[26][90]->setFree(false);
    matriz[31][22]->setFree(false);
    matriz[66][66]->setFree(false);
    matriz[24][80]->setFree(false);
    matriz[1][90]->setFree(false);
    matriz[91][70]->setFree(false);
    matriz[30][57]->setFree(false);

    matriz[25][97]->setFree(false);
    matriz[60][23]->setFree(false);
    matriz[17][44]->setFree(false);
    matriz[19][77]->setFree(false);
    matriz[29][93]->setFree(false);
    matriz[24][29]->setFree(false);
    matriz[48][31]->setFree(false);
    matriz[98][66]->setFree(false);
    matriz[3][32]->setFree(false);
    matriz[39][9]->setFree(false);
    matriz[68][7]->setFree(false);
    matriz[36][0]->setFree(false);
    matriz[45][74]->setFree(false);
    matriz[25][92]->setFree(false);
    matriz[73][33]->setFree(false);
    matriz[67][32]->setFree(false);
    matriz[93][97]->setFree(false);
    matriz[17][67]->setFree(false);
    matriz[32][23]->setFree(false);
    matriz[54][89]->setFree(false);
    matriz[96][43]->setFree(false);
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::dibujar(){

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::white);
    QBrush redBrush(Qt::red);
    QBrush whiteBrush(Qt::black);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    for (int i = 0; i<100;i++){
        for (int j=0;j<100;j++){
            outlinePen.setWidth(1);
            if (matriz[i][j]->getActual()){
                outlinePen.setWidth(0);
                scene->addRect(6*i, 6*j, 6, 6, outlinePen, whiteBrush);
            }
            else if (matriz[i][j]->getfree()){
                scene->addRect(6*i, 6*j, 6, 6, outlinePen, blueBrush);
            } else {
                scene->addRect(6*i, 6*j, 6, 6, outlinePen, redBrush);
            }
        }
    }


}

void Interfaz::handleresul(){
    animacion();
}

void Interfaz::caminar(int iini, int jini, int ifn, int jfn){
    iact= iini;
    jact = jini;
    ifin = ifn;
    jfin = jfn;
    actual = matriz[iini][jini];
}

void Interfaz::animacion(){
    dibujar();
    actual->setActual(false);
    if (iact!=ifin){
        iact= iact+1;
    }
    if (jact!=jfin){
        jact = jact+1;
    }
    actual=matriz[iact][jact];
    actual->setActual(true);

    if (actual == matriz[iact][jact]){
        pro->quit();
    }
}

void Interfaz::on_obstaculos_clicked()
{
    definirObstaculos();
    dibujar();
}

void Interfaz::on_caminar_clicked()
{
    pro->start();
    caminar(7,3,90,78);

}
