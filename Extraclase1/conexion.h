#ifndef CONEXION_H
#define CONEXION_H
#include <string>

using namespace std;

class conexion
{
public:
    conexion();
    void enviarmensaje(string infoenviar);
    char getmensaje();
private:
    char mensaje;
};

#endif // CONEXION_H
