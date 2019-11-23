#include "empaquetar.h"

empaquetar::empaquetar(string accion, int numero, int posicion)
{
    Accion= accion;
    Numero = numero;
    Posicion = posicion;

}

json empaquetar::generarJson(){
    json empa;
    empa["ACCION"]= Accion;
    empa["NUMERO"]= Numero;
    empa["POSICION"] = Posicion;
    return empa;
}
