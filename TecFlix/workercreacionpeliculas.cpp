#include "workercreacionpeliculas.h"

workerCreacionPeliculas::workerCreacionPeliculas(QObject *parent):QThread (parent)
{

}

void workerCreacionPeliculas::run(){
    emit paginaCreada();
}

