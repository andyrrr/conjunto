#ifndef CONEXION_H
#define CONEXION_H
#include <string>
#include <empaquetar.h>

using namespace std;

class conexion
{
public:
    conexion();
    void enviarmensaje(empaquetar* paquete);
    string getmensaje();
private:
    char mensaje;
    string infoEnviar;
    string infoRecibida;
};

#endif // CONEXION_H
