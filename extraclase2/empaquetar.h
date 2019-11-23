#ifndef EMPAQUETAR_H
#define EMPAQUETAR_H
#include <string>
#include <json.hpp>

using json = nlohmann::json;

using namespace std;


class empaquetar
{
public:
    empaquetar(string accion, int numero, int posicion);
    json generarJson();
private:
    string Accion;
    int Numero;
    int Posicion;
};

#endif // EMPAQUETAR_H
