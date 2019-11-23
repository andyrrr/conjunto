#include "estructura.h"
#include <iostream>
#include <detalles.h>

using namespace std;

Estructura::Estructura(QToolButton* b):boton(b)
{
    connect(boton,SIGNAL(clicked()),this, SLOT(recibir()));
}

void Estructura::setPelicula(pelicula p){
    peli = p;
}


void Estructura::recibir(){
    detalles *p = new detalles ();
    p->modificar(peli);
    p->show();
}
