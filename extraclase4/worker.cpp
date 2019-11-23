#include "worker.h"

#include <iostream>
#include <interfaz.h>

using namespace std;

worker::worker(QObject *parent): QThread(parent)
{
    vacia=false;
}

void worker::cambio(bool cambio){
    vacia=cambio;
}

void worker::run(){
    int segundos=0;
    while (true){
        sleep(1);
        segundos++;
        if(!vacia){
            emit progreso();
        }
    }
}
