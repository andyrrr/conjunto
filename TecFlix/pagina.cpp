#include "pagina.h"
#include <singletondataset.h>
#include <iostream>

using namespace std;

Pagina::Pagina(int i, int tam): id(i), tamaño(tam)
{
    setPeliculas();
}

void Pagina::setTamaño(int tam){
    tamaño = tam;
}

vector<pelicula> Pagina::getPeliculas(){
    return peliculas;
}
void Pagina::setPeliculas(){
    SingletonDataSet *s = SingletonDataSet::getInstance();
    for (int i = id*tamaño; i< id*tamaño+tamaño; i++){
        pelicula temp(s->getDataset()[i]);
        peliculas.push_back(temp);
        cout<<"Pelicula Creada "<<i<<" en página "<< id <<endl;
    }
}

void * Pagina::operator new(size_t size)
    {
        void * p = ::new pelicula();

        return p;
    }
void Pagina::operator delete(void * p)
{
    qDebug()<<"se libera pagina";
    free(p);
}

