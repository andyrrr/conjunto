#include "evaluacion.h"

//Constructor
Evaluacion::Evaluacion(int col, int fil, QLabel *ima):corx(250+col*80),cory(50+fil*60)
{
    imagen = ima;
    animation = new QPropertyAnimation(imagen,"geometry");
    libre = true;
    //conecta la señal del término de la animación con el SLOT de evalución
    connect(animation,SIGNAL(finished()),this,SLOT(llegaEvaluacion()));

}

//Empiezaz la anmación si la flecha ya está libre
void Evaluacion::evaluar(int xfin, int yfin){
    if (libre){
        libre= false;
        imagen->setPixmap(QPixmap(":/bala.png"));
        imagen->setScaledContents(true);
        animation->setDuration(1000);
        animation->setStartValue(QRect(corx,cory,50,50));
        animation->setEndValue(QRect(xfin,yfin,50,50));
        animation->start();
    }
}

//Se termina la animación, entonces se envía la señal para que los estudiantes que están en el nodo se evalúen
void Evaluacion::llegaEvaluacion(){
    libre=true;
    imagen->setPixmap(QPixmap(""));
    emit termino();
}
