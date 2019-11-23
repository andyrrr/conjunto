#include "worker.h"
#include <iostream>
#include <QDebug>
using namespace std;

worker::worker()
{

}

void worker::setData(int i, int t){
    id = i;
    tamaño = t;
}

void worker::run(){
    termina = false;
    pag = new Pagina(id,tamaño);
    termina=true;
    emit enviar();
}

bool worker::terminoHilo(){
    return termina;
}

