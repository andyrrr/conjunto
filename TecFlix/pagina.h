#ifndef PAGINA_H
#define PAGINA_H
#include <vector>
#include <QObject>
#include <pelicula.h>
#include <workercreacionpeliculas.h>

class Pagina;

class Pagina
{
public:
    Pagina(int i, int tam);
    int id;
    vector<pelicula> getPeliculas();
    void setTamaño(int tam);


    void* operator new(size_t size);
    void operator delete(void*);

private:

    vector<pelicula> peliculas;
    void setPeliculas();
    static int numeroPeliculas;
    int tamaño;


public slots:
    void recibeData();

};

#endif // PAGINA_H
